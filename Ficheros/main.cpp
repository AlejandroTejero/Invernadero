#include "Interfaz.h"
#include "BDUsuarios.h"
#include "BDSensores.h"
#include "Login.h"

int main() {

    Interfaz interfaz;
    BDUsuarios basedatos;
    BDSensores bdsensores;
    Login login;

    bdsensores.ConfigurarSensores();
    login.GestionarUsuarios(basedatos, interfaz, bdsensores);

    return 0;
}