#include "BDUsuarios.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <cstdlib> // Para la función system(""clear")

BDUsuarios::BDUsuarios() {
    cargarArchivo("users.txt");
}

BDUsuarios::~BDUsuarios() {
    for (auto usuario : usuarios) {
        delete usuario; // Liberar la memoria de los usuarios
    }
}

bool BDUsuarios::estaBaseDatosVacia() const {
    return usuarios.empty();
}

//Relanzamiento de excepciones con bad alloc, y relanza con el throw a excepction
void BDUsuarios::cargarArchivo(const std::string& nombreArchivo) {
    try {
        std::ifstream archivo(nombreArchivo);
        //Excepcion mandada en el chat sino se abre el archivo.
        if (!archivo.is_open()) {
            throw std::runtime_error("No se pudo abrir el archivo " + nombreArchivo + ", no se cargaran los datos.\n");
        }
        //Leo linea por linea y guardo en el array
        std::string linea;
        while (std::getline(archivo, linea)) {
            // Analizar la línea para obtener el tipo de usuario y los datos
            if (!linea.empty()) { //sino esta vacia
                std::istringstream ss(linea);
                std::string tipoUsuario, nombre, dni;
                ss >> tipoUsuario >> nombre >> dni;

                if (tipoUsuario == "Usuario:") {
                    try {
                        usuarios.insert(new Usuario(nombre, dni));
                    } catch (const std::bad_alloc& e) {
                        std::cerr << "[ERROR]-> bad_alloc al crear un Usuario";
                        throw; // Esto relanza la excepción al siguiente bloque de código que pueda manejarla
                    }
                } else if (tipoUsuario == "Administrador:") {
                    try {
                        usuarios.insert(new Administrador(nombre, dni));
                    } catch (const std::bad_alloc& e) {
                        std::cerr << "[ERROR]-> bad_alloc al crear un Administrador";
                        throw; // Esto relanza la excepción al siguiente bloque de código que pueda manejarla
                    }
                }
            }
        }
        archivo.close();
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] -> " << e.what() << std::endl;
    }
}

void BDUsuarios::agregarUsuario(const std::string& tipoUsuario, const std::string& nombre, const std::string& dni) {
    if (tipoUsuario == "Usuario") {
        usuarios.insert(new Usuario(nombre, dni));
    } else if (tipoUsuario == "Administrador") {
        usuarios.insert(new Administrador(nombre, dni));
    }
}

bool BDUsuarios::dniExistente(const std::string& dni, const std::string& nombre) const {
    for (auto usuario : usuarios) {
        if (usuario->getDni() == dni && usuario->getNombre() != nombre) {
            return true; // El DNI ya existe para un nombre de usuario diferente
        }
    }
    return false;
}


void BDUsuarios::mostrarUsuarios() const {
    system("clear");
    if (usuarios.empty()) {
        // Lanzar una excepción si la base de datos está vacía. Clase Exception.h
        throw BaseDeDatosVaciaException("La base de datos de usuarios está vacía, primero debera registrar usuario o administrador.\n");
        //std::cout << "";
    }
    std::cout << "Administradores y usuarios registrados:\n" << std::endl;
    int contador = 1;
    for (auto usuario : usuarios) {
        if (dynamic_cast<Administrador*>(usuario)) {
            std::cout << contador << ". Administrador: ";
        } else {
            std::cout << contador << ". Usuario: ";
        }
        std::cout << usuario->getNombre() << " (" << usuario->getDni() << ")" << std::endl;
        contador++;
    }
}

void BDUsuarios::editarUsuario() {
    try {
        mostrarUsuarios();
        std::string opcionStr;
        std::cout << "Ingrese el número del usuario que desea editar: ";
        std::cin >> opcionStr;
        
        // Introduzco la entrada como string, y la intento convertir a int, para ver si da error y evitar colapsos en el programa.
        int opcion;
        try {
            opcion = std::stoi(opcionStr); // stoi intenta convertir a número el string
        } catch (const std::invalid_argument&) { // si no se puede convertir a número
            throw std::runtime_error("Entrada inválida: se esperaba un número.");
        }
        if (opcion <= 0 || opcion > static_cast<int>(usuarios.size())) { // si el número no está en el rango
            throw std::out_of_range("Número de usuario inválido.");
        }
        
        auto it = usuarios.begin();
        std::advance(it, opcion - 1);
        Usuario* usuarioAEditar = *it;
        std::string nuevoNombre, nuevoDni;
        std::cout << "Ingrese el nuevo nombre: ";
        std::cin >> nuevoNombre;
        std::cin.ignore();

        bool dniValido = false;
        while (!dniValido) {
            std::cout << "Ingrese el nuevo dni: ";
            usuarioAEditar->solicitarDni();
            nuevoDni = usuarioAEditar->getDni();

            // Verificar si el nuevo DNI ya está en uso
            dniValido = true;
            for (auto usuario : usuarios) {
                if (usuario->getDni() == nuevoDni && usuario != usuarioAEditar) {
                    dniValido = false;
                    std::cerr << "El DNI ingresado ya está en uso. Intente nuevamente." << std::endl;
                    break;
                }
            }
        }
        // Actualizar los datos del usuario
        usuarioAEditar->setNombre(nuevoNombre);
        usuarioAEditar->setDni(nuevoDni);
        std::cout << "Usuario editado correctamente." << std::endl;
    } catch (const BaseDeDatosVaciaException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void BDUsuarios::eliminarUsuario() {
    try {
        mostrarUsuarios();
        std::string opcionStr;
        std::cout << "Ingrese el número del usuario que desea eliminar: ";
        std::cin >> opcionStr;

        int opcion;
        try {
            opcion = std::stoi(opcionStr); //stoi intenta convertir a numero el string
        } catch (const std::invalid_argument&) { //si no se puede convertir a numero
            throw std::runtime_error("Entrada inválida: se esperaba un número.");
        }
        if (opcion <= 0 || opcion > static_cast<int>(usuarios.size())) { //si el numero no esta en el rango
            throw std::out_of_range("Número de usuario fuera de rango.");
        }

        auto it = usuarios.begin();
        std::advance(it, opcion - 1);
        delete *it;
        usuarios.erase(it);
        std::cout << "Usuario eliminado correctamente." << std::endl;
    } catch (const BaseDeDatosVaciaException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: Entrada inválida. Se esperaba un número." << std::endl;
    }
}

void BDUsuarios::escribirEnArchivo(const std::string& nombreArchivo) const {
    std::ofstream archivo(nombreArchivo, std::ios::trunc); // ios trunc : sobrescritura, creea o sobreescribe
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return;
    }
    // Escribir usuarios primero
    for (auto usuario : usuarios) {
        if (!dynamic_cast<Administrador*>(usuario)) {
            archivo << "Usuario: ";
            archivo << usuario->getNombre() << " " << usuario->getDni() << std::endl;
        }
    }
    // Escribir administradores después
    for (auto usuario : usuarios) {
        if (dynamic_cast<Administrador*>(usuario)) {
            archivo << "Administrador: ";
            archivo << usuario->getNombre() << " " << usuario->getDni() << std::endl;
        }
    }
    archivo.close();
}
