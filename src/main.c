#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "agenda.h"

int main() {

    Agenda a;

    strcpy(a.directorio, "contactos");
    sprintf(a.rutaArchivo, "%s/contactos.txt", a.directorio);
    a.max_contactos = 50;

    crearDirectorio(a);
    crearTXT(a);
    menu(a);

    return 0;
}
