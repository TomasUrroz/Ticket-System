#include "complemento.h"

int controlEnXInicial()
{
    int opcion =0, rta =3;
    char c;
    dibujaCuadradoGordo(11,36,5,9,7);
    do
    {
        c=getch();
        switch(c)
        {
        case TECLADER:
            if(opcion <2)
            {
                opcion++;
                if(opcion == 1)
                {
                    dibujaCuadrado(11,36,5,9,1);
                    dibujaCuadradoGordo(46,71,5,9,7);
                }
                else
                {
                    dibujaCuadrado(46,71,5,9,1);
                    dibujaCuadradoGordo(83,108,5,9,7);
                }
            }
            break;
        case TECLAIZQ:
            if(opcion >0)
            {
                opcion--;
                if(opcion == 1)
                {
                    dibujaCuadrado(83,108,5,9,1);
                    dibujaCuadradoGordo(46,71,5,9,7);
                }
                else
                {
                    dibujaCuadrado(46,71,5,9,1);
                    dibujaCuadradoGordo(11,36,5,9,7);
                }
            }
            break;
        case ENTER:

            rta = opcion;
            break;
        case ESC:

            rta = 4;
            break;
        }

    }
    while(rta == 3);

    return rta;

}

int control(int supx, int supy, int opciones)
{
    int x=supx, y=supy;
    char c=0;
    int respuesta=0; //este valor es el valor de y al apretar enter

    gotoxy(x,y);
    printf("%c",15);

    do
    {
        fflush(stdin);
        c=getch();
        switch(c)
        {
        case TECLAARR:
            if(y>supy)    //arriba
            {
                gotoxy(x,y);
                printf("  "); //borro el cursor
                y=y-2;
                gotoxy(x,y);
                printf("%c",15);
            }
            break;
        case TECLAABJ:
            if(y<supy+(opciones-1)*2)    //abajo
            {
                gotoxy(x,y);
                printf("  ");  //borro el cursor
                y=y+2;
                gotoxy(x,y);
                printf("%c",15);
            }
            break;
        case ENTER:

            gotoxy(x,y);    //enter
            printf("%c",15); // lo muestro en otro color
            gotoxy(x,y);
            printf("  ");  //borro el cursor
            y=y-(supy-1);
            respuesta=y;
        }

    }
    while(respuesta==0);

    return respuesta;

}
