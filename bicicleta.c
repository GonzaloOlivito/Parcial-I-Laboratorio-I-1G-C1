#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "utn.h"
#include "tipo.h"
#include "color.h"
#include "cliente.h"
#include "datawarehouse.h"

/** \brief Funcion que engloba todas las opciones del programa
 *
 * \return devuelve la opcion ingresada
 *
 */
char menuOpciones()
{
    char opcion;
    system("cls");

    printf("BIENVENIDO \n\n");
    printf("A.Alta bicicleta\n");
    printf("B.Modificar bicicleta\n");
    printf("C.Baja bicicleta\n");
    printf("D.Lista bicicletas\n");
    printf("E.Listar tipos\n");
    printf("F.Listar colores\n");
    printf("G.Listar Servicios\n");
    printf("H.Alta trabajo\n");
    printf("I.Mostrar trabajos\n");
    printf("J.Informes\n");
    printf("K.Salir\n");
    printf("Ingrese la opcion deseada: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}

/** \brief Funcion que inicializa todas las bicicletas vacias en 1
 *
 * \param vec[] eBicicleta Recibe el vector de bicicletas
 * \param tam int El tamaño del vector
 * \return No retorna nada
 *
 */
void inicializarBicicletas(eBicicleta vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty=1;
    }
}

/** \brief Funcion que busca lugar libre en el vector
 *
 * \param vec[] eBicicleta Recibe el vector de bicicletas
 * \param tam int Tamaño del vector
 * \return int retorna -1 en caso de error o el lugar libre en el vector
 *
 */
int buscarLibre(eBicicleta vec[], int tam)
{
    int retorno = -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
/** \brief Funcion que busca una bicicleta por ID
 *
 * \param Se ingresa el id a buscar
 * \param Se busca en el vector
 * \return Retorna -1 en caso de no encontrarlo o el vector posicion en caso de encontrarlo
 *
 */

int buscarBicicleta(int id, eBicicleta vec[], int tam)
{

    int retorno = -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0 && vec[i].id == id)
        {
            retorno = i;
            break;
        }

    }
    return retorno;
}


/** \brief Funcion para dar de alta una bicicleta
 *
 * \param vec[] eBicicleta Vector bicicleta
 * \param tam int Tamaaño del vector
 * \return int retorna 0 en caso de error y 1 en caso de dar de alta
 *
 */
int altaBicicleta(eBicicleta vec[], int tam, eColor colores[], int tamc, eTipo tipos[], int tamt, eCliente cliente[], int tamcliente)
{
    system("cls");
    printf("**ALTA BICICLETA**\n\n");
    int todoOk=0;
    int libre=buscarLibre(vec,tam);
    int esta;
    int id;
    if(libre==-1)
    {
        printf("No hay lugar\n");
    }
    else
    {
        getIntRange(&id,0,9999,"Ingrese id (entre 0 y 9999): ");
        esta=buscarBicicleta(id,vec,tam);
        if(esta==-1)
        {
            vec[libre].id=id;
            getStringAlpha(20,"Ingrese la marca: ", vec[libre].marca);
            listarTipos(tipos,tamt);
            getIntRange(&vec[libre].idTipo,1000,1003,"Ingrese el id tipo: ");
            listarColores(colores,tamc);
            getIntRange(&vec[libre].idColor,5000,5004,"Ingrese el id color: ");
            getFloatRange(0,99,&vec[libre].rodado,"Ingrese el rodado (entre 0 y 99): ");
            //listarClientes(clientes,tamclientes);
            //getIntRange(&vec[libre].idCliente,0,10,"Ingrese el id cliente: ");
            vec[libre].isEmpty=0;
            todoOk=1;
            printf("\nAlta exitosa! \n");
        }
        else
        {
            printf("El id ya esta registrado, reintente.\n");
        }
    }

    return todoOk;
}

/** \brief Funcion para mostrar una sola bicicleta
 *
 * \param Recibe los vectores tipo y color con sus respectivos tamaños
 * \param Recibe un tipo de dato de la estructura
 * \return no retorna nada
 *
 */
void mostrarBici (eBicicleta bici, eTipo tipoBici[], int tamTipo, eColor colorBici[], int tamColor, eCliente cliente[], int tamcliente)
{
    char tipoDes[20];
    char colorDes[20];
    char nombreDes[20];
    cargarDescripcionTipo(tipoDes,tipoBici,tamTipo,bici.idTipo);
    cargarDescripcionColor(bici.idColor,colorDes,colorBici,tamColor);
    cargarDescripcionCliente(nombreDes,cliente,tamcliente,bici.idCliente);
    printf("%d   %9s    %8s %8s    %.2f  %10s  \n", bici.id,bici.marca,tipoDes,colorDes,bici.rodado,nombreDes);
}

/** \brief Funcion para mostrar todas las bicicletas del vector
 *
 * \param Recibe todas las estructuras con sus respectivos tamaños
 * \param
 * \return No devuelve nada la funcion
 *
 */
void mostrarBicis (eBicicleta vec[], int tam, eTipo tipoBici[], int tamTipo, eColor colorBici[], int tamColor, eCliente cliente[], int tamcliente)
{
    system("cls");
    printf("** LISTADO BICIS ** \n\n");
    printf("ID        MARCA       TIPO     COLOR   RODADO    CLIENTE\n");
    int flag=-1;
    for(int i =0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarBici(vec[i],tipoBici,tamTipo,colorBici,tamColor,cliente,tamcliente);
            flag=1;
        }
    }
    if(flag==-1)
    {
        printf("No hay bicis que mostrar\n\n");
    }
}

