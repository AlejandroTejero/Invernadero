#include <iostream>
#include "CTermica.h"
#include <ctime> // Para obtener la fecha y hora actual

CTermica::CTermica() {}

void CTermica::MostrarDatos() const {
    std::cout << "Datos de la matriz de la cámara térmica:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl; // Salto de línea después de cada fila
    }
}

int CTermica::CalcularDatos() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Inicializar la semilla de la aleatoriedad
    // Generar números aleatorios para llenar la matriz
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matriz[i][j] = std::rand() % 101; // Números aleatorios entre 0 y 100
        }
    }
    // Devolver algún valor, en este caso, la suma de todos los elementos de la matriz
    int suma = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            suma += matriz[i][j];
        }
    }
    return suma;
}

std::string CTermica::getNombre() const {
  return "Camara Termica";
}

