#ifndef STEMP_H
#define STEMP_H
#include "SensorCamara.h"


/**
 * @file STemp.h
 * @brief Clase que representa un sensor de temperatura.
 * 
 * Esta clase hereda de SensorCamara y proporciona funcionalidades específicas para medir la temperatura.
 */

class STemp : public SensorCamara {
public:
    STemp();

    int CalcularDatos() override;
    void MostrarDatos() const override;
    std::string getNombre() const override;

private:
    int tempaleatoria;
};

#endif // STEMP_H