#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "color.h"
#include "informes.h"
#include "tipo.h"
#include "cliente.h"
#include "utn.h"
#include "trabajo.h"
#include "servicio.h"

void informes(eBicicleta bicicletas[], int tam,eTipo tipo[],int tamt, eColor color[], int tamc, eCliente cliente[], int tamcli,eTrabajo trabajos[], int tamtrab, eServicio servicios[], int tams)
{
    char respuesta;
    char seguir='s';
    do
    {
        switch(menuInformes())
        {
        case 'a':
            informarBicisPorColor(bicicletas,tam,tipo,tamt,color,tamc,cliente,tamcli);
            break;
        case 'b':
            informarBicisPorTipo(bicicletas,tam,tipo,tamt,color,tamc,cliente,tamcli);
            break;
        case 'c':
            biciMenorRodado(bicicletas,tam,tipo,tamt,color,tamc,cliente,tamcli);
            break;
        case 'd':
            listadoBiciPorTipo(bicicletas,tam,tipo,tamt,color,tamc,cliente,tamcli);
            break;
        case 'e':
listadoBiciPorTipoyColor(bicicletas,tam,tipo,tamt,color,tamc,cliente,tamcli);
            break;
        case 'f':
mostrarTrabajoXBici(bicicletas,tam,tipo,tamt,color,tamc,cliente,tamcli,trabajos,tamtrab,servicios,tams);
            break;
        case 'h':

            break;
        case 'g':
            printf("Confirma salir: s/n: ");
            fflush(stdin);
            scanf("%c",&respuesta);
            if(respuesta=='s')
            {
                seguir='n';
                break;
            }
            break;
        }
        system("pause");
    }
    while(seguir == 's');


}

char menuInformes()
{
    char opcion;
    system("cls");
    printf("\n*** Informe Bicicletas ***\n\n");
    printf("A. Informe bicicletas por color seleccionado\n");
    printf("B. Informe bicicletas por tipo seleccionado\n");
    printf("C. Informe bicicleta de menor rodado\n");
    printf("D. Informe bicicletas separadas por tipo\n");
    printf("E. Informe cantidad de bicicletas del mismo color y tipo\n");
    printf("F. Mostrar trabajo por bicicleta\n");
    printf("\n");
    printf("G. Salir\n");

    printf("Ingrese una respuesta: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;
}

void informarBicisPorColor(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc, eCliente cliente[], int tamcli)
{
    int idColor;
    char descriColor[20];
    system("cls");
    printf("***BICICLETAS POR COLOR***\n\n");
    listarColores(color,tamc);
    getIntRange(&idColor,5000,5004,"Ingrese el ID del color de bicicleta a seleccionar: ");
    cargarDescripcionColor(idColor,descriColor,color,tamc);
    system("cls");
    printf("\nUsted eligio el color : %s\n", descriColor);
    printf("ID        MARCA       TIPO     COLOR   RODADO    CLIENTE\n");
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            if(idColor == vec[i].idColor)
            {
                mostrarBici(vec[i],tipo,tamt,color,tamc,cliente,tamcli);
            }
        }

    }

}

void informarBicisPorTipo(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc, eCliente cliente[], int tamcli)
{
    int idTipo;
    char descriTipo[20];
    system("cls");
    printf("***BICICLETAS POR TIPO***\n\n");
    listarTipos(tipo,tamt);
    getIntRange(&idTipo,1000,1003,"Ingrese el ID del tipo de bicicleta a seleccionar: ");
    cargarDescripcionTipo(descriTipo,tipo,tamt,idTipo);
    system("cls");
    printf("\nUsted eligio el tipo : %s\n", descriTipo);
    printf("ID        MARCA       TIPO     COLOR   RODADO    CLIENTE\n");
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            if(idTipo == vec[i].idTipo)
            {
                mostrarBici(vec[i],tipo,tamt,color,tamc,cliente,tamcli);
            }
        }

    }

}


void biciMenorRodado(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc, eCliente cliente[], int tamcli)
{
    system("cls");
    float menor;
    printf("***INFORME BICICLETA MENOR RODADO***\n");
    int flag=0;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            if(menor>vec[i].rodado || flag ==0)
            {
                menor=vec[i].rodado;
                flag=1;
            }

        }

    }
    for(int i=0;i<tam;i++)
    {
        if(vec[i].rodado == menor && vec[i].isEmpty==0)
            {
                printf("ID        MARCA       TIPO     COLOR   RODADO    CLIENTE\n");
                mostrarBici(vec[i],tipo,tamt,color,tamc,cliente,tamcli);
                printf("\nEl menor rodado registrado es: %.2f \n\n",menor);
            }
    }




}

void listadoBiciPorTipo(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc, eCliente cliente[], int tamcli)
{
    system("cls");
    printf("        ****LISTADO DE BICICLETAS POR TIPO****\n\n");
    for(int t=0;t<tamt;t++)
    {

        printf("Listado de bicicleta tipo: %s \n",tipo[t].descripcion);
        for(int b=0;b<tam;b++)
        {
            if(vec[b].idTipo==tipo[t].id)
            {
                mostrarBici(vec[b],tipo,tamt,color,tamc,cliente,tamcli);
            }

        }
         printf("----------------------------------------------------------\n");
    }
}

void listadoBiciPorTipoyColor(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc, eCliente cliente[], int tamcli)
{
    system("cls");
    int idTipo;
    int idColor;
    int contador=0;
    char descripTipo[20];
    char descripColor[20];
    system("cls");
    printf("   ****LISTADO DE BICICLETAS POR TIPO Y COLOR****\n\n");
    listarTipos(tipo,tamt);
    getIntRange(&idTipo,1000,1003,"Ingrese el id del tipo de bicicleta: ");
    listarColores(color,tamc);
    getIntRange(&idColor,5000,5004,"Ingrese el id del color de bicicleta: ");
    cargarDescripcionTipo(descripTipo,tipo,tamt,idTipo);
    cargarDescripcionColor(idColor,descripColor,color,tamc);
    printf("\nID        MARCA       TIPO     COLOR   RODADO    CLIENTE\n");
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty==0)
        {
            if(vec[i].idColor==idColor && vec[i].idTipo==idTipo)
            {

                contador++;
                mostrarBici(vec[i],tipo,tamt,color,tamc,cliente,tamcli);
            }
        }
    }

    printf("\n\nHay %d bicicletas del tipo %s y color %s\n",contador,descripTipo,descripColor);

}

void colorMasElegido(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc, eCliente cliente[], int tamcli)
{
    system("cls");
    int contador=0;
    for(int c=0;c<tamc;c++)
    {
        for(int i=0;i<tam;i++)
        {
           if(vec[i].isEmpty && vec[i].idColor==color[c].id)
           {
               contador++;
           }
        }

    }

    printf(": %d",contador);
}

void mostrarTrabajoXBici(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc, eCliente cliente[], int tamcli,eTrabajo trabajos[], int tamtrab, eServicio servicios[], int tams)
{
    system("cls");
    int idBici;
    mostrarBicis(vec,tam,tipo,tamt,color,tamc,cliente,tamcli);
    getIntRange(&idBici,2000,2020,"Ingrese el id de la bicicleta a consultar: ");

    printf("Se realizaron los siguientes servicios: \n");
    printf("ID TRABAJO  ID BICI  SERVICIO     FECHA\n");
    for(int i=0;i<tamtrab;i++)
    {
        if(trabajos[i].isEmpty==0)
        {
            if(trabajos[i].idBici==idBici)
            {
                mostrarTrabajo(trabajos[i],servicios,tams);
            }
        }
    }

}
