#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>

/**
 * @file BaseDeDatosVaciaException.h
 * @brief Clase que representa una excepción para una base de datos vacía.
 * 
 * Esta clase hereda de std::runtime_error y se utiliza para indicar que se intentó realizar una operación en una base de datos vacía.
 */

class BaseDeDatosVaciaException : public std::runtime_error {
public:
    /**
    * @brief Constructor que toma un mensaje de error.
    * @param mensaje El mensaje de error asociado a la excepción.
    */
    explicit BaseDeDatosVaciaException(const std::string& mensaje) : std::runtime_error(mensaje) {}
};

#endif // EXCEPTION_H