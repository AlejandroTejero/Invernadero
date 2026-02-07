#include <iostream>
#include "CRgb.h"

#include <cstdlib> // Necesario para la función rand
#include <ctime>   // Necesario para la función time


CRgb::CRgb() {}

void CRgb::MostrarDatos() const {
    std::cout << "Datos de la matriz de la cámara RGB:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl; // Salto de línea después de cada fila
    }
}

int CRgb::CalcularDatos() {
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

std::string CRgb::getNombre() const {
  return "Camara Rgb";
}

/*
int CRgb::CalcularDatos() {
    componenteRed = std::rand() % 101; // Nº aleatorio [0,100]
    componenteGreen = std::rand() % (101 - componenteRed);
    componenteBlue = 100 - componenteRed - componenteGreen;
    return componenteRed + componenteGreen + componenteBlue; //Resultado = 100
}

void CRgb::MostrarDatos() const {
    std::cout << "Red::" << componenteRed << "%" << std::endl;
    std::cout << "Green:" << componenteGreen << "%" << std::endl;
    std::cout << "Blue:" << componenteBlue << "%" << std::endl;
}
*/