#include "Usuario.h"
#include <iostream>
Usuario::Usuario(const std::string& nombre, const std::string& dni)
    : nombre(nombre), dni(dni) {}

std::string Usuario::getNombre() const {
    return nombre;
}

std::string Usuario::getDni() const {
    return dni;
}

void Usuario::setNombre(const std::string& newNombre) {
    nombre = newNombre;
}

void Usuario::setDni(const std::string& newDni) {
    dni = newDni;
}

//Funcion que dectecta si el dni es valido o no, valido (8num+1letra)
void Usuario::solicitarDni() {
    bool dni_valido = false;
    while (!dni_valido) {
        //std::cout << "Introduzca el DNI (8 números seguidos de una letra): ";
        //std::string dni;
        //std::cin >> dni; 
        std::getline(std::cin, dni); //Almaceno como dni la entrada cin.
        if (dni.size() == 9) {
            bool numeros_correctos = true;
            for (size_t i = 0; i < dni.size() - 1; ++i) {
                if (!std::isdigit(dni[i])) {
                    numeros_correctos = false;
                    break;
                }
            }
            bool letra_correcta = std::isalpha(dni[8]);
            //Libreria std que devulve True si es una letra, false si no lo es.
            if (numeros_correctos && letra_correcta) {
                dni_valido = true;
            }
        }

        if (!dni_valido) {
            //std::cout << "" << std::endl;
            std::cout << "Formato incorrecto (8 números + 1 letra): ";
        }
    }
}

/*bool Usuario::operator<(const Usuario& otro) const {
    if (dni != otro.dni) {
        return dni < otro.dni;
    }
    return nombre < otro.nombre;
}
bool Usuario::operator<(const Usuario& otro) const {
    if (nombre == otro.nombre) {
        // Si los nombres son iguales, ordena por DNI de mayor a menor
        return dni > otro.dni;
    } else {
        // Si los nombres son diferentes, ordena por nombre de menor a mayor
        return nombre < otro.nombre;
    }
}
//Distintos operadores de prueba
bool Usuario::operator<(const Usuario& otro) const {
    return dni < otro.dni;
}
bool Usuario::operator<(const Usuario& otro) const {
    return otro.nombre > nombre;
}*/