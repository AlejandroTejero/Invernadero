# Invernadero

# Invernadero (C++) — Simulación de sensores y gestión de usuarios

Proyecto en C++ orientado a programación modular y POO para simular un entorno de **invernadero** con distintos **sensores** y un flujo de **login/gestión de usuarios**. Incluye persistencia básica de datos y documentación automática.

## Features
- Login y gestión de usuarios (Usuario / Administrador) a partir de un fichero `users.txt`.
- Sensores simulados (temperatura, humedad, aire, iluminación, RGB, térmica, cámara).
- Menú interactivo por terminal para consultar datos por sensor.
- Guardado de lecturas en fichero binario `sensors.dat`.
- Documentación con **Doxygen** y depuración con **GDB**.

## Estructura del proyecto
- `main.cpp`: punto de entrada.
- `Login.*`: flujo principal de autenticación/gestión.
- `BDUsuarios.*`: carga y gestión de usuarios desde `users.txt`.
- `BDSensores.*`: configuración de sensores y persistencia en `sensors.dat`.
- `S*.*/C*.*/SensorCamara.*`: implementación de sensores.
- `Doxyfile`: configuración para generar documentación.
- `Makefile`: compilación rápida.

## Requisitos
- Linux / macOS (recomendado) o WSL en Windows
- `g++` y `make`
- (Opcional) `figlet` para la interfaz visual si tu terminal lo usa:
  - Debian/Ubuntu: `sudo apt-get install figlet`

## Compilación y ejecución
Desde la carpeta del proyecto:

```bash
make
./main
``
