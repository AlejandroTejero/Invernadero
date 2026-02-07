#include <iostream>
#include "Alarma.h"
#include <limits>

Alarma::Alarma () {}

void Alarma::BloqueoPuertas() {
    std::cout << "Puertas bloqueadas" << std::endl;   
}

void Alarma::ActivarAlarma() {
    std::cout << "ALARMA ACTIVADA\n" << std::endl;
    BloqueoPuertas();
}

void Alarma::DesactivarAlarma() {
    bool alarma_activada = true;
    while (alarma_activada) {
        try {
            std::cout << "Para desactivar la alarma, introduzca el número 1: ";
            std::string input;
            std::cin >> input;

            // Verificar si la entrada es un número
            if (input.find_first_not_of("0123456789") != std::string::npos) {
                throw std::invalid_argument("Entrada no válida. Debe ser un número.");
            }

            int desactivar = std::stoi(input);

            if (desactivar == 1) {
                alarma_activada = false; // Salir del bucle de desactivación de alarma
            } else {
                std::cout << "Número incorrecto. La alarma sigue activada." << std::endl;
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << ". Intente de nuevo." << std::endl;
            // Limpiar el buffer de entrada para evitar bucles infinitos
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } catch (const std::out_of_range& e) {
            std::cout << "Error: el número está fuera de rango." << std::endl;
            // Limpiar el buffer de entrada para evitar bucles infinitos
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } catch (const std::exception& e) {
            std::cout << "Error inesperado: " << e.what() << ". Intente de nuevo." << std::endl;
            // Limpiar el buffer de entrada para evitar bucles infinitos
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
