#include "Login.h"

#include <memory>
#include <string>
#include <limits>   // Para std::numeric_limits (limpiar bueffer de entrada)
#include <cstdlib> // Para la función system("clear")

#define RESET   "\033[0m" 
#define RED     "\033[31m"
#define BOLD    "\033[1m" //Negrita

/**
 * @brief Método para gestionar usuarios en el sistema.
 * Se manejan 3 casos, entrar como Usuario, Admin, o salir. Dentro de cada uno se encuentran sus opciones.
 * @param basedatos La base de datos de usuarios.
 * @param interfaz La interfaz de usuario.
 * @param bdsensores La base de datos de los sensores.
 */

void Login::GestionarUsuarios(BDUsuarios& basedatos, Interfaz& interfaz, BDSensores& bdsensores) {
    
    //Bienvenida al programa.
    system("figlet Bienvenido");
    std::cout << "Pulsa ENTER para continuar...\n";
    std::cin.get();
    system("clear");


    // Verificar si la base de datos de usuarios está vacía
    if (basedatos.estaBaseDatosVacia()) {
        std::cout << RED << BOLD << "AVISO" << RESET << "\n";
        std::cout << "La base de datos de usuarios estaba vacía. Usted fue registrado como Admin, dni: 00000000A " << std::endl;
        std::cout << "Para iniciar sesion por primera vez porfavor use esos datos, en sus opciones podrá editar su perfil mas adelante.\n\n\n";
        
        basedatos.agregarUsuario("Administrador", "Admin", "00000000A");
        basedatos.escribirEnArchivo("users.txt");
    }

    bool salir = false;
    while (!salir) {
        interfaz.MostrarMenuPrincipal();
        try {
            int opcion;
            std::cin >> opcion;
            //Control de entrada de opciones del menu principal.
            if (std::cin.fail()) {
                throw std::runtime_error("[ERROR1] -> Debes introducir un número.");
            }

            switch (opcion) {

                //CASE 1: ENTRAR COMO USUARIO.
                case 1: {
                    std::string nombre;
                    std::cout << "Nombre de usuario: ";
                    std::cin >> nombre;
                    std::cin.ignore();

                    Usuario nuevoUsuario(nombre,"");
                    std::cout << "Introduzca el DNI (8 números seguidos de una letra): ";
                    nuevoUsuario.solicitarDni();
                    std::string dni = nuevoUsuario.getDni();

                    if (basedatos.dniExistente(dni,nombre)) {
                        system("clear");
                        std::cout << "El DNI ingresado ya ESTÁ en USO. Volviendo a la interfaz.\n\n.";
                        break; // Salir del case y volver al menú principal
                    }

                    bool salir_user = false;
                    while (!salir_user) {
                        try {
                            system("clear");
                            interfaz.MostrarOpcionesUsuario();
                            int opcionUsuario;
                            std::cin >> opcionUsuario;

                            if (std::cin.fail()) {
                                throw std::runtime_error("[ERROR2] -> Debes introducir un número.");
                            }
                            
                            switch (opcionUsuario) {
                                case 1:
                                    bdsensores.MostrarDispositivos();
                                    break;
                                case 2:
                                    system("clear");
                                    salir_user = true; // Salir del bucle y volver al menú principal
                                    basedatos.agregarUsuario("Usuario", nombre, dni);
                                    basedatos.escribirEnArchivo("users.txt");
                                    bdsensores.GuardarSensoresEnArchivo();
                                    break;
                                default:
                                    std::cout << "Opción no válida.\n";
                                    break;
                            }   //Cierre del switch (opciones del usuario)

                        //Capta error al introducir una letra y no un numero. Lanza fail linea 65
                        } catch (const std::runtime_error& e) {
                            std::cerr << "Error: " << e.what() << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }   //Cierre del while (salir del usuario)
                    break;
                } // Cierre del case 1

                //CASE 2: ENTRAR COMO ADMINISTRADOR.
                case 2: {
                    std::string nombre;
                    std::cout << "Nombre de administrador: ";
                    std::cin >> nombre;
                    std::cin.ignore();

                    Administrador nuevoAdmin(nombre,"");
                    std::cout << "Introduzca el DNI (8 números seguidos de una letra): ";
                    nuevoAdmin.solicitarDni();
                    std::string dni = nuevoAdmin.getDni();
                                
                    if (basedatos.dniExistente(dni,nombre)) {
                        system("clear");
                        std::cout << "El DNI ingresado ya ESTÁ en USO. Volviendo a la interfaz.\n\n";
                        break; // Salir del case y volver al menú principal
                    }

                    bool salir_admin = false;
                    while (!salir_admin) {
                        try {
                            interfaz.MostrarOpcionesAdministrador();
                            int opcionMostrar;
                            std::cin >> opcionMostrar;

                            if (std::cin.fail()) {
                                throw std::runtime_error("[ERROR3] -> Debes introducir un número.");
                            }

                            switch (opcionMostrar) {
                                case 1: {
                                    Alarma alarmaemergencia;
                                    alarmaemergencia.ActivarAlarma();
                                    alarmaemergencia.DesactivarAlarma();
                                    system("clear");
                                    break;
                                }
                                case 2: {
                                    basedatos.editarUsuario();
                                    break;
                                }
                                case 3: {
                                    basedatos.eliminarUsuario();
                                    break;
                                }
                                case 4: {
                                    basedatos.mostrarUsuarios();
                                    std::cout << std::endl;
                                    break;
                                }
                                case 5: {
                                    salir_admin = true; // Salir del bucle y volver al menú principal
                                    basedatos.agregarUsuario("Administrador", nombre, dni);
                                    basedatos.escribirEnArchivo("users.txt");
                                    bdsensores.GuardarSensoresEnArchivo();
                                    system("clear");
                                    break;
                                }
                                default: {
                                    std::cout << "Opción no válida." << std::endl;
                                    break;
                                }
                            } // Cierre switch (opciones del administrador)

                        // Captura el error al introducir una letra en lugar de un número. Lanza el fail linea 119.
                        } catch (const std::runtime_error& e) {
                            std::cerr << "Error: " << e.what() << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }   //Cierre del while (salir del administrador)
                    break; 
                }   // Cierre del case 2

                //CASE 3: SALIR DEL PROGRAMA.
                case 3: {
                    salir = true;
                    system("clear");
                    system("figlet Vuelva Pronto");
                    //std::cout << "\nSaliendo del programa, vuelva pronto." << std::endl;
                    break;
                }
                default: {
                    std::cout << "Opción no válida." << std::endl;
                    break;
                }
            }   //Cierre del switch (opciones del menu principal)

        //Capta error al introducir una letra y no un numero. Lanza el fail linea 34.
        } catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }   //Cierre del while (salir del programa)
    
}   //Cierre del método GestionarUsuarios
