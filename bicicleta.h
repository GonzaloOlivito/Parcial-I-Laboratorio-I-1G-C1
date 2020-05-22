#include "tipo.h"
#include "color.h"
#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct{
int id;
char marca[20];
int isEmpty;
float rodado;
int idTipo;
int idColor;
} eBicicleta;

#endif // BICICLETA_H_INCLUDED

char menuOpciones();
void inicializarBicicletas(eBicicleta vec[], int tam);
int buscarLibre(eBicicleta vec[], int tam);
int buscarBicicleta(int id, eBicicleta vec[], int tam);
int altaBicicleta(eBicicleta vec[], int tam, eColor colores[], int tamc, eTipo tipos[], int tamt);
void mostrarBici (eBicicleta bici, eTipo tipoBici[], int tamTipo, eColor colorBici[], int tamColor);
void mostrarBicis (eBicicleta vec[], int tam, eTipo tipoBici[], int tamTipo, eColor colorBici[], int tamColor);
int hardcoreo(eBicicleta vec[], int tam);
int modificarBicicleta(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc);
int bajaBicicleta(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc);
void ordenar(eBicicleta bicicleta[], int tam, eTipo tipos[], int tamt, eColor color[], int tamc);
