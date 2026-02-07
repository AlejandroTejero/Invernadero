#include <iostream>
#include "SHumedad.h"

#include <cstdlib> // Necesario para la función rand
#include <ctime>   // Necesario para la función time

SHumedad::SHumedad() {}

int SHumedad::CalcularDatos() {
    std::srand(static_cast<unsigned int>(std::time(0))); //Inicializacion de aleatoriedad.    
    humedadAleatoria = std::rand() % 101; // Nº aleatorio  [0,100]
    return humedadAleatoria;
    //return humedadAleatoria = rand() % 101;
}

void SHumedad::MostrarDatos() const {
    std::cout << "Humedad en el ambiente: " << humedadAleatoria << "% - ";
    if (humedadAleatoria >= 0 && humedadAleatoria <= 25) {
        std::cout << "Humedad baja" << std::endl;
    } else if (humedadAleatoria > 25 && humedadAleatoria <= 50) {
        std::cout << "Humedad media" << std::endl;
    } else if (humedadAleatoria > 50 && humedadAleatoria <= 75) {
        std::cout << "Humedad alta" << std::endl;
    } else {
        std::cout << "Humedad muy alta" << std::endl;
    }
}

std::string SHumedad::getNombre() const {
  return "Sensor de Humedad";
}
