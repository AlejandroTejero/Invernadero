#ifndef BDUSUARIOS_H
#define BDUSUARIOS_H

#include <set>
#include "Usuario.h"
#include "Administrador.h"
#include "Exception.h"

/**
 * @file BDUsuarios.h
 * @brief Clase que representa una base de datos de usuarios.
 * 
 * Esta clase se encarga de gestionar y manipular la colección de usuarios del sistema, eliminado usuarios
 * duplicados y evitando que alguien acceda con un dni existente.
 */

//No guarda con mismo dni, pero te deja actuar.
class ComparadorUsuarios {
public:
    bool operator()(const Usuario* u1, const Usuario* u2) const {
        return u1->getDni() < u2->getDni();
    }
};

class BDUsuarios {
public:
    
    BDUsuarios();
    ~BDUsuarios();
    /**
     * @brief Método para cargar usuarios desde un archivo.
     * @param nombreArchivo El nombre del archivo desde el cual se cargan los usuarios.
     */
    void cargarArchivo(const std::string& nombreArchivo); 
    bool estaBaseDatosVacia() const;
    void agregarUsuario(const std::string& tipoUsuario, const std::string& nombre, const std::string& dni);
    void mostrarUsuarios() const;
    bool dniExistente(const std::string& dni, const std::string& nombre) const; // Nuevo método
    void editarUsuario();
    void eliminarUsuario();
    /**
    * @brief Método para escribir la base de datos en un archivo.
    * @param nombreArchivo El nombre del archivo en el cual se escribe la base de datos.
    */
    void escribirEnArchivo(const std::string& nombreArchivo) const;
    
private:
    std::set<Usuario*, ComparadorUsuarios> usuarios; ///< Conjunto de usuarios almacenados en la base de datos, añade el primero que introduzca el dni (en caso de repetición).
};

#endif // BDUSUARIOS_H
