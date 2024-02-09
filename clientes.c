#include <stdlib.h>
#include <stdio.h>
#include "clientes.h"

int arch2arreglo(char nombreArchivo[], stCliente e[], int dim, int v){
    FILE *archi = fopen(nombreArchivo, "rb");
    if(archi){
        while(v<dim && fread(&e[v], sizeof(stCliente), 1, archi) > 0){
            v++;
        }
        fclose(archi);
    }
    return v;
}

