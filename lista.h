#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "empleado.h"

typedef struct{
    stEmpleado dato;
    struct nodo * siguiente;
} nodo;

nodo * iniciLista();
nodo * crearNodo(stEmpleado dato);
nodo* buscarUltimo(nodo* lista);
int buscarUltimoId(nodo * lista);
nodo * agregarAlFinal(nodo * lista, nodo * nuevo);
nodo * cargarListaEmpleado(nodo * lista);
void cargarArchivoEmpleado(char nombreArchivo[], nodo * lista);
nodo * archivoToLista(char archivo[], nodo * lista);

void mostrarLista(nodo * lista);
void mostrarUnNodo(nodo * n);

nodo * eliminarNodo(nodo * lista, int id);
nodo * encontrarNodo(nodo * lista, int id);
nodo * modificarUnDato(nodo * lista, int id);


#endif // LISTA_H_INCLUDED
