#include "trabajo.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

void informes(eBicicleta bicicletas[], int tam,eTipo tipo[],int tamt, eColor color[], int tamc, eCliente cliente[], int tamcli,eTrabajo trabajos[], int tamtrab, eServicio servicios[], int tams);
char menuInformes();
void informarBicisPorColor(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc, eCliente cliente[], int tamcli);
void informarBicisPorTipo(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc, eCliente cliente[], int tamcli);
void biciMenorRodado(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc, eCliente cliente[], int tamcli);
void listadoBiciPorTipo(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc, eCliente cliente[], int tamcli);
void listadoBiciPorTipoyColor(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc, eCliente cliente[], int tamcli);
void colorMasElegido(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc, eCliente cliente[], int tamcli);
void mostrarTrabajoXBici(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc, eCliente cliente[], int tamcli,eTrabajo trabajos[], int tamtrab, eServicio servicios[], int tams);
void mostrarPlataGastadaEnBici(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc, eCliente cliente[], int tamcli,eTrabajo trabajos[], int tamtrab, eServicio servicios[], int tams);
void mostrarServicioABicis(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc, eCliente cliente[], int tamcli,eTrabajo trabajos[], int tamtrab, eServicio servicios[], int tams);

