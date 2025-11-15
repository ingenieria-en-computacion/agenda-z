

// Se deja estructura para ir complementando con lo que se hizo ofline

//#include "agenda.h"

/**
 * Esta función se encarga de iniciar el número de contactos a cero

void iniciar_agenda(Agenda *agenda){

}



// Varible que lleva la cuenta de cuantos contactos hay en la agenda
int num_contactos;

/**
 * Esta función sirve para agregar un contacto nuevo en la agenda

void agregar_contacto(Agenda *agenda, Contacto c){

}


/**
 * Esta función sirve para buscar un contacto por nombre en la agenda y retorna la posición del contacto si exisite
 * En caso contrario retorna -1

int buscar_contacto(Agenda *agenda, char *nombre){

}


/**
 * Esta función  sirve para buscar un contacto por su número de telefono en la agenda

int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]){

}


/**
 * Esta función sirve para ordenar los contactos por nombres de forma ascendente

void ordenar_contactos(Agenda *a){
    int i, j;
    Contacto temp;
    for(i = 0; i < a->num_contactos; i++){
        for(j=0; j < a->num_contactos-i-1; j++){
            if(strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre)>0){
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
        }
    }
}

/**
 * Esta función sirve para ordenar los contactos por nombres de forma descendente

void ordenar_contactos_inv(Agenda *a){
    int i, j;
    Contacto temp;
    for(i = 0; i < a->num_contactos; i++){
        for(j=0; j < a->num_contactos-i-1; j++){
            //Completar basandose en la función anterior
        }
    }
}


/**
 * Función auxiliar para imprimir un contacto
/
void mostrar_contacto(Contacto){

}


/**
 * Función auxiliar para leer un contacto

void leer_contacto(Contacto *c){

}

/**
 * Función que imprime todos los contactos de la agenda en pantalla

void imprimir_agenda(Agenda agenda){

}

/**
 * Función que sirve para cargar contactos escritos en un archivo a la agenda

void cargar_contactos(char *filename, Agenda *agenda){

}

 * Función que sirve para guardar todos los contactos de la agenda en un archivo
 
void guardar_contactos(char *filename, Agenda agenda){

}
 */
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

// Arreglos de strings para imprimir enums
char *mesesStr[] = {
    "ENERO","FEBRERO","MARZO","ABRIL","MAYO","JUNIO",
    "JULIO","AGOSTO","SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"
};


char *tiposTelStr[] = {"Casa","Movil","Oficina","Otro"};
char *tiposContactoStr[] = {"Amigo","Conocido","Laboral"};

/**
 * Esta función se encarga de iniciar el número de contactos a cero
 */
void iniciar_agenda(Agenda *agenda){
    agenda->num_contactos = 0;
}

// Variable que lleva la cuenta de cuantos contactos hay en la agenda
int num_contactos = 0;

/**
 * Esta función sirve para agregar un contacto nuevo en la agenda
 */
void agregar_contacto(Agenda *agenda, Contacto c){
    if(agenda->num_contactos < MAX_CONTACTOS){
        agenda->contactos[agenda->num_contactos++] = c;
    }
}

/**
 * Esta función sirve para buscar un contacto por nombre en la agenda y retorna la posición del contacto si existe
 * En caso contrario retorna -1
 */
int buscar_contacto(Agenda *agenda, char *nombre){
    for(int i = 0; i < agenda->num_contactos; i++){
        if(strcmp(agenda->contactos[i].nombre, nombre) == 0)
            return i;
    }
    return -1;
}

/**
 * Esta función sirve para buscar un contacto por su número de telefono en la agenda
 */
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]){
    for(int i = 0; i < agenda->num_contactos; i++){
        if(strcmp(agenda->contactos[i].telefono, telefono) == 0)
            return i;
    }
    return -1;
}

/**
 * Esta función sirve para ordenar los contactos por nombres de forma ascendente
 */
void ordenar_contactos(Agenda *a){
    int i,j;
    Contacto temp;
    for(i=0;i<a->num_contactos-1;i++){
        for(j=0;j<a->num_contactos-i-1;j++){
            if(strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre)>0){
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
        }
    }
}

/**
 * Esta función sirve para ordenar los contactos por nombres de forma descendente
 */
void ordenar_contactos_inv(Agenda *a){
    int i,j;
    Contacto temp;
    for(i=0;i<a->num_contactos-1;i++){
        for(j=0;j<a->num_contactos-i-1;j++){
            if(strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre)<0){
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
        }
    }
}

/**
 * Función auxiliar para imprimir un contacto
 */
void mostrar_contacto(Contacto c){
    printf("%s %s | %d %s | %s | %s | %s\n",
           c.nombre,
           c.apellido,
           c.diaNacimiento,
           mesesStr[c.mesNacimiento],
           c.telefono,
           tiposTelStr[c.tipoTelefono],
           tiposContactoStr[c.tipoContacto]);
}

/**
 * Función auxiliar para leer un contacto
 */
void leer_contacto(Contacto *c){
    int mes, tipoTel, tipoCon;

    printf("Nombre: ");
    scanf("%s", c->nombre);

    printf("Apellido: ");
    scanf("%s", c->apellido);

    printf("Dia de nacimiento: ");
    scanf("%d", &c->diaNacimiento);

   printf("Mes de nacimiento (en mayuscula completo): ");
    scanf("%d", &mes);
    c->mesNacimiento = mes - 1;

    printf("Telefono: ");
    scanf("%s", c->telefono);

    printf("Tipo de telefono (0=Casa,1=Movil,2=Oficina,3=Otro): ");
    scanf("%d", &tipoTel);
    c->tipoTelefono = tipoTel;

    printf("Tipo de contacto (0=Amigo,1=Conocido,2=Laboral): ");
    scanf("%d", &tipoCon);
    c->tipoContacto = tipoCon;
}

/**
 * Función que imprime todos los contactos de la agenda en pantalla
 */
void imprimir_agenda(Agenda agenda){
    printf("\nPersona | Cumpleanios | Telefono | Tipo Telefono | Tipo Contacto\n");
    printf("_______________________________________________________________\n");
    for(int i=0;i<agenda.num_contactos;i++){
        mostrar_contacto(agenda.contactos[i]);
    }
}

/**
 * Función que sirve para cargar contactos escritos en un archivo a la agenda
 */
void cargar_contactos(char *filename, Agenda *agenda){
    FILE *f = fopen(filename,"r");
    if(!f) return;

    while(!feof(f)){
        Contacto c;
        int mesTmp, tipoTelTmp, tipoConTmp;
        if(fscanf(f,"%29[^|]|%29[^|]|%d|%d|%19[^|]|%d|%d\n",
                  c.nombre, c.apellido,
                  &c.diaNacimiento, &mesTmp,
                  c.telefono, &tipoTelTmp, &tipoConTmp)==7){
            c.mesNacimiento = mesTmp;
            c.tipoTelefono = tipoTelTmp;
            c.tipoContacto = tipoConTmp;
            agregar_contacto(agenda,c);
        }
    }

    fclose(f);
}

/**
 * Función que sirve para guardar todos los contactos de la agenda en un archivo
 */
void guardar_contactos(char *filename, Agenda agenda){
    FILE *f = fopen(filename,"w");
    if(!f) return;

    for(int i=0;i<agenda.num_contactos;i++){
        Contacto c = agenda.contactos[i];
        fprintf(f,"%s|%s|%d|%d|%s|%d|%d\n",
                c.nombre,c.apellido,
                c.diaNacimiento,c.mesNacimiento,
                c.telefono,c.tipoTelefono,c.tipoContacto);
    }

    fclose(f);
}
