#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include "string.h"

stEmpleado cargarUnEmpleado(){

    stEmpleado e;
    printf("\n Ingrese apellido del empleado: ");
    fflush(stdin);
    gets(e.apellido);
    printf("\n Ingrese nombre del empleado: ");
    fflush(stdin);
    gets(e.nombre);
    printf("\n Ingrese el dni del empleado: ");
    fflush(stdin);
    gets(e.dni);
    printf("\n Ingrese el telefono del empleado: ");
    fflush(stdin);
    gets(e.telefono);
    printf("\n Ingrese el mail del empleado: ");
    fflush(stdin);
    gets(e.mail);
    return e;
}

void mostrarUnEmpleado(stEmpleado e){
    printf("\n id: %i", e.id);
    printf("\n Apellido: %s", e.apellido);
    printf("\n Nombre: %s", e.nombre);
    printf("\n DNI: %s", e.dni);
    printf("\n Telefono: %s", e.telefono);
    printf("\n Email: %s", e.mail);
    printf("\n------------------------");
}

stEmpleado buscarEmpleado (char archivo [], char usu[]){
    FILE * archi = fopen(archivo, "rb");
    int flag = 0;
    stEmpleado e;
    if(archi){

        while(fread(&e, sizeof(stEmpleado), 1, archi) > 0 ){
            if(strcmp(e.usuario, usu) == 0 && flag == 0 ){
            flag = 1;
            }
        }
    fclose(archi);
    }
    return e;
}
