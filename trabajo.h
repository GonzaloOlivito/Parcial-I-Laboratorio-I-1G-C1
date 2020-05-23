#include "servicio.h"
#include "bicicleta.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
int dia;
int mes;
int anio;

}eFecha;

typedef struct{
int idBici;
int idServicio;
int idTrabajo;
int isEmpty;
eFecha fecha;
}eTrabajo;




#endif // TRABAJO_H_INCLUDED

int altaTrabajo(int idTrabajo, eTrabajo trabajos[], int tamtrab, eBicicleta bicicletas[], int tam, eServicio servicios[], int tams, eTipo tipos[],
                int tamt, eColor colores[], int tamc, eCliente cliente[], int tamcliente);
void inicializarTrabajo(eTrabajo trabajos[], int tamtrab);
int buscarLibreTrabajo(eTrabajo trabajos[], int tamtrab);
void mostrarTrabajos (eTrabajo trabajos[], int tamtrab, eServicio servicios[], int tams);
void mostrarTrabajo (eTrabajo trabajo, eServicio servicios[], int tams);
int hardcoreoTrabajo(eTrabajo vec[], int tam);
