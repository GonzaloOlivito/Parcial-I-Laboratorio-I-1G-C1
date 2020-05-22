#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

/** \brief Lista todos los tipos de bicicletas
 *
 * \param tipos[] eTipo
 * \param tamt int
 * \return void
 *
 */
void listarTipos(eTipo tipos[], int tamt)
{
    printf(" ID         TIPO\n");
     for(int i=0;i<tamt;i++)
    {
        printf("%d   %8s \n", tipos[i].id,tipos[i].descripcion);
    }
}

/** \brief Funcion para cargar el tipo de bicicleta a traves de su id
 *
 * \param descripcion[] char
 * \param tipos[] eTipo
 * \param tamt int
 * \param id int
 * \return int
 *
 */
int cargarDescripcionTipo(char descripcion[], eTipo tipos[], int tamt, int id)
{
    int retorno = -1;
    for(int i=0;i<tamt;i++)
    {
        if(tipos[i].id==id)
        {
            strcpy(descripcion,tipos[i].descripcion);
            retorno = 1;
        }
    }

    return retorno;
}
