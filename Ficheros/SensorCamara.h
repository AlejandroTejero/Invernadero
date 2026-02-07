#ifndef SENSORCAMARA_H
#define SENSORCAMARA_H
#include <string>
/**
 * @file SensorCamara.h
 * @brief Clase que representa un sensorCamara padre genérico.
 * 
 * Esta clase proporciona una interfaz para los diferentes tipos de sensores de cámara.
 */

class SensorCamara {
public:    
    //Tipos de SensorCamara
    enum Types {
        STemp,          ///< Sensor de temperatura.
        SHumedad,       ///< Sensor de humedad.
        SIluminacion,   ///< Sensor de iluminación.
        SAire,          ///< Sensor de aire.
        CRgb,           ///< Sensor de color RGB.
        CTermica        ///< Sensor térmico.
    };
    

    //Constructor (nombre de la clase)
    SensorCamara(); 
    
    virtual int CalcularDatos() = 0;
    virtual void MostrarDatos() const = 0;  
    virtual std::string getNombre() const = 0;
    
    virtual ~SensorCamara(); //Destructor virtual de la clase, para todos los sensores

};

#endif // SENSOR_H
