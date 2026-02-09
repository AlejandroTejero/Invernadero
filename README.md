# Invernadero (C++)

**Invernadero** es un proyecto en **C++** orientado a **programación orientada a objetos (POO)** que simula un sistema de invernadero con **sensores** y una interfaz por terminal.  
Incluye un sistema básico de **usuarios** (login) y **persistencia en ficheros** para guardar información entre ejecuciones.

---

## Características
- Simulación de un invernadero con varios **sensores** (temperatura, humedad, aire/iluminación, etc.).
- Interfaz por **terminal** para consultar lecturas y navegar por el sistema.
- Sistema de **usuarios** con autenticación simple.
- **Persistencia**:
  - usuarios en fichero de texto (`users.txt`)
  - sensores/lecturas en fichero binario (`sensors.dat`)
- Proyecto modular con separación por clases y ficheros `.h/.cpp`.
- Incluye configuración para documentación con **Doxygen** y compilación mediante **Makefile**.

---

## Tecnologías
- **C++**
- Compilación con `g++` + `make`
- (Opcional) **Doxygen** para documentación

---

## Compilación y ejecución

```bash
cd Invernadero/Ficheros
make
./main
```