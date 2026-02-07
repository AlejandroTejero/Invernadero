// BDSensores.h
#ifndef BDSENSORES_H
#define BDSENSORES_H

#include "SensorCamara.h"
#include "SAire.h"
#include "STemp.h"
#include "SHumedad.h"
#include "SIluminacion.h"
#include "CRgb.h"
#include "CTermica.h"

#include <set>
#include <memory>

/**
 * @file BDSensores.h
 * @brief Clase que representa una base de datos de sensores.
 * 
 * Esta clase se encarga de configurar y agregar al sistema los diferentes sensores disponibles.
 */

class BDSensores {
public:
    
    BDSensores();
    ~BDSensores();
    
    void AgregarSensorCamara(SensorCamara* sensorcamara);
    void MostrarDispositivos();

    /**
    * @brief Método para configurar los sensores en la interfaz.
    * @param interfaz La interfaz a través de la cual se configuran los sensores.
    */
    void ConfigurarSensores();
    void GuardarSensoresEnArchivo();

private:
    std::set<SensorCamara*> sensorcamara_; 
};

#endif // BDSENSORES_H
