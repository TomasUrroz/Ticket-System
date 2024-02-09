#include "dibuja.h"

void dibujarLinea(int x, int xfin, int y, char caract)
{
    if(x<xfin)
    {
        while(x!=xfin)
        {
            gotoxy(x,y);
            printf("%c",caract);
            x++;
        }
    }
    else
    {
        while(x!=xfin)
        {
            gotoxy(x,y);
            printf("%c",caract);
            x--;
        }
    }
}

void dibujarLineaV(int x, int y, int yfin, char caract)
{
    if(y<yfin)
    {
        while(y!=yfin)  ///pinta de arriba a abajo
        {
            gotoxy(x,y);
            printf("%c",caract);
            y++;
        }
    }
    else
    {
        while(y!=yfin)  ///pinta de abajo a arriba
        {
            gotoxy(x,y);
            printf("%c",caract);
            y--;
        }
    }
}

void dibujaCuadrado(int x, int finx, int y, int finy, int colorcito)
{
    color(colorcito);
    gotoxy(x,y);
    printf("%c",218);
    dibujarLinea(x+1,finx,y,196);
    dibujarLineaV(x,y+1,finy,179);
    gotoxy(x,finy);
    printf("%c", 192);
    dibujarLinea(x+1,finx,finy,196);
    gotoxy(finx,finy);
    printf("%c",217);
    dibujarLineaV(finx,finy-1,y,179);
    gotoxy(finx,y);
    printf("%c",191);

}

void dibujaTitulo()
{
    int x=20,y=0, finx= 95, finy=7;

    dibujaLogo(x,y+1);
    dibujaCuadradoSombra(x,finx,y,finy,1);

}

void dibujaCuadradoSombra(int x, int finx, int y, int finy, int colorcito)
{
    color(colorcito);
    gotoxy(x,y);
    printf("%c",218);
    gotoxy(x+1,y+1);
    dibujarLinea(x+1,finx,y,196);
    dibujarLineaV(x,y+1,finy,179);
    gotoxy(x,finy);
    printf("%c", 192);
    dibujarLinea(x+1,finx,finy,205);
    gotoxy(finx,finy);
    printf("%c",188);
    dibujarLineaV(finx,finy-1,y,186);
    gotoxy(finx,y);
    printf("%c",191);
}

void dibujaCuadradoGordo(int x, int finx, int y, int finy, int colorcito)
{
    color(colorcito);
    gotoxy(x,y);
    printf("%c",201);
    gotoxy(x+1,y+1);
    dibujarLinea(x+1,finx,y,205);
    dibujarLineaV(x,y+1,finy,186);
    gotoxy(x,finy);
    printf("%c", 200);
    dibujarLinea(x+1,finx,finy,205);
    gotoxy(finx,finy);
    printf("%c",188);
    dibujarLineaV(finx,finy-1,y,186);
    gotoxy(finx,y);
    printf("%c",187);
}
void dibujaLogo(int x, int y)
{
    gotoxy(x,y);
    printf("      ____                                   _____           ____   __     \n");
    y++;
    gotoxy(x,y);
    printf("     / __ \\  ____  _      __  ___    _____  / ___/  ____    / __/  / /_    \n");
    y++;
    gotoxy(x,y);
    printf("    / /_/ / / __ \\| | /| / / / _ \\  / ___/  \\__ \\  / __ \\  / /_   / __/    \n");
    y++;
    gotoxy(x,y);
    printf("   / ____/ / /_/ /| |/ |/ / /  __/ / /     ___/ / / /_/ / / __/  / /_      \n");
    y++;
    gotoxy(x,y);
    printf("  /_/      \\____/ |__/|__/  \\___/ /_/     /____/  \\____/ /_/     \\__/      \n");
}

void dibujaUsuariosInicial()
{
    dibujaCuadrado(42,80,10,18,1);

    gotoxy(48,12);
    printf("Usuario: ");
    gotoxy(48,14);
    printf("Contrase%ca: ",164);
    gotoxy(48,16);
    printf("Entrar");

}

void dibujaInicial()
{
    dibujaTitulo();
    dibujaUsuariosInicial();

}



void limpia(int iniX, int finX, int iniY, int finY)
{
    int x= iniX, y = iniY;
    while(x<finX)
    {
        while(y<finY)
        {
            gotoxy(x,y);
            printf(" ");
            y++;
        }
        y=iniY;
        gotoxy(x,y);
        printf(" ");
        x++;
    }

}
void dibujaMenuCliente()
{
    dibujaCuadrado(0,118,0,25,1);
    cuadradoCliente();
    cuadradoConsumos();
    cuadradoUsuario();
}

void cuadradoCliente()
{
    dibujaCuadrado(11,36,5,9,1);
    gotoxy(20,7);
    printf("Clientes");
}

void cuadradoConsumos()
{
    dibujaCuadrado(46,71,5,9,1);
    gotoxy(55,7);
    printf("Consumos");
}

void cuadradoUsuario()
{
    dibujaCuadrado(83,108,5,9,1);
    gotoxy(88,7);
    printf("Edicion Usuario");
}

void dibujaTituloMenus(int x, int finx, int y, int finy, char titulo[])
{
    dibujaCuadrado(x,finx,y,finy,1);
    gotoxy(x+4,y+1);
    printf("%s", titulo);
    gotoxy(x,y);
    printf("%c",194);
    gotoxy(finx,y);
    printf("%c",194);

}
