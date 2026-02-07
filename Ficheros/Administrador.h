#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "Usuario.h"

/**
 * @file Administrador.h
 * @brief Clase que representa un administrador del sistema.
 * 
 * Esta clase hereda de Usuario y proporciona funcionalidades específicas para los administradores (heredadas).
 */

class Administrador : public Usuario {
public:
    Administrador(const std::string& nombre, const std::string& dni);
};

#endif // ADMINISTRADOR_H
