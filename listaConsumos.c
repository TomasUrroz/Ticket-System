#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


#include "listaConsumos.h"



nodoListaConsumo* inicLista()
{
    return NULL;
}




nodoListaConsumo* nuevo_nodo_consumo (stConsumo c)
{
    nodoListaConsumo* nuevoNodo = (nodoListaConsumo*) malloc(sizeof(nodoListaConsumo));

    nuevoNodo->dato = c;

    nuevoNodo->siguiente = inicLista();

    return nuevoNodo;
}





nodoListaConsumo* agregarAlPpio (nodoListaConsumo* consumos, nodoListaConsumo* nuevoConsumo)
{
    nuevoConsumo->siguiente = consumos;

    return nuevoConsumo;
}



nodoListaConsumo* busca_consumo_por_fecha (nodoListaConsumo* consumos, char* fecha)
{
    nodoListaConsumo* buscar = inicLista();

    if(consumos){
        char fechaActual[15];

        sprintf(fechaActual, "%d%d%d", consumos->dato.dia, consumos->dato.mes, consumos->dato.anio);

        while (!buscar && consumos)
            {
            if (atoi(fecha) == atoi(fechaActual))
                {
                buscar = consumos;
                }

            consumos = consumos->siguiente;

            sprintf(fechaActual, "%d%d%d", consumos->dato.dia, consumos->dato.mes, consumos->dato.anio);
            }
        }
    return buscar;
}



void buscar_consumo_por_fecha (nodoListaConsumo* consumos)
{
    stConsumo c;
    nodoListaConsumo* buscar = inicLista();

    printf("Ingrese el dia: ");
    scanf("%d", &c.dia);
    system("cls");

    printf("Ingrese el mes: ");
    scanf("%d", &c.mes);
    system("cls");

    printf("Ingrese el ano: ");
    scanf("%d", &c.anio);
    system("cls");

    char fecha[15];

    sprintf(fecha, "%d%d%d", c.dia, c.mes, c.anio);

    buscar = busca_consumo_por_fecha(consumos, fecha);

    if (buscar)
        {
        printf("El consumo existe");
        }else
        {
        printf("El consumo no existeeee");
        }
}





nodoListaConsumo* carga_consumo_por_fecha (nodoListaConsumo* consumos, nodoListaConsumo* nuevoConsumo)
{
    if (!consumos)
        {
        consumos = nuevoConsumo;
        }
    else
        {
        char fechaActual[15];
        char fechaNuevo[15];

        sprintf(fechaActual, "%d%d%d", consumos->dato.dia, consumos->dato.mes, consumos->dato.anio);
        sprintf(fechaNuevo, "%d%d%d", nuevoConsumo->dato.dia, nuevoConsumo->dato.mes, nuevoConsumo->dato.anio);

        if (atoi(fechaActual) <= atoi(fechaNuevo))
            {
            consumos = agregarAlPpio(consumos, nuevoConsumo);
            }
        else
            {
            nodoListaConsumo* prev = consumos;
            nodoListaConsumo* next = consumos->siguiente;

            sprintf(fechaActual, "%d%d%d", next->dato.dia, next->dato.mes, next->dato.anio);

            while (atoi(fechaActual) < atoi(fechaNuevo))
                {
                prev = next;
                next = next->siguiente;

                sprintf(fechaActual, "%d%d%d", next->dato.dia, next->dato.mes, next->dato.anio);
                }

            prev->siguiente = nuevoConsumo;
            nuevoConsumo->siguiente = next;
            }
        }


    return consumos;
}



nodoListaConsumo* consumo_en_fecha(nodoListaConsumo* lista, char* fecha)
{
    char fechaActual[15];
    nodoListaConsumo* buscar = inicLista();

    while (!buscar && lista)
        {
        sprintf(fechaActual, "%d%d%d", lista->dato.dia, lista->dato.mes, lista->dato.anio);

        if (atoi(fecha) == atoi(fechaActual))
            {
            buscar = lista;
            }

        lista = lista->siguiente;
        }

    return buscar;
}




nodoListaConsumo* trash_list (nodoListaConsumo* consumos)
{
    nodoListaConsumo* trash = inicLista();

    while (consumos)
        {
        trash = consumos;

        consumos = consumos->siguiente;

        free(trash);
        }

    return consumos;
}
