#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"


/** \brief Funcion que lista los clientes
 *
 * \param clientes[] eCliente vector clientes
 * \param tamclientes int tamaño del vector clientes
 * \return void
 *
 */
void listarClientes(eCliente clientes[], int tamclientes)
{
    printf("    LISTA DE CLIENTES\n");
    printf("  ID    NOMBRE   SEXO\n");
    for(int i=0;i<tamclientes;i++)
    {
        printf("%d   %8s   %c\n", clientes[i].idCliente,clientes[i].nombre,clientes[i].sexo);
    }
}

/** \brief Funcion que carga el nombre de un cliente a traves el ID
 *
 * \param descripcion[] char
 * \param clientes[] eCliente
 * \param tamcliente int
 * \param id int
 * \return int retorna -1 en caso de error y 1 en caso de exito
 *
 */
int cargarDescripcionCliente(char descripcion[], eCliente clientes[], int tamcliente, int id)
{
    int retorno = -1;
    for(int i=0;i<tamcliente;i++)
    {
        if(clientes[i].idCliente==id)
        {
            strcpy(descripcion,clientes[i].nombre);
            retorno = 1;
        }
    }

    return retorno;
}
