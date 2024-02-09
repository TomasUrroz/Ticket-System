#ifndef LISTACONSUMOS_H_INCLUDED
#define LISTACONSUMOS_H_INCLUDED


#include "consumos.h"


typedef struct _nodoListaConsumo
{
	stConsumo dato;
    int modificado;    /// 0 si no se modifico
	struct _nodoListaConsumo* siguiente;
}nodoListaConsumo;



nodoListaConsumo* inicLista();
nodoListaConsumo* nuevo_nodo_consumo (stConsumo c);
nodoListaConsumo* agregarAlPpio (nodoListaConsumo* consumos, nodoListaConsumo* nuevoConsumo);
nodoListaConsumo* busca_consumo_por_fecha (nodoListaConsumo* consumos, char* fecha);
void buscar_consumo_por_fecha (nodoListaConsumo* consumos);
nodoListaConsumo* carga_consumo_por_fecha (nodoListaConsumo* consumos, nodoListaConsumo* nuevoConsumo);
nodoListaConsumo* consumo_en_fecha(nodoListaConsumo* lista, char* fecha);
nodoListaConsumo* trash_list (nodoListaConsumo* consumos);



#endif // LISTACONSUMOS_H_INCLUDED
