#include <iostream>
#include "STemp.h"

#include <cstdlib> // Necesario para la función rand
#include <ctime>   // Necesario para la función time

STemp::STemp() {}

int STemp::CalcularDatos() {
    std::srand(static_cast<unsigned int>(std::time(0))); //Inicializa la aletoreidad con rand.
    tempaleatoria = std::rand() % 101; // Nº aleatorio  [0,100]
    return tempaleatoria;
}

void STemp::MostrarDatos() const {
    std::cout << "Temperatura actual: " << tempaleatoria << "º celsius - ";
    if (tempaleatoria >= 0 && tempaleatoria <= 25) {
      std::cout << "Temperatura baja" << std::endl;
    } else if (tempaleatoria > 25 && tempaleatoria <= 50) {
      std::cout << "Temperatura media" << std::endl;
    } else if (tempaleatoria > 50 && tempaleatoria <= 75) {
      std::cout << "Temperatura alta" << std::endl;
    } else {
      std::cout << "Temperatura muy alta" << std::endl;
  }
}
std::string STemp::getNombre() const {
  return "Sensor de Temperatura";
}

//fgkcdghhg