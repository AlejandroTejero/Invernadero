# P8-Ficheros_23-24

**Fecha:** 25/04/2024  
**Autor:** Tejero de la Morena, Alejandro

## Objetivo
En esta práctica nos encargaremos de aprender a manejar ficheros binarios, en este caso con extension .dat.

## Desarrollo
Para esta práctica he añadido un fichero para el manejo de sensores (sensors.dat). Aunque de momento no se pueden eliminar sensores, o añadir nuevos, en un futuro sería una buena actualizacion poder encender, apagar o modificar sensores, de forma que se queden reflejados todos estos cambios en el fichero.
Es un fichero binario con ios::trunc, de forma que cada vez que se inicia la aplicación se reescibe el contenido anterior por los cambios nuevos. 

### Posible error por falta de instalacion de figlet.

He añadido una interfaz visual para el inicio y el final del programa. Esto requiere de figlet, en caso de que salte algun error, que no deberia ocurrir ya que lo he probado con varios ordenadores que no tienen instalado figlet y funciona. En caso de saltar error debemos instalar el añadido figlet, con este comando por terminal: sudo apt-get install figlet.