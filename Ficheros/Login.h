// Login.h
#ifndef LOGIN_H
#define LOGIN_H

#include "BDUsuarios.h" //Se encarga de llamar Usuario.h y Admin.h
#include "BDSensores.h"
#include "Interfaz.h" //Llama a todos los sensores.h
#include "Alarma.h"

/**
 * @file Login.h
 * @brief Clase que maneja el proceso de login y la gestión de usuarios en el sistema.
 */

class Login {
public:
    void GestionarUsuarios(BDUsuarios& basedatos, Interfaz& interfaz, BDSensores& bdsensores);
};

#endif // LOGIN_H
