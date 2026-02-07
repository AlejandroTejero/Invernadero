#include "BDSensores.h"
#include <iostream>
#include <memory>
#include <fstream> // Para manejo de archivos


BDSensores::BDSensores() {}

BDSensores::~BDSensores() {
    for (auto sensor : sensorcamara_) {
        delete sensor;
}
}

void BDSensores::AgregarSensorCamara(SensorCamara* sensorcamara) {
    sensorcamara_.insert(sensorcamara);
    }

void BDSensores::MostrarDispositivos() {
    std::cout << "Seleccione el sensor para ver su datos o 'salir' para finalizar:\n" << std::endl;

    size_t indice = 1;
    for (auto& sensor : sensorcamara_) {
        std::cout << indice << ". " << sensor->getNombre() << std::endl;
        ++indice;
    }

    std::string opcion;
    std::cout << "Seleccione el dispositivo:  ";
    std::cin >> opcion;

    // Mostrar datos del sensor seleccionado
    while (opcion != "salir") {
        try {
            size_t indice = std::stoul(opcion);
            if (indice >= 1 && indice <= sensorcamara_.size()) {
                auto it = sensorcamara_.begin();
                std::advance(it, indice - 1);
                (*it)->CalcularDatos();
                (*it)->MostrarDatos();
                std::cout << "\n";
            } else {
                std::cout << "[ERROR]: Opción fuera de rango" << std::endl;
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: Opción inválida. Debe ingresar un número." << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: Opción fuera de rango." << std::endl;
        }

        std::cout << "Seleccione el dispositivo:  ";
        std::cin.ignore();
        std::cin >> opcion;
    }
}

void BDSensores::ConfigurarSensores() {
    sensorcamara_.insert(new SAire);
    sensorcamara_.insert(new STemp);
    sensorcamara_.insert(new SHumedad);
    sensorcamara_.insert(new SIluminacion);
    sensorcamara_.insert(new CRgb);
    sensorcamara_.insert(new CTermica);
}

//Pinta legible
void BDSensores::GuardarSensoresEnArchivo() {
    std::ofstream archivo("sensors.dat", std::ios::binary | std::ios::trunc);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return;
    }

    for (const auto& sensor : sensorcamara_) {
        // Obtener el nombre del sensor y escribirlo en el archivo
        std::string nombre = sensor->getNombre();
        archivo.write(nombre.c_str(), nombre.size());
        //No legible pero con reintrpret_cast
        //archivo.write(reinterpret_cast<char*>(sensor), sizeof(SensorCamara));
        archivo.put('\0'); // Carácter nulo para indicar el final del nombre

        // Calcular los datos del sensor y escribirlos en el archivo
        int datos = sensor->CalcularDatos();
        archivo.write(reinterpret_cast<const char*>(&datos), sizeof(int));
    }
    archivo.close();
}
