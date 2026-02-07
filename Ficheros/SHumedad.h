#ifndef SHUMEDAD_H
#define SHUMEDAD_H
#include "SensorCamara.h"

/**
 * @file SHumedad.h
 * @brief Clase que representa un sensor de humedad.
 * 
 * Esta clase hereda de SensorCamara y proporciona funcionalidades específicas para medir la humedad.
 */

class SHumedad : public SensorCamara {
public:
    SHumedad();

    int CalcularDatos() override;
    void MostrarDatos() const override;
    std::string getNombre() const override;

private:
    int humedadAleatoria;
};

#endif // SHUMEDAD_H