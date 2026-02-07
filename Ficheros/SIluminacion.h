#ifndef SILUMINACION_H
#define SILUMINACION_H
#include "SensorCamara.h"

/**
 * @file SIluminacion.h
 * @brief Clase que representa un sensor de iluminación.
 * 
 * Esta clase hereda de SensorCamara y proporciona funcionalidades específicas para medir la iluminación.
 */

class SIluminacion : public SensorCamara {
public:
    SIluminacion();

    int CalcularDatos() override;
    void MostrarDatos() const override;
    std::string getNombre() const override;


private:
    int iluminacionAleatoria;
};

#endif // SILUMACION_H