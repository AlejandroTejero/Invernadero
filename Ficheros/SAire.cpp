#include <iostream>
#include "SAire.h"

#include <cstdlib> // Necesario para la función rand
#include <ctime>   // Necesario para la función time

SAire::SAire () {}

int SAire::CalcularDatos() {

    std::srand(static_cast<unsigned int>(std::time(0))); //Inicializa la aletoreidad con rand
    calidadaleatoria = std::rand() % 101; // Nº aleatorio  [0,100]
    return calidadaleatoria;
}

void SAire::MostrarDatos() const {
    std::cout << "Calidad del aire: " <<calidadaleatoria << "% - ";
    if (calidadaleatoria >= 0 && calidadaleatoria <= 25) {
        std::cout << "Iluminación baja" << std::endl;
    } else if (calidadaleatoria > 25 && calidadaleatoria <= 50) {
        std::cout << "Iluminación media" << std::endl;
    } else if (calidadaleatoria > 50 && calidadaleatoria <= 75) {
        std::cout << "Iluminación alta" << std::endl;
    } else {
        std::cout << "Iluminación muy alta" << std::endl;
    }
}

std::string SAire::getNombre() const {
  return "Sensor de Aire";
}