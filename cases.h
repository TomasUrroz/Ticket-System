#ifndef CASES_H_INCLUDED
#define CASES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "lista.h"
#include "nodoArbolCliente.h"
#include "dibuja.h"
#include "complemento.h"

#define ARCHIVOCLIENTES "clientesNuevo.dat"

//ADENTRO DE CASES TIENEN QUE ESTAR INCLUIDOS LOS EMPLEADOS






void caseMenu(stEmpleado empleado);

nodoArbolCliente * caseConsumo(stEmpleado empleado, nodoArbolCliente * arbol);
nodoArbolCliente * cargaConsumo(int x, int y, nodoArbolCliente * cliente);

void caseUsuario(stEmpleado empleado);

//Case de clientes
nodoArbolCliente * caseCliente(stEmpleado empleado,nodoArbolCliente *arbol);
void cargaCliente(int x, int y, nodoArbolCliente * arbol);
nodoArbolCliente * modificaCliente(int x, int y, nodoArbolCliente* arbol);
nodoArbolCliente * editorDeCliente(int x, int y, nodoArbolCliente * cliente);
nodoArbolCliente * altaBajaCliente(int x, int y, nodoArbolCliente * arbol);
nodoArbolCliente * destruyeCliente(int x, int y, nodoArbolCliente * arbol);

//Titulin y si el empleado es admin arriba a la derecha
void empleadoYRol(stEmpleado empleado);

#endif // CASES_H_INCLUDED
