#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#include "tipo.h"
#include "color.h"
#include "bicicleta.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"
#include "informes.h"

#define TAM 9
#define TAMT 4
#define TAMC 5
#define TAMHARD 8
#define TAMS 4
#define TAMTRAB 8
#define TAMCLIENTE 8
int main()
{
    char respuesta;
    char seguir = 's';
    int idTrab=50;
    int flag=-1;
    eBicicleta bicis[TAM];
    eTipo tipos[TAMT]={{1000,"Rutera"},{1001,"Carrera"},{1002,"Mountain"},{1003,"BMX"}};
    eColor colores[TAMC]={{5000,"Gris"},{5001,"Negro"},{5002,"Blanco"},{5003,"Azul"},{5004,"Rojo"}};
    eServicio servicios[TAMS]={{20000,"Limpieza",250},{20001,"Parche",300},{20002,"Centrado",400},{20003,"Cadena",350}};
eTrabajo trabajos[TAMTRAB]={{2009,20001,50,0,{12,12,2019}},{2001,20003,51,0,{10,2,2018}},{2002,20002,52,0,{8,9,2020}},{2000,20002,53,0,{12,12,2017}},{2008,20003,54,0,{12,12,2017}}
                                ,{2000,20003,55,0,{25,6,2020}},{2004,20001,56,0,{12,7,2020}},{2009,20000,56,0,{25,12,2020}}};
    eCliente clientes[TAMCLIENTE]={{1,"Gonzalo",'m'},{2,"Martin",'m'},{3,"Federico",'m'},{4,"Mar",'f'},{5,"Estefania",'f'}
                                ,{6,"Maria",'f'},{7,"Sabrina",'f'},{8,"Marcos",'m'}};
    inicializarBicicletas(bicis,TAM);
    //inicializarTrabajo(trabajos,TAMTRAB);

    if(hardcoreo(bicis,TAMHARD))
    {
        flag=1;
    }

     do
    {

        switch(menuOpciones())
        {
        case 'a':
            if(altaBicicleta(bicis,TAM,colores,TAMC,tipos,TAMT,clientes,TAMCLIENTE))
            {
                flag=1;
            }
            break;
        case 'b':
            if(flag==-1)
            {
                printf("Primero debe dar de alta una bicicleta\n");

            }else
            {
                modificarBicicleta(bicis,TAM,tipos,TAMT,colores,TAMC,clientes,TAMCLIENTE);
            }

            break;
        case 'c':
              if(flag==-1)
            {
                printf("Primero debe dar de alta una bicicleta\n");

            }else
            {
                bajaBicicleta(bicis,TAM,tipos,TAMT,colores,TAMC,clientes,TAMCLIENTE);
            }

            break;
        case 'd':
            ordenar(bicis,TAM,tipos,TAMT,colores,TAMC);
             mostrarBicis(bicis,TAM,tipos,TAMT,colores,TAMC,clientes,TAMCLIENTE);
            break;
        case 'e':
            system("cls");
            listarTipos(tipos,TAMT);
            break;
        case 'f':
            system("cls");
            listarColores(colores,TAMC);
            break;
        case 'g':
            system("cls");
            listarServicios(servicios,TAMS);

            break;
        case 'h':
            if(flag==-1)
            {
            printf("Primero debe dar de alta una bicicleta");
            }else if(altaTrabajo(idTrab,trabajos,TAMTRAB,bicis,TAM,servicios,TAMS,tipos,TAMT,colores,TAMC,clientes,TAMCLIENTE))
            {
                idTrab++;
            }
            break;
        case 'i':
            mostrarTrabajos(trabajos,TAMTRAB,servicios,TAMS);
            break;
        case 'j':
            informes(bicis,TAM,tipos,TAMT,colores,TAMC,clientes,TAMCLIENTE,trabajos,TAMTRAB,servicios,TAMS);
            break;
        case 'k':
            printf("\nSeguro que desea salir?s/n: ");
            fflush(stdin);
            scanf("%c", &respuesta);
            if(respuesta == 's')
            {
                seguir='n';
            }
            break;
        }
        system("pause");
    }
    while(seguir == 's');
    return 0;

    return 0;
}
