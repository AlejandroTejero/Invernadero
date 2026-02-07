#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "SensorCamara.h"
#include <vector>
#include <memory> // para std::unique_ptr


/**
 * @file Interfaz.h
 * @brief Clase que representa la interfaz de usuario del sistema.
 * 
 * Esta clase se encarga de interactuar con el usuario y gestionar los dispositivos de cámara.
 */

class Interfaz {
public:
    Interfaz();

    /**
     * @brief Métodos que muestran las opciones en el terminal (std::cout).
     */
    void MostrarMenuPrincipal();
    void MostrarOpcionesUsuario();
    void MostrarOpcionesAdministrador();

    //~Interfaz(); // Destructor para liberar memoria de los dispositivos
};

#endif  //INTERFAZ_H