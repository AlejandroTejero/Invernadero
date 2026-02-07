#include <iostream>
#include "SIluminacion.h"

#include <cstdlib> // Necesario para la función rand
#include <ctime>   // Necesario para la función time

SIluminacion::SIluminacion () {}

int SIluminacion::CalcularDatos() {
    
    std::srand(static_cast<unsigned int>(std::time(0))); //Inicializa la aletoreidad con rand
    iluminacionAleatoria = std::rand() % 101; // Nº aleatorio  [0,100]
    return iluminacionAleatoria;
}

void SIluminacion::MostrarDatos() const {
    std::cout << "Iluminación: " << iluminacionAleatoria << "% - ";
    if (iluminacionAleatoria >= 0 && iluminacionAleatoria <= 25) {
        std::cout << "Iluminación baja" << std::endl;
    } else if (iluminacionAleatoria > 25 && iluminacionAleatoria <= 50) {
        std::cout << "Iluminación media" << std::endl;
    } else if (iluminacionAleatoria > 50 && iluminacionAleatoria <= 75) {
        std::cout << "Iluminación alta" << std::endl;
    } else {
        std::cout << "Iluminación muy alta" << std::endl;
    }
}

std::string SIluminacion::getNombre() const {
  return "Sensor de Iluminacion";
}

