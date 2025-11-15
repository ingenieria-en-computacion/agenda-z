/*#ifndef __AGENDA_H__
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

#endif*/

#ifndef __AGENDA_H__
#define __AGENDA_H__

#define MAX_CONTACTOS 100

// Enum para tipo de teléfono
typedef enum { CASA, MOVIL, OFICINA, OTRO } TipoTelefono;

// Enum para tipo de contacto
typedef enum { AMIGO, CONOCIDO, LABORAL } TipoContacto;

// Enum para mes de nacimiento
typedef enum { ENERO, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO,
               AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE } Mes;

// Estructura de contacto
typedef struct {
    char nombre[30];
    char apellido[30];
    int diaNacimiento;
    Mes mesNacimiento;
    char telefono[20];
    TipoTelefono tipoTelefono;
    TipoContacto tipoContacto;
} Contacto;

// Estructura de agenda
typedef struct {
    Contacto contactos[MAX_CONTACTOS];
    int num_contactos;
} Agenda;

// Funciones
void iniciar_agenda(Agenda *agenda);
void agregar_contacto(Agenda *agenda, Contacto c);
int buscar_contacto(Agenda *agenda, char *nombre);
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]);
void ordenar_contactos(Agenda *agenda);
void ordenar_contactos_inv(Agenda *agenda);
void mostrar_contacto(Contacto c);
void leer_contacto(Contacto *c);
void imprimir_agenda(Agenda agenda);
void cargar_contactos(char *filename, Agenda *agenda);
void guardar_contactos(char *filename, Agenda agenda);

#endif

