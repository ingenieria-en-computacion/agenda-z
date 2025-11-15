#ifndef __AGENDA_H__
#define __AGENDA_H__

#define MAX_CONTACTOS 100

typedef enum {CASA, MOVIL, OFICINA, OTRO} TipoTelefono;
typedef enum {ENERO, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE} Mes;
typedef enum {AMIGO, CONOCIDO, LABORAL} TipoContacto;

typedef struct {
    char nombre[30];
    char apellido[30];
    int diaNacimiento;
    Mes mesNacimiento;
    char telefono[20];
    TipoTelefono tipoTelefono;
    TipoContacto tipoContacto;
} Persona;

typedef struct {
    Persona contactos[MAX_CONTACTOS];
    int num_contactos;
    char directorio[50];
    char rutaArchivo[100];
} Agenda;

void iniciar_agenda(Agenda *agenda);
void crearDirectorio(Agenda a);
void crearTXT(Agenda a);
void guardar_contactos(Agenda a);
void cargar_contactos(Agenda *agenda);
void agregar_persona(Agenda *agenda, Persona p);
int buscar_persona(Agenda *agenda, char *nombre);
void mostrar_persona(Persona p);
void imprimir_agenda(Agenda a);
void leer_persona(Persona *p);
void ordenar_personas(Agenda *agenda);
void ordenar_personas_inv(Agenda *agenda);
void menu(Agenda a);

#endif
