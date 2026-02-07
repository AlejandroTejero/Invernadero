#ifndef CTERMICA_H
#define CTERMICA_H
#include "SensorCamara.h"

/**
 * @file CTermica.h
 * @brief Clase que representa un sensor térmico.
 * 
 * Esta clase hereda de SensorCamara y proporciona funcionalidades específicas para medir la temperatura.
 */

class CTermica : public SensorCamara {
public:
    CTermica();

    int CalcularDatos() override;
    void MostrarDatos() const override;
    std::string getNombre() const override;

private:
   int matriz[3][3];
};

#endif  //SAIRE_H