#include <iostream>
#include "Interfaz.h"

#define RESET   "\033[0m" 
#define WHITE   "\033[37m"
#define BOLD    "\033[1m" //Negrita

Interfaz::Interfaz () {}

void Interfaz::MostrarMenuPrincipal() {    
    std::cout << "\n";
    std::cout << WHITE << BOLD << "----BIENVENIDO AL MENU PRINCIPAL----" << RESET << "\n\n";
    std::cout << "1. Acceder como Usuario" << std::endl;
    std::cout << "2. Acceder como Administrador" << std::endl;
    std::cout << "3. Salir\n" << std::endl;
    std::cout << "Introduzca a qué quiere acceder (1, 2 o 3): ";
}

void Interfaz::MostrarOpcionesUsuario() {
    std::cout << WHITE << BOLD << "----OPCIONES DE USUARIO----" << RESET << "\n\n";
    std::cout << "Seleccione una opción:\n\n";
    std::cout << "1. Ver Sensores\n";
    std::cout << "2. Abandonar Sesión\n\n";
    std::cout << "Introduzca a qué desea hacer (1 o 2): ";

}

void Interfaz::MostrarOpcionesAdministrador() {
    std::cout << WHITE << BOLD << "----OPCIONES DE ADMINISTRADOR----" << RESET << "\n\n";
    std::cout << "Seleccione qué desea hacer:\n";
    std::cout << "1. Activar alarma emergencia\n";
    std::cout << "2. Editar Usuario\n";
    std::cout << "3. Eliminar Usuario\n";
    std::cout << "4. Mostrar Usuarios\n";
    std::cout << "5. Abandonar sesion\n" << std::endl;
    std::cout << "Introduzca a qué desea hacer (1, 2, 3, 4 o 5): ";
}
