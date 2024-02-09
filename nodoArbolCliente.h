#ifndef NODOARBOLCLIENTE_H_INCLUDED
#define NODOARBOLCLIENTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "listaConsumos.h"



typedef struct _nodoArbolCliente{
	stCliente dato;
    int modificado;
	nodoListaConsumo* consumos;
	struct _nodoArbolCliente* izq;
	struct _nodoArbolCliente* der;
}nodoArbolCliente;

nodoArbolCliente *inicArbol();
nodoArbolCliente *crearNodoArbol(stCliente dato);
nodoArbolCliente *agregarNodoArbol(nodoArbolCliente *arbol,stCliente dato);
void muestraNodo(nodoArbolCliente *arbol);

void preOrden(nodoArbolCliente *arbol);
void inOrden(nodoArbolCliente *arbol);
void posOrden(nodoArbolCliente *arbol);

void abrirArbol2Archi (char* ruta, nodoArbolCliente* arbol);
void arbol2Archi(nodoArbolCliente* clients, FILE* clientsFile);
void cargaClienteEnArchivo(FILE *clientsFile, stCliente cliente);

nodoArbolCliente * arreglo2ArbolCliente(stCliente A[],int validos);
stCliente buscaClienteEnArchivo(FILE *clientsFile,int id);
nodoArbolCliente * buscaClientePorNroCliente(nodoArbolCliente *arbol,int aBuscar);

nodoArbolCliente *borrarNodo(nodoArbolCliente *arbol,int aBorrar);
nodoArbolCliente *buscaNodoMasIzq(nodoArbolCliente *arbol);
nodoArbolCliente *buscaNodoMasDer(nodoArbolCliente *arbol);
nodoArbolCliente *buscarClientePorId(nodoArbolCliente *arbol,int buscar);

int archi2ArrayOrdenado(stCliente A[],int dim);
nodoArbolCliente *array2Arbol(stCliente a[],int base,int tope);
void arbol2Array(nodoArbolCliente* arbol, stCliente c[], int *v, int dim);
int devuelveUltId(nodoArbolCliente *arbol);
#endif // NODOARBOLCLIENTE_H_INCLUDED
