#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int idCliente;
    char nombre[20];
    char sexo;
} eCliente;


#endif // CLIENTE_H_INCLUDED

void listarClientes(eCliente clientes[], int tamclientes);
int cargarDescripcionCliente(char descripcion[], eCliente clientes[], int tamcliente, int id);
