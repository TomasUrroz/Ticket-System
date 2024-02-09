#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

nodo * iniciLista(){
    return NULL;
}

nodo * crearNodo(stEmpleado dato){
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

nodo* buscarUltimo(nodo* lista){
    nodo* ultimo = lista;
    while(ultimo->siguiente != NULL){
        ultimo = ultimo->siguiente;
    }
    return ultimo;
}

int buscarUltimoId(nodo * lista){
    int id = 0;
    nodo * ultimo = lista;
    ultimo = buscarUltimo(lista);
    id = ultimo->dato.id;
    return id;
}

nodo * agregarAlFinal(nodo * lista, nodo * nuevo){
    if(!lista){
        lista = nuevo;
    }
    else{
        nodo * aux = lista;
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
    return lista;
}

nodo * cargarListaEmpleado(nodo * lista){
    stEmpleado e;
    char opcion;
    nodo * nuevo = crearNodo(e);
    int id = 0;
    do{
        id = buscarUltimoId(lista);
        e.id = id;
        e.nuevo = 1;
        e = cargarUnEmpleado();
        agregarAlFinal(lista, nuevo);
        ///MENU CARGAR EMPLEADO
        printf("SEGUIR CARGANDO EMPLEADOS?");
        printf("ESC PARA SALIR O CUALQ. TECLA PARA CONTINUAR");
        printf("\n\t\t\t\t\t\t\t\t");
        opcion = getch();
        system("cls");
        }
        while(opcion!= 27);
    return lista;
}

void cargarArchivoEmpleado(char nombreArchivo[], nodo * lista){

    FILE *archiEmpleados = fopen(nombreArchivo, "ab");
    stEmpleado e;
    int id = 0;

    if(archiEmpleados)
    {
        while(lista  && lista->dato.nuevo == 1){
            lista->dato.nuevo = 0;
            fwrite(&e,sizeof(stEmpleado), 1, archiEmpleados);
        }
    fclose(archiEmpleados);
    }
}

nodo * archivoToLista(char archivo[], nodo * lista){
    FILE * archiEmpleados = fopen(archivo, "rb");
    stEmpleado e;
    if(archiEmpleados){
        while(fread(&e, sizeof(stEmpleado), 1, archiEmpleados) > 0){
        lista = agregarAlFinal(lista, crearNodo(e));
        fclose(archiEmpleados);
        }
    }
    return lista;
}

void mostrarLista(nodo * lista){
    nodo * aux = lista;
    while(aux != NULL){
        mostrarUnNodo(aux);
        aux = aux->siguiente;
    }
}

void mostrarUnNodo(nodo * n){
    printf("\n nodo: %p", n);
    mostrarUnEmpleado(n->dato);
}

nodo * eliminarNodo(nodo * lista, int id){
    nodo * anterior;
    nodo * siguiente;
    if(lista && lista->dato.id == id){
            nodo * aux = lista;
            lista = lista->siguiente;
            free(aux);
    }
    else{
            siguiente = lista;
            while(siguiente && siguiente->dato.id != id){
                anterior = siguiente;
                siguiente = siguiente->siguiente;
            }
            if(siguiente){
                anterior->siguiente = siguiente->siguiente;
                free(siguiente);
            }
        }
    return lista;
}

nodo * encontrarNodo(nodo * lista, int id){
    nodo * aux = lista;
    while(aux){
        if(aux->dato.id == id){
            mostrarUnEmpleado(aux->dato);
        }
        aux = aux->siguiente;
    }
    return aux;
}

nodo * modificarUnDato(nodo * lista, int id){
    int opcion;
    nodo * aux = lista;
    encontrarNodo(aux, id);
    if(aux->dato.id == id){
        printf("\n Ingrese la opcion que desea modificar:");
        printf("\n 1: modificar nombre");
        printf("\n 2: modificar apellido");
        printf("\n 3: modificar dni");
        printf("\n 4: modificar mail");
        printf("\n 5: modificar telefono");
        switch(opcion){
            case 1: printf("\n Ingrese nuevo nombre:");
            fflush(stdin);
            gets(aux->dato.nombre);
            aux->dato.nuevo = 1;
            break;
            case 2: printf("\n Ingrese nuevo apellido:");
            fflush(stdin);
            gets(aux->dato.apellido);
            aux->dato.nuevo = 1;
            break;
            case 3: printf("\n Ingrese nuevo dni:");
            fflush(stdin);
            gets(aux->dato.dni);
            aux->dato.nuevo = 1;
            break;
            case 4: printf("\n Ingrese nuevo telefono:");
            fflush(stdin);
            gets(aux->dato.telefono);
            aux->dato.nuevo = 1;
            break;
            case 5: printf("\n Ingrese nuevo nombre:");
            fflush(stdin);
            gets(aux->dato.nombre);
            aux->dato.nuevo = 1;
            break;
            default: printf("\n Opcion incorrecta");
            ///NO CAMBIO EL DATO "nuevo" porque no hay nada que cambiar.
        }
    }
}

