#include "nodoArbolCliente.h"

nodoArbolCliente * inicArbol()
{
    return NULL;
}

nodoArbolCliente *crearNodoArbol(stCliente dato)
{
    nodoArbolCliente *nuevo = (nodoArbolCliente*)malloc(sizeof(nodoArbolCliente));
    nuevo->der=NULL;
    nuevo->izq=NULL;
    nuevo->dato=dato;
    nuevo->consumos=NULL;
    nuevo->modificado=0;
    return nuevo;
}

nodoArbolCliente *agregarNodoArbol(nodoArbolCliente *arbol,stCliente dato)
{
    if(!arbol)
    {
        arbol=crearNodoArbol(dato);
    }
    else
    {
        if(dato.id> arbol->dato.id)
        {
            arbol->der=agregarNodoArbol(arbol->der,dato);
        }
        else
        {
            arbol->izq=agregarNodoArbol(arbol->izq,dato);
        }
    }
    return arbol;
}

void preOrden(nodoArbolCliente *arbol)
{
    if(arbol)
    {
        muestraCliente(arbol->dato);
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void inOrden(nodoArbolCliente *arbol)
{
    if(arbol)
    {
        inOrden(arbol->izq);
        muestraCliente(arbol->dato);
        inOrden(arbol->der);
    }
}

void posOrden(nodoArbolCliente *arbol)
{
    if(arbol)
    {
        posOrden(arbol->izq);
        posOrden(arbol->der);
        muestraCliente(arbol->dato);
    }
}

nodoArbolCliente *buscarClientePorId(nodoArbolCliente *arbol,int buscar)
{
    nodoArbolCliente *buscado=NULL;
    if(arbol)
    {


    if(arbol->dato.id == buscar)
    {
        buscado=arbol;
    }
    else
    {
        if(buscar >arbol->dato.id)
        {
            buscado=buscarClientePorId(arbol->der,buscar);
        }
        else
        {
            buscado=buscarClientePorId(arbol->izq,buscar);
        }
    }
    }
    return buscado;
}

nodoArbolCliente *array2Arbol(stCliente A[],int base,int tope)
{
    int medio;
    nodoArbolCliente *arbol=inicArbol();
    if(!(base>tope))
    {
        medio=(base+tope)/2;
        arbol=agregarNodoArbol(arbol,A[medio]);
        arbol->izq=array2Arbol(A,base,medio-1);
        arbol->der=array2Arbol(A,medio+1,tope);
    }
    return arbol;
}

void abrirArbol2Archi (char* ruta, nodoArbolCliente* arbol)
{
    FILE* archi = fopen(ruta, "r+b");

    if (archi)
    {
        arbol2Archi(arbol, archi);

        fclose(archi);
    }
}

void abrirArbol2destruye (char* ruta, nodoArbolCliente* arbol)
{
    FILE* archi = fopen(ruta, "wb+");

    if (archi)
    {
        cargaClienteEnArchivodestruye(arbol, archi);

        fclose(archi);
    }
}

void arbol2Archi(nodoArbolCliente* clients, FILE* clientsFile)
{
    stCliente cliente;
    if(clients)
    {
        arbol2Archi(clients->izq, clientsFile);
        if(clients->modificado)
        {
            cliente=clients->dato;
            cargaClienteEnArchivo(clientsFile,cliente);
        }
        arbol2Archi(clients->der, clientsFile);
    }
}

void cargaClienteEnArchivo(FILE *clientsFile, stCliente cliente)
{
    stCliente aux;
    int flag = 0;

    rewind(clientsFile);

    if (clientsFile)
    {
        while (!flag && fread(&aux, sizeof(stCliente), 1, clientsFile) > 0)
        {
            if (aux.id == cliente.id)
            {
                flag = 1;
            }
        }

        if (flag)
        {
            fseek(clientsFile, (-1) * sizeof(stCliente), SEEK_CUR);

            fwrite(&cliente, sizeof(stCliente), 1, clientsFile);
        }
        else
        {
            fwrite(&cliente, sizeof(stCliente), 1, clientsFile);
        }
    }
}

void cargaClienteEnArchivodestruye(nodoArbolCliente* clients, FILE* clientsFile)
{
    stCliente cliente;
    if(clients)
    {
        cargaClienteEnArchivodestruye(clients->izq, clientsFile);
        cliente=clients->dato;
        fwrite(&cliente,sizeof(stCliente),1,clientsFile);
        cargaClienteEnArchivodestruye(clients->der, clientsFile);
    }
}



nodoArbolCliente *buscaNodoMasDer(nodoArbolCliente *arbol)
{
    nodoArbolCliente *ultimo=NULL;
    if(arbol)
    {
        ultimo=buscaNodoMasDer(arbol->der);
    }
    if(!ultimo)
    {
        ultimo=arbol;
    }
    return ultimo;
}

nodoArbolCliente *buscaNodoMasIzq(nodoArbolCliente *arbol)
{
    nodoArbolCliente *ultimo=NULL;
    if(arbol)
    {
        ultimo=buscaNodoMasIzq(arbol->izq);
    }
    if(!ultimo)
    {
        ultimo=arbol;
    }
    return ultimo;
}

nodoArbolCliente *borrarNodo(nodoArbolCliente *arbol,int aBorrar)
{
    if(arbol)
    {
        if(aBorrar == arbol->dato.id)
        {
            if(arbol->izq)
            {
                nodoArbolCliente *ultimo=buscaNodoMasDer(arbol->izq);
                arbol->dato=ultimo->dato;
                arbol->izq=borrarNodo(arbol->izq,ultimo->dato.id);
            }
            else if(arbol->der)
            {
                nodoArbolCliente *ultimo=buscaNodoMasIzq(arbol->der);
                arbol->dato=ultimo->dato;
                arbol->der=borrarNodo(arbol->der,ultimo->dato.id);
            }
            else
            {
                free(arbol);
                arbol=NULL;
            }
        }
        else
        {
            if(aBorrar > arbol->dato.id)
            {
                arbol->der=borrarNodo(arbol->der,aBorrar);
            }
            else
            {
                arbol->izq=borrarNodo(arbol->izq,aBorrar);
            }
        }
    }
    return arbol;

}
void arbol2Array(nodoArbolCliente* arbol, stCliente c[], int *v, int dim)
{
    if (arbol && *v < dim)
    {
        c[*v] = arbol->dato;
        *v += 1;
        arbol2Array(arbol->izq, c, v, dim);
        arbol2Array(arbol->der, c, v, dim);
    }
}

void muestraNodo(nodoArbolCliente *arbol)
{
    if(arbol)
    {
        muestraCliente(arbol->dato);
        /// muestraConsumos(arbol->consumos);
    }
}

nodoArbolCliente * buscaClientePorNombre(nodoArbolCliente * arbol,char nombre[],char apellido[])
{
    nodoArbolCliente *aux= NULL;
    if(arbol)
    {
        if(strcmpi(apellido,arbol->dato.apellido)==0 && strcmpi(nombre,arbol->dato.nombre==0))
        {
            aux=arbol;
        }
        else
        {
            aux=buscaClientePorNombre(arbol->izq,nombre,apellido);
            if(!aux)
            {
                aux=buscaClientePorNombre(arbol->der,nombre,apellido);
            }
        }
    }
    return aux;
}

nodoArbolCliente * buscaClientePorNroCliente(nodoArbolCliente *arbol,int aBuscar)
{
    nodoArbolCliente *aux = NULL;
    if(arbol)
    {
        if(aBuscar == arbol->dato.nroCliente)
        {
            aux=arbol;
        }
        else
        {
            aux=buscaClientePorNroCliente(arbol->izq,aBuscar);
            if(!aux)
            {
                aux=buscaClientePorNroCliente(arbol->der,aBuscar);
            }
        }
    }
    return aux;
}

void insertarCliente(stCliente c[],int ultVal,stCliente dato)
{
    int i=ultVal;
    while(i>=0 && dato.id<c[i].id)
    {
        c[i+1]=c[i];
        i--;
    }
    c[i+1]=dato;
}

void OrdenacionClientes(stCliente c[],int validos)
{
    int i=0;
    while(i<validos-1)
    {
        insertarCliente(c,i,c[i+1]);
        i++;
    }
}

int arch2array(stCliente c[],int dim)
{
    char cli[]= {"clientesNuevo.dat"};
    FILE *archi=fopen(cli,"rb");
    int i=0;
    stCliente p;
    if(archi)
    {
        while(fread(&p,sizeof(stCliente),1,archi)>0 && i<dim)
        {
            c[i]=p;
            i++;
        }
        fclose(archi);
    }
    return i;
}

int devuelveUltId(nodoArbolCliente *arbol)
{
    int rta=0,dato=0;
    if(arbol)
    {
        dato=arbol->dato.id;
        if(arbol->der)
        {
            rta=devuelveUltId(arbol->der);
        }
        if(dato>rta)
        {
            rta=dato;
        }
    }
    return rta;
}
