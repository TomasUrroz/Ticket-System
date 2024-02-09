#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct {
    int id;
    char apellido [20];
    char nombre[20];
    char dni[10];
    char telefono [12];
    char mail [45];
    int rol;
    int nuevo;
    int modificado;
    char usuario [20];
    char password[20];
}stEmpleado;

stEmpleado cargarUnEmpleado();
void mostrarUnEmpleado(stEmpleado e);
stEmpleado buscarEmpleado (char archivo [], char usu[]);


#endif // EMPLEADO_H_INCLUDED
