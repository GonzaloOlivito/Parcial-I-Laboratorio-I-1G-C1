#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"


void listarClientes(eCliente clientes[], int tamclientes)
{
    printf("    LISTA DE CLIENTES\n");
    printf("  ID    NOMBRE   SEXO\n");
    for(int i=0;i<tamclientes;i++)
    {
        printf("%d   %8s   %c\n", clientes[i].idCliente,clientes[i].nombre,clientes[i].sexo);
    }
}

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
