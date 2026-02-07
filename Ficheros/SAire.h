#ifndef SAIRE_H
#define SAIRE_H
#include "SensorCamara.h"

/**
 * @file SAire.h
 * @brief Clase que representa un sensor de calidad de aire.
 * 
 * Esta clase hereda de SensorCamara y proporciona funcionalidades específicas para medir la calidad del aire.
 */

class SAire : public SensorCamara {
public:
    SAire();

    int CalcularDatos() override;
    void MostrarDatos() const override;
    std::string getNombre() const override;


private:
    int calidadaleatoria;
};

#endif  //SAIRE_H