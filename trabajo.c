#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "bicicleta.h"
#include "servicio.h"
#include "utn.h"


/** \brief Funcion para inicializar en 1 todos los trabajos
 *
 * \param trabajos[] eTrabajo
 * \param tamT int
 * \return void
 *
 */
void inicializarTrabajo(eTrabajo trabajos[], int tamtrab)
{
    for(int i=0; i<tamtrab; i++)
    {
        if(trabajos[i].isEmpty!=0)
        {
            trabajos[i].isEmpty=1;
        }

    }
}

/** \brief  Funcion que busca lugar libre en el vector trabajo
 *
 * \param trabajos[] eTrabajo
 * \param tamT int
 * \return retorna -1 en caso de error y el indice del vector en caso de existir libre
 *
 */
int buscarLibreTrabajo(eTrabajo trabajos[], int tamtrab)
{
    int retorno=-1;

    for(int i=0; i<tamtrab; i++)
    {
        if(trabajos[i].isEmpty==1)
        {
            retorno=i;

            break;
        }


    }

    return retorno;
}

/** \brief Funcion para dar de alta un trabajo
 *
 * \param Recirbe los vectores y sus respectivos tamaños
 * \param Recibe el id ya que es autoincremental
 * \return  Returna 0 en caso de error y 1 en caso de tener exito en la alta
 *
 */
int altaTrabajo(int idTrabajo, eTrabajo trabajos[], int tamtrab, eBicicleta bicicletas[], int tam, eServicio servicios[], int tams, eTipo tipos[],
                int tamt, eColor colores[], int tamc, eCliente cliente[], int tamcliente)
{
    system("cls");
    printf("**ALTA TRABAJO**\n\n");
    int retorno=0;
    int libre=buscarLibreTrabajo(trabajos,tamtrab);
    int auxIdBici;
    int estaBici;

    if(libre==-1)
    {
        printf("No hay lugar\n");
    }
    else
    {


        mostrarBicis(bicicletas,tam,tipos,tamt,colores,tamc,cliente,tamcliente);
        getIntRange(&auxIdBici,0,9999,"Ingrese el ID de la bicicleta a seleccionar (entre 0 y 9999): ");
        estaBici=buscarBicicleta(auxIdBici,bicicletas,tam);
        if(estaBici ==-1)
        {
            printf("Id mal ingresado. Reintente");
        }
        else
        {
            trabajos[libre].idBici=auxIdBici;
            listarServicios(servicios,tams);
            getIntRange(&trabajos[libre].idServicio,20000,20003,"Ingrese el ID del servicio a realizar: " );
            trabajos[libre].idTrabajo=idTrabajo;
            getIntRange(&trabajos[libre].fecha.dia,0,31,"Ingrese el dia: ");
            getIntRange(&trabajos[libre].fecha.mes,0,12,"Ingrese el mes: ");
            getIntRange(&trabajos[libre].fecha.anio,1950,2020,"Ingrese el anio (entre 1950 y 2020): ");
            trabajos[libre].isEmpty=0;

            retorno=1;
            printf("\nAlta de trabajo exitosa! \n");
        }


    }

    return retorno;
}

/** \brief Funcion que muestra un solo trabajo
 *
 * \param
 * \param
 * \return
 *
 */
void mostrarTrabajo (eTrabajo trabajo, eServicio servicios[], int tams)
{
    char servicioDes[20];
    cargarDescripcionServicio(servicios,tams,trabajo.idServicio,servicioDes);
    printf("%4d    %8d  %10s    %.2d/%.2d/%d\n", trabajo.idTrabajo,trabajo.idBici,servicioDes,trabajo.fecha.dia,trabajo.fecha.mes
                                                                                                            ,trabajo.fecha.anio);
}
/** \brief Funcion que muestra todos los trabajos
 *
 * \param
 * \param
 * \return
 *
 */
void mostrarTrabajos (eTrabajo trabajos[], int tamtrab, eServicio servicios[], int tams)
{
    system("cls");
    printf("** LISTADO TRABAJOS ** \n\n");
    printf("ID TRABAJO  ID BICI  SERVICIO   PRECIO  FECHA\n");
    int flag=-1;
    for(int i =0; i<tamtrab; i++)
    {

        if(trabajos[i].isEmpty==0)
        {
            mostrarTrabajo(trabajos[i],servicios,tams);
            flag=1;
        }
    }
    if(flag==-1)
    {
        printf("No hay trabajos que mostrar\n\n");
    }
}