/** \brief Funcion para hardcodear bicicletas
 *
 * \param vec[] eBicicleta
 * \param tam int
 * \return retorna 1 en caso de exito
 *
 */
int hardcoreo(eBicicleta vec[], int tam)
{
    int retorno=-1;
    for(int i=0; i<tam; i++)
    {
        vec[i].id=ids[i];
        vec[i].idColor=idsColor[i];
        vec[i].idTipo=idsTipo[i];
        vec[i].idCliente=idsCliente[i];
        strcpy(vec[i].marca,marcas[i]);
        vec[i].rodado=rodados[i];
        vec[i].isEmpty=0;
        retorno=1;
    }
    return retorno;
}

/** \brief Funcion para modificar una bicicleta
 *
 * \param vec[] eBicicleta Recibe el vector bicicleta y su tamaño
 * \param tam int
 * \param tipo[] eTipo El vector de tipos de bicicicleta junto con su tamaño
 * \param tamt int
 * \param color[] eColor El vector de colores con su tamaño
 * \param tamc int
 * \return int Retorna -1 en caso de error y 1 en caso de modificar exitosamente
 *
 */
int modificarBicicleta(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc, eCliente cliente[], int tamcliente)
{
    int id;
    int eleccion;
    int retorno=-1;
    int esta;
    system("cls");
    printf("***MENU MODIFICACION***\n\n");
    mostrarBicis(vec,tam,tipo,tamt,color,tamc,cliente,tamcliente);

    getIntRange(&id,0,9999,"Ingrese el id a modificar: ");
    esta=buscarBicicleta(id,vec,tam);
    if(esta== -1)
    {
        printf("Id mal ingresado, reintente.");
    }
    else
    {
        system("cls");
        printf("ID        MARCA       TIPO     COLOR   RODADO    CLIENTE\n");
        mostrarBici(vec[esta],tipo,tamt,color,tamc,cliente,tamcliente);
        printf("1. Modificar tipo\n");
        printf("2. Modificar rodado\n");
        getIntRange(&eleccion,1,2,"Ingrese la opcion a modificar: ");
        switch(eleccion)
        {
        case 1:
            listarTipos(tipo,tamt);
            getIntRange(&vec[esta].idTipo,1000,1004, "Ingrese el nuevo tipo: ");
            printf("Tipo modificado con exito \n");
            break;
        case 2:
            getFloatRange(0,999,&vec[esta].rodado,"Ingrese el nuevo rodado: ");
            printf("Rodado modificado con exito \n");
            break;
            retorno = 1;
        }
    }

    return retorno;
}

/** \brief Funcion para dar baja logica de una bicicleta
 *
 * \param vec[] eBicicleta Recibe el vector bicicletas
 * \param tam int
 * \param tipo[] eTipo Recibe los tipos
 * \param tamt int
 * \param color[] eColor Recibe los colores
 * \param tamc int
 * \return int Devuelve -1 en caso de error y 1 en caso de lograr la baja logica
 *
 */
int bajaBicicleta(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc, eCliente cliente[], int tamcliente)
{
    int id;
    char eleccion;
    int retorno=-1;
    int esta;
    system("cls");
    printf("***MENU BAJA***\n\n");
    mostrarBicis(vec,tam,tipo,tamt,color,tamc,cliente,tamcliente);

    getIntRange(&id,0,9999,"Ingrese el id a dar de baja: ");
    esta=buscarBicicleta(id,vec,tam);
    if(esta== -1)
    {
        printf("Id mal ingresado, reintente.");
    }
    else
    {
        system("cls");
        printf("\nSelecciono: \n");
        printf("ID        MARCA       TIPO     COLOR   RODADO  NOMBRE \n");
        mostrarBici(vec[esta],tipo,tam,color,tamc,cliente,tamcliente);
        getChar(3,&eleccion,"Confirma baja? s/n");
        if(eleccion == 's')
        {
            vec[esta].isEmpty=1;
            printf("Baja realizada con exito");
            retorno = 1;
        }
    }
    return retorno;
}

/** \brief Funcion que ordena las bicis por tipo y rodado en caso de ser el mismo tipo
 *
 * \param bicicleta[] eBicicleta
 * \param tam int
 * \param tipos[] eTipo
 * \param tamt int
 * \param color[] eColor
 * \param tamc int
 * \return void
 *
 */
void ordenar(eBicicleta bicicleta[], int tam, eTipo tipos[], int tamt, eColor color[], int tamc)
{
    system("cls");
    eBicicleta aux;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(bicicleta[i].isEmpty==0 && bicicleta[i].idTipo<bicicleta[j].idTipo)
            {
                aux=bicicleta[i];
                bicicleta[i]=bicicleta[j];
                bicicleta[j]=aux;
            }
            else if(bicicleta[i].isEmpty==0 && bicicleta[i].idTipo==bicicleta[j].idTipo && bicicleta[i].rodado>bicicleta[j].rodado )
            {
                aux=bicicleta[i];
                bicicleta[i]=bicicleta[j];
                bicicleta[j]=aux;
            }
        }
    }
}
