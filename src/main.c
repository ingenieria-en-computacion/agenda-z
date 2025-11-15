#include <stdio.h>
#include <string.h>
#include "agenda.h"

int main() {
    Agenda a;

    strcpy(a.directorio, "contactos");
    sprintf(a.rutaArchivo, "%s/contactos.txt", a.directorio);

    iniciar_agenda(&a);
    crearDirectorio(a);
    crearTXT(a);
    cargar_contactos(&a);
    menu(a);

    return 0;
}


