#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <stdexcept>
#include <iostream>

/**
 * @file Usuario.h
 * @brief Clase que representa un usuario del sistema.
 * 
 * Proporciona funcionalidades para usuario y administrador.
 */


class Usuario {
public:
    Usuario(const std::string& nombre, const std::string& dni);
    virtual ~Usuario() {}

    std::string getNombre() const;
    std::string getDni() const;
    void setNombre(const std::string& newNombre);
    void setDni(const std::string& newDni);
    
    /**
    * @brief Método para solicitar el DNI del usuario.
    * Este método puede ser utilizado para solicitar el DNI al usuario desde la entrada estándar.
    */
    void solicitarDni();
    //bool operator<(const Usuario& otro) const;    (Probar para el orden de muestra)

private:
    std::string nombre; ///< Nombre del usuario.
    std::string dni;    ///< DNI del usuario.
};

#endif // USUARIO_H
