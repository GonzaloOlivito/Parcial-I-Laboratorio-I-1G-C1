#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#include "tipo.h"
#include "color.h"
#include "bicicleta.h"
#include "servicio.h"
#include "trabajo.h"


#define TAM 9
#define TAMT 4
#define TAMC 5
#define TAMHARD 8
#define TAMS 4
#define TAMTRAB 8
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
    eTrabajo trabajos[TAMTRAB];
    inicializarBicicletas(bicis,TAM);
    inicializarTrabajo(trabajos,TAMTRAB);

    if(hardcoreo(bicis,TAMHARD))
    {
        flag=1;
    }

   ;
     do
    {

        switch(menuOpciones())
        {
        case 'a':
            if(altaBicicleta(bicis,TAM,colores,TAMC,tipos,TAMT))
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
                modificarBicicleta(bicis,TAM,tipos,TAMT,colores,TAMC);
            }

            break;
        case 'c':
              if(flag==-1)
            {
                printf("Primero debe dar de alta una bicicleta\n");

            }else
            {
                bajaBicicleta(bicis,TAM,tipos,TAMT,colores,TAMC);
            }

            break;
        case 'd':
            ordenar(bicis,TAM,tipos,TAMT,colores,TAMC);
             mostrarBicis(bicis,TAM,tipos,TAMT,colores,TAMC);
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
            }else if(altaTrabajo(idTrab,trabajos,TAMTRAB,bicis,TAM,servicios,TAMS,tipos,TAMT,colores,TAMC))
            {
                idTrab++;
            }
            break;
        case 'i':
            mostrarTrabajos(trabajos,TAMTRAB,servicios,TAMS);
            break;
        case 'j':
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
