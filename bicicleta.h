#include "tipo.h"
#include "color.h"
#include "cliente.h"
#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct{
int id;
char marca[20];
int isEmpty;
float rodado;
int idTipo;
int idColor;
int idCliente;
} eBicicleta;

#endif // BICICLETA_H_INCLUDED

char menuOpciones();
void inicializarBicicletas(eBicicleta vec[], int tam);
int buscarLibre(eBicicleta vec[], int tam);
int buscarBicicleta(int id, eBicicleta vec[], int tam);
int altaBicicleta(eBicicleta vec[], int tam, eColor colores[], int tamc, eTipo tipos[], int tamt, eCliente cliente[], int tamcliente);
void mostrarBici (eBicicleta bici, eTipo tipoBici[], int tamTipo, eColor colorBici[], int tamColor, eCliente cliente[], int tamcliente);
void mostrarBicis (eBicicleta vec[], int tam, eTipo tipoBici[], int tamTipo, eColor colorBici[], int tamColor, eCliente cliente[], int tamcliente);
int hardcoreo(eBicicleta vec[], int tam);
int modificarBicicleta(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc, eCliente cliente[], int tamcliente);
int bajaBicicleta(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc, eCliente cliente[], int tamcliente);
void ordenar(eBicicleta bicicleta[], int tam, eTipo tipos[], int tamt, eColor color[], int tamc);
