#ifndef DIBUJA_H_INCLUDED
#define DIBUJA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void dibujaLogo(int x, int y);
void dibujaInicial();
void dibujaTitulo();

//Menus
void dibujaUsuariosInicial();
void dibujaMenuCliente();
void cuadradoCliente();
void cuadradoConsumos();
void cuadradoUsuario();
void dibujaTituloMenus(int x, int finx, int y, int finy, char titulo[]);

//Lineas
void dibujarLineaV(int x, int y, int yfin, char caract);
void dibujarLinea(int x, int xfin, int y, char caract);
//Formas
void dibujaCuadrado(int x, int finx, int y, int finy, int colorcito);
void dibujaCuadradoSombra(int x, int finx, int y, int finy, int colorcito);


#endif // DIBUJA_H_INCLUDED
