#ifndef CRGB_H
#define CRGB_H
#include "SensorCamara.h"

/**
 * @file CRgb.h
 * @brief Clase que representa un sensor de color RGB.
 * 
 * Esta clase hereda de SensorCamara y proporciona funcionalidades específicas para medir el color en formato RGB.
 */

class CRgb : public SensorCamara {
public:
    CRgb();

    int CalcularDatos() override;
    void MostrarDatos() const override;
    std::string getNombre() const override;

private:
    /*int componenteRed;
    int componenteGreen;
    int componenteBlue;*/
    int matriz[3][3];

};


#endif // CRB_H