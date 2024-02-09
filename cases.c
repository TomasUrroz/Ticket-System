#include "cases.h"



void empleadoYRol(stEmpleado empleado)
{
    gotoxy(4,1);
    color(7);
    printf("%s %s", empleado.apellido, empleado.nombre);
    if(empleado.rol == 1)
    {
        gotoxy(94,1);
        printf("Modo administrador");

    }
    color(1);

}

void caseMenu(stEmpleado empleado)
{
    int opcion, fin =0, v=0, dim=100;

    stCliente clientes[dim];
    v = arch2array(clientes,dim);
    OrdenacionClientes(clientes,v);

    nodoArbolCliente * arbol = inicArbol();
    arbol = array2Arbol(clientes,0,v);

    do
    {
        empleadoYRol(empleado);

        dibujaMenuCliente();
        opcion = controlEnXInicial();
        switch(opcion)
        {
        case 0:
            arbol =caseCliente(empleado,arbol);
            limpia(11,40,10,26);
            dibujaCuadrado(11,36,5,9,1);
            abrirArbol2Archi(ARCHIVOCLIENTES,arbol);
            break;

        case 1:
            caseConsumo(empleado, arbol);
            limpia(46,73,10,20);
            dibujaCuadrado(46,71,5,9,1);
            abrirArbol2Archi(ARCHIVOCLIENTES,arbol);

            break;

        case 2:
            caseUsuario(empleado);
            limpia(83,109,10,20);
            dibujaCuadrado(83,108,5,9,1);
            abrirArbol2Archi(ARCHIVOCLIENTES,arbol);

            break;

        case 3:
            fin = 3;
            //Case pa tra
            break;
        }
    }
    while(fin !=3);

}





/*-------------------------------CLIETES-------------------------------*/

nodoArbolCliente * caseCliente(stEmpleado empleado, nodoArbolCliente * arbol)
{
    int x=16, y=9, opcion=0;
    limpia(11,36,9,9);

    do
    {
        dibujaMenuCliente();
        limpia(11,36,9,23);
        dibujaCuadradoGordo(11,36,5,23,7);
        color(3);
        gotoxy(x,y);
        printf("Ingresar cliente");
        gotoxy(x,y+2);
        printf("Mostrar lista");
        gotoxy(x,y+4);
        printf("Buscar cliente");
        gotoxy(x,y+6);
        printf("Modificar cliente");
        gotoxy(x,y+8);
        printf("Alta/baja cliente");
        gotoxy(x,y+10);
        printf("Elimina cliente");
        gotoxy(x,y+12);
        printf("Salir");

        opcion = control(14,9,7);
        switch(opcion)
        {
        case 1:

            limpia(3,117,3,26);
            cargaCliente(x,y,arbol);
            limpia(15,71,4,23,1);
            limpia(49,80,0,4);
            dibujarLinea(49,80,0,196);

            break;

        case 3:

            limpia(3,117,3,26);
            mostrarArrayCliente(x,y, arbol);
            dibujaCuadrado(0,118,0,25,1);
            empleadoYRol(empleado);

            break;

        case 5:
            limpia(3,117,3,26);
            buscaClientes(x-10,y,arbol);
            limpia(2,71,4,23,1);
            limpia(46,85,0,4);
            dibujarLinea(49,80,0,196);

            break;

        case 7:
            limpia(3,117,3,26);
            arbol = modificaCliente(x-10,y,arbol);
            limpia(2,71,4,23,1);
            limpia(46,85,0,4);
            dibujarLinea(49,80,0,196);
            break;

        case 9:
            arbol = altaBajaCliente(x,y,arbol);
            limpia(2,71,4,26,1);
            limpia(46,85,0,4);
            dibujarLinea(49,80,0,196);

            break;

        case 11:
            arbol = destruyeCliente(x,y,arbol);
            abrirArbol2destruye(ARCHIVOCLIENTES,arbol);
            limpia(2,71,4,26,1);
            limpia(46,85,0,4);
            dibujarLinea(49,80,0,196);
            break;

        case 13:
            //chota de oso
            break;
        }
    }
    while(opcion !=13);
    return arbol;
}

void cargaCliente(int x, int y, nodoArbolCliente * arbol)
{
    dibujaTituloMenus(49,74,0,2,"Creador de cliente");
    dibujaCuadrado(15,70,6,22,1);

    int auxY = -2, opcion, opcion2 =0;
    stCliente nuevo;

    gotoxy(x+4,y+auxY);
    auxY +=2;
    printf("Numero de cliente: ");

    gotoxy(x+4,y+auxY);
    printf("Nombre: ");

    auxY +=2;
    gotoxy(x+4,y+auxY);
    printf("Apellido: ");

    auxY +=2;
    gotoxy(x+4,y+auxY);
    printf("DNI: ");

    auxY +=2;
    gotoxy(x+4,y+auxY);
    printf("Email: ");

    auxY +=2;
    gotoxy(x+4,y+auxY);
    printf("Domicilio: ");

    auxY +=2;
    gotoxy(x+4,y+auxY);
    printf("Telefono: ");

    auxY +=2;
    gotoxy(x+4,y+auxY);
    printf("Aceptar");


    do
    {
        opcion = control(x,y-2,8);
        switch(opcion)
        {
        case 1:
            limpia(x+22,x+40,y-2,y-2);
            gotoxy(x+22,y-2);
            hidecursor(1);
            color(11);
            scanf("%i",&nuevo.nroCliente);
            color(1);
            hidecursor(0);
            break;

        case 3:
            limpia(x+11,x+40,y,y);
            gotoxy(x+11,y);
            hidecursor(1);
            color(11);
            fflush(stdin);
            gets(nuevo.nombre);
            color(1);
            hidecursor(0);
            break;

        case 5:
            limpia(x+13,x+40,y+2,y+2);
            gotoxy(x+13,y+2);
            hidecursor(1);
            color(11);
            fflush(stdin);
            gets(nuevo.apellido);
            color(1);
            hidecursor(0);
            break;

        case 7:
            limpia(x+8,x+40,y+4,y+4);
            gotoxy(x+8,y+4);
            hidecursor(1);
            color(11);
            fflush(stdin);
            gets(nuevo.dni);
            color(1);
            hidecursor(0);
            break;
        case 9:
            limpia(x+10,x+40,y+6,y+6);
            gotoxy(x+10,y+6);
            hidecursor(1);
            color(11);
            fflush(stdin);
            gets(nuevo.email);
            color(1);
            hidecursor(0);
            break;
        case 11:
            limpia(x+14,x+40,y+8,y+8);
            gotoxy(x+14,y+8);
            hidecursor(1);
            color(11);
            fflush(stdin);
            gets(nuevo.domicilio);
            color(1);
            hidecursor(0);
            break;
        case 13:
            limpia(x+13,x+40,y+10,y+10);
            gotoxy(x+13,y+10);
            hidecursor(1);
            color(11);
            fflush(stdin);
            gets(nuevo.telefono);
            color(1);
            hidecursor(0);
            break;
        case 15:
            dibujaCuadrado(71,90,6,13,1);
            gotoxy(74,7);
            printf("Desea cargarlo?");
            gotoxy(80,9);
            printf("No");
            gotoxy(80,11);
            printf("Si");
            opcion2=control(78,9,2);
            limpia(71,91,5,14);
            break;
        }
    }
    while(opcion2 !=3 );
    arbol = agregarNodoArbol(arbol, nuevo);
}

void mostrarArrayCliente(int x, int y, nodoArbolCliente * arbol)
{
    limpia(0,118,25,25);
    int posX =0, posY =0, i=1, v=0, dim=100;

    stCliente clientes[100];
    arbol2Array(arbol,clientes,&v,dim);
    OrdenacionClientes(clientes,v);

    char c = 0;

    do
    {
        while(i<v)
        {
            while(posX <3 && i<v)
            {
                if(posX ==0)
                {
                    muestraCliente(x-2,y+posY, clientes[i]);
                }
                else if(posX ==1)
                {
                    muestraCliente(x+36,y+posY, clientes[i]);
                }
                else if(posX ==2)
                {
                    muestraCliente(x+74,y+posY, clientes[i]);
                }
                posX++;
                i++;
            }
            posX=0;
            posY+=15;
        }
        gotoxy(0,0);
        dibujaCuadrado(0,118,0,posY+6,1);
        dibujaTituloMenus(49,74,0,2,"Lista de clientes");

        color(7);
        gotoxy(114,1);
        printf("ESC");
        color(1);
        dibujarLinea(113,118,2,196);
        dibujarLineaV(112,1,2,179);

        gotoxy(112,2);
        printf("%c",192);

        gotoxy(112,0);
        printf("%c",194);

        gotoxy(118,2);
        printf("%c",180);

        c =getch();
    }
    while(c !=27);

    system("cls");

}

void muestraCliente(int x, int y, stCliente cliente)
{
    dibujaCuadrado(x-9,x+26,y-5, y+7,1);
    dibujarLinea(x-8,x+26,y-3,196);

    dibujaCuadrado(x-9,x+26,y-5,y-3,1);

    gotoxy(x-7,y-4);

    //CLAVAR DATOS NICO
    printf("%s %s", cliente.nombre, cliente.apellido);

    gotoxy(x-9,y-3);
    printf("%c",195);
    gotoxy(x+26,y-3);
    printf("%c",180);


    gotoxy(x-7,y-2);
    printf("ID: %i", cliente.id);

    gotoxy(x-7,y-1);
    printf("Numero de cliente: %i", cliente.nroCliente);

    gotoxy(x-7,y);
    printf("Nombre: %s", cliente.nombre);

    gotoxy(x-7,y+1);
    printf("Apellido: %s", cliente.apellido);

    gotoxy(x-7,y+2);
    printf("DNI: %s", cliente.dni);

    gotoxy(x-7,y+3);
    printf("Email: %s", cliente.email);

    gotoxy(x-7,y+4);
    printf("Domicilio: %s", cliente.domicilio);

    gotoxy(x-7,y+5);
    printf("Telefono: %s", cliente.telefono);

    gotoxy(x-7,y+6);
    printf("Eliminado: %i", cliente.eliminado);
}

void buscaClientes(int x, int y, nodoArbolCliente* arbol)
{
    nodoArbolCliente * encontrado = NULL;
    int opcion, busca=-1;
    char nombre[20], apellido[20], c;
    dibujaTituloMenus(48,74,0,2,"Buscador de clientes");

    gotoxy(x,y-4);
    printf("Buscar por ID:");
    gotoxy(x,y-2);
    printf("Buscar por numero de cliente:");
    gotoxy(x,y);
    printf("Buscar por nombre y apellido:");
    gotoxy(x,y+2);
    printf("Salir");

    do
    {
        limpia(x+15,x+20,y-4,y-4);
        limpia(x+30,x+40,y-2,y-2);
        limpia(x+30,x+40,y,y);
        dibujaCuadrado(3,70,4,12,1);
        opcion = control(x-2,y-4,4);
        switch(opcion)
        {
        case 1:
            limpia(x+15,x+20,y-4,y-2);
            gotoxy(x+15,y-4);
            hidecursor(1);
            color(11);
            scanf("%i",&busca);
            color(1);
            hidecursor(0);
            if(busca <= devuelveUltId(arbol))
            {
                encontrado = buscarClientePorId(arbol, busca);
                if(encontrado)
                {
                    muestraCliente(x+80,y,encontrado->dato);
                    c = getch();

                }
                else if(!encontrado)
                {
                    dibujaCuadrado(80,115,4, 7,1);
                    gotoxy(84,5);
                    printf("No existe cliente con esa ID!");
                    c = getch();
                }
            }
            else
            {
                dibujaCuadrado(80,115,4, 7,1);
                gotoxy(84,5);
                printf("No existe cliente con esa ID!");
                c = getch();
            }
            limpia(x+60,x+110,y-5,y+10);

            break;

        case 3:
            limpia(x+30,x+20,y,y);
            gotoxy(x+30,y-2);
            hidecursor(1);
            color(11);
            scanf("%i",&busca);
            color(1);
            hidecursor(0);

            encontrado = buscaClientePorNroCliente(arbol, busca);
            if(encontrado)
            {
                muestraCliente(x+80,y,encontrado->dato);
                c = getch();

            }
            else
            {
                dibujaCuadrado(80,115,4, 7,1);
                gotoxy(82,5);
                printf("No existe el numero de cliente!");
                c = getch();
            }
            limpia(x+60,x+110,y-5,y+10);

            break;

        case 5:
            limpia(x+30,x+20,y,y);
            gotoxy(x+30,y);
            hidecursor(1);
            color(11);
            fflush(stdin);
            gets(nombre);

            gotoxy(x+45,y);
            fflush(stdin);
            gets(apellido);
            color(1);
            hidecursor(0);

            encontrado = buscaClientePorNombre(arbol,nombre, apellido);
            if(encontrado)
            {
                muestraCliente(x+80,y,encontrado->dato);
                c = getch();

            }
            else
            {
                dibujaCuadrado(80,115,4, 7,1);
                gotoxy(82,5);
                printf("No existe cliente con ese nombre!");
                c = getch();

            }
            limpia(x+60,x+110,y-5,y+10);

            break;
        case 7:

            break;
        }
    }
    while(opcion !=7 );

}

nodoArbolCliente * modificaCliente(int x, int y, nodoArbolCliente* arbol)
{
    nodoArbolCliente * encontrado = NULL;
    int opcion, busca=-1, opcion2;
    char nombre[20], apellido[20], c;
    dibujaTituloMenus(48,74,0,2,"Editor de clientes");

    do
    {
        gotoxy(x,y-4);
        printf("Buscar por ID:");
        gotoxy(x,y-2);
        printf("Buscar por numero de cliente:");
        gotoxy(x,y);
        printf("Buscar por nombre y apellido:");
        gotoxy(x,y+2);
        printf("Salir");

        limpia(x+15,x+20,y-4,y-4);
        limpia(x+30,x+40,y-2,y-2);
        limpia(x+30,x+40,y,y);
        dibujaCuadrado(3,70,4,12,1);
        opcion = control(x-2,y-4,4);
        switch(opcion)
        {
        case 1:
            limpia(x+15,x+20,y-4,y-2);
            gotoxy(x+15,y-4);
            hidecursor(1);
            color(11);
            scanf("%i",&busca);
            color(1);
            hidecursor(0);
            if(busca <= devuelveUltId(arbol))
            {
                encontrado = buscarClientePorId(arbol, busca);
                if(encontrado)
                {
                    muestraCliente(x+80,y,encontrado->dato);

                    dibujaCuadrado(31,50,14,21,1);
                    gotoxy(32,15);
                    printf("Desea editarlo?");
                    gotoxy(38,17);
                    printf("No");
                    gotoxy(38,19);
                    printf("Si");
                    opcion2=control(36,17,2);
                    limpia(71,91,5,14);
                    limpia(30,51,13,22);

                    if(opcion2 == 3)
                    {
                        encontrado = editorDeCliente(x,y,encontrado);

                    }
                    opcion2 =0;

                }
                else if(!encontrado)
                {
                    dibujaCuadrado(80,115,4, 7,1);
                    gotoxy(84,5);
                    printf("No existe cliente con esa ID!");
                    c = getch();
                }
            }
            else
            {
                dibujaCuadrado(80,115,4, 7,1);
                gotoxy(84,5);
                printf("No existe cliente con esa ID!");
                c = getch();
            }
            limpia(x+60,x+110,y-5,y+10);

            break;

        case 3:
            limpia(x+30,x+20,y,y);
            gotoxy(x+30,y-2);
            hidecursor(1);
            color(11);
            scanf("%i",&busca);
            color(1);
            hidecursor(0);

            encontrado = buscaClientePorNroCliente(arbol, busca);
            if(encontrado)
            {
                muestraCliente(x+80,y,encontrado->dato);
                dibujaCuadrado(31,50,14,21,1);
                gotoxy(32,15);
                printf("Desea editarlo?");
                gotoxy(38,17);
                printf("No");
                gotoxy(38,19);
                printf("Si");
                opcion2=control(36,17,2);
                limpia(71,91,5,14);
                limpia(30,51,13,22);

                if(opcion2 == 3)
                {
                    encontrado = editorDeCliente(x,y,encontrado);
                }
                opcion2 =0;

            }
            else
            {
                dibujaCuadrado(80,115,4, 7,1);
                gotoxy(82,5);
                printf("No existe el numero de cliente!");
                c = getch();
            }
            limpia(x+60,x+110,y-5,y+10);

            break;

        case 5:
            limpia(x+30,x+20,y,y);
            gotoxy(x+30,y);
            hidecursor(1);
            color(11);
            fflush(stdin);
            gets(nombre);

            gotoxy(x+45,y);
            fflush(stdin);
            gets(apellido);
            color(1);
            hidecursor(0);

            encontrado = buscaClientePorNombre(arbol,nombre, apellido);
            if(encontrado)
            {
                muestraCliente(x+80,y,encontrado->dato);
                dibujaCuadrado(31,50,14,21,1);
                gotoxy(32,15);
                printf("Desea editarlo?");
                gotoxy(38,17);
                printf("No");
                gotoxy(38,19);
                printf("Si");
                opcion2=control(36,17,2);
                limpia(71,91,5,14);
                limpia(30,51,13,22);

                if(opcion2 == 3)
                {
                    encontrado = editorDeCliente(x,y,encontrado);
                }
                opcion2 =0;
            }
            else
            {
                dibujaCuadrado(80,115,4, 7,1);
                gotoxy(82,5);
                printf("No existe cliente con ese nombre!");
                c = getch();

            }
            limpia(x+60,x+110,y-5,y+10);

            break;
        case 7:

            break;
        }
    }
    while(opcion !=7 );

    return arbol;
}

nodoArbolCliente * editorDeCliente(int x, int y, nodoArbolCliente * cliente)
{
    limpia(3,117,3,20);
    dibujaCuadrado(x-2,70,6,22,1);
    int auxY = -2, opcion, opcion2 =0;
    stCliente nuevo;

    strcpy(nuevo.apellido,cliente->dato.apellido);
    strcpy(nuevo.dni,cliente->dato.dni);
    strcpy(nuevo.domicilio,cliente->dato.domicilio);
    nuevo.eliminado = cliente->dato.eliminado;
    strcpy(nuevo.email,cliente->dato.email);
    nuevo.id = cliente->dato.id;
    strcpy(nuevo.nombre,cliente->dato.nombre);
    strcpy(nuevo.telefono,cliente->dato.telefono);
    nuevo.nroCliente = cliente->dato.nroCliente;

    gotoxy(x+4,y+auxY);
    auxY +=2;
    printf("Numero de cliente: ");

    gotoxy(x+4,y+auxY);
    printf("Nombre: ");

    auxY +=2;
    gotoxy(x+4,y+auxY);
    printf("Apellido: ");

    auxY +=2;
    gotoxy(x+4,y+auxY);
    printf("DNI: ");

    auxY +=2;
    gotoxy(x+4,y+auxY);
    printf("Email: ");

    auxY +=2;
    gotoxy(x+4,y+auxY);
    printf("Domicilio: ");

    auxY +=2;
    gotoxy(x+4,y+auxY);
    printf("Telefono: ");

    auxY +=2;
    gotoxy(x+4,y+auxY);
    printf("Aceptar");
    color(11);
    gotoxy(x+22,y-2);
    printf("%i", cliente->dato.nroCliente);

    gotoxy(x+11,y);
    printf("%s", cliente->dato.nombre);

    gotoxy(x+13,y+2);
    printf("%s", cliente->dato.apellido);

    gotoxy(x+8,y+4);
    printf("%s", cliente->dato.dni);

    gotoxy(x+10,y+6);
    printf("%s", cliente->dato.email);

    gotoxy(x+14,y+8);
    printf("%s", cliente->dato.domicilio);

    gotoxy(x+13,y+10);
    printf("%s", cliente->dato.telefono);
    color(1);

    do
    {
        opcion = control(x,y-2,8);
        switch(opcion)
        {
        case 1:
            limpia(x+22,x+40,y-2,y-2);
            gotoxy(x+22,y-2);
            hidecursor(1);
            color(11);
            scanf("%i",&nuevo.nroCliente);
            color(1);
            hidecursor(0);
            break;

        case 3:
            limpia(x+11,x+40,y,y);
            gotoxy(x+11,y);
            hidecursor(1);
            color(11);
            fflush(stdin);
            gets(nuevo.nombre);
            color(1);
            hidecursor(0);
            break;

        case 5:
            limpia(x+13,x+40,y+2,y+2);
            gotoxy(x+13,y+2);
            hidecursor(1);
            color(11);
            fflush(stdin);
            gets(nuevo.apellido);
            color(1);
            hidecursor(0);
            break;

        case 7:
            limpia(x+8,x+40,y+4,y+4);
            gotoxy(x+8,y+4);
            hidecursor(1);
            color(11);
            fflush(stdin);
            gets(nuevo.dni);
            color(1);
            hidecursor(0);
            break;
        case 9:
            limpia(x+10,x+40,y+6,y+6);
            gotoxy(x+10,y+6);
            hidecursor(1);
            color(11);
            fflush(stdin);
            gets(nuevo.email);
            color(1);
            hidecursor(0);
            break;
        case 11:
            limpia(x+14,x+40,y+8,y+8);
            gotoxy(x+14,y+8);
            hidecursor(1);
            color(11);
            fflush(stdin);
            gets(nuevo.domicilio);
            color(1);
            hidecursor(0);
            break;
        case 13:
            limpia(x+13,x+40,y+10,y+10);
            gotoxy(x+13,y+10);
            hidecursor(1);
            color(11);
            fflush(stdin);
            gets(nuevo.telefono);
            color(1);
            hidecursor(0);
            break;
        case 15:
            dibujaCuadrado(71,90,6,13,1);
            gotoxy(74,7);
            printf("Desea cargarlo?");
            gotoxy(80,9);
            printf("No");
            gotoxy(80,11);
            printf("Si");
            opcion2=control(78,9,2);
            limpia(71,91,5,14);
            break;
        }
    }
    while(opcion2 !=3 );
    cliente->dato = nuevo;
    limpia(3,117,3,25);
    return cliente;
}

nodoArbolCliente * altaBajaCliente(int x, int y, nodoArbolCliente * arbol)
{
    int opcion2, id;
    char c;
    nodoArbolCliente * encontrado = NULL;
    do
    {
        limpia(3,117,10,24);
        limpia(67,75,22,22);
        dibujaCuadrado(11,36,5,9,1);

        dibujaCuadrado(40,76,21,23,1);
        gotoxy(41,22);
        printf("Ingrese el ID del cliente:");
        gotoxy(67,22);
        hidecursor(1);
        scanf("%i", &id);
        hidecursor(0);
        if(id <= devuelveUltId(arbol))
        {
            encontrado = buscarClientePorId(arbol, id);
            if(encontrado)
            {
                limpia(38,77,20,24);
                muestraCliente(x+70,y+7,encontrado->dato);
                dibujaCuadrado(20,38,15,20,1);
                gotoxy(22,16);
                printf("Desea editarlo?");
                gotoxy(26,17);
                printf("Baja");
                gotoxy(26,19);
                printf("Alta");
                opcion2=control(23,17,2);
                limpia(19,39,14,21);
                limpia(75,115,10,25);
                if( opcion2 == 1)
                {
                    dibujaCuadrado(85,115,21,23,1);
                    gotoxy(86,22);
                    color(4);
                    printf("Cliente dado de baja");
                    encontrado->dato.eliminado =-1;
                    encontrado->modificado = 1;
                    c = getch();
                }
                else
                {
                    dibujaCuadrado(85,115,21,23,1);
                    gotoxy(86,22);
                    color(4);
                    printf("Cliente dado de alta");
                    encontrado->dato.eliminado =1;
                    encontrado->modificado = 1;
                    c = getch();
                }


            }
            else if(!encontrado)
            {
                dibujaCuadrado(85,115,21,23,1);
                gotoxy(86,22);
                color(4);
                printf("No existe cliente con esa ID!");
                c = getch();
            }
        }
        else
        {
            dibujaCuadrado(85,115,21,23,1);
            color(4);
            gotoxy(86,22);
            printf("No existe cliente con esa ID!");
            c = getch();
        }
    }
    while(!encontrado);
    limpia(84,116,20,24);

    return arbol;
}

nodoArbolCliente * destruyeCliente(int x, int y, nodoArbolCliente * arbol)
{
    int opcion2, id;
    char c;
    nodoArbolCliente * encontrado = NULL;
    do
    {
        limpia(3,117,10,24);
        limpia(67,75,22,22);
        dibujaCuadrado(11,36,5,9,1);

        dibujaCuadrado(40,76,21,23,1);
        gotoxy(41,22);
        printf("Ingrese el ID del cliente:");
        gotoxy(67,22);
        hidecursor(1);
        scanf("%i", &id);
        hidecursor(0);
        encontrado = buscarClientePorId(arbol, id);
        if(encontrado)
        {
            limpia(38,77,20,24);
            muestraCliente(x+70,y+7,encontrado->dato);
            dibujaCuadrado(20,40,15,24,1);
            gotoxy(22,16);
            printf("Desea ELIMINARLO?");
            gotoxy(26,17);
            printf("No");
            gotoxy(26,19);
            printf("SI");
            gotoxy(26,21);
            printf("Salir");
            opcion2=control(23,17,3);
            limpia(19,39,14,21);
            limpia(75,115,10,25);
            if( opcion2 == 3)
            {
                dibujaCuadrado(85,115,21,23,1);
                gotoxy(86,22);
                color(4);
                printf("Cliente DESTRUIDO");
                arbol = borrarNodo(arbol,id);
                c = getch();
            }else if(opcion2 == 5)
            {
                encontrado = NULL;
            }


        }
        else if(!encontrado)
        {
            dibujaCuadrado(85,115,21,23,1);
            gotoxy(86,22);
            color(4);
            printf("No existe cliente con esa ID!");
            c = getch();
        }
    }
    while(!encontrado);
    limpia(84,116,20,24);

    return arbol;
}

//FIJARSE PORQUE CHOTA DE OSO NO SE JUGARDA BIEN
/*-------------------------------CONSUMOS-------------------------------*/



nodoArbolCliente * caseConsumo(stEmpleado empleado, nodoArbolCliente * arbol)
{
    int x=51, y=9, opcion, id;
    nodoArbolCliente * encontrado = NULL;
    char c;

    nodoListaConsumo * lista = iniciLista();

    do
    {
        limpia(83,117,21,24);
        limpia(67,75,22,22);
        dibujaCuadrado(40,76,21,23,1);
        gotoxy(41,22);
        printf("Ingrese el ID del cliente:");
        gotoxy(67,22);
        hidecursor(1);
        scanf("%i", &id);
        hidecursor(0);
        if(id <= devuelveUltId(arbol))
        {
            encontrado = buscarClientePorId(arbol, id);
            if(encontrado)
            {
                do
                {
                    muestraCliente(x+35,y+7,encontrado->dato);
                    limpia(38,77,20,24);
                    dibujaMenuCliente();
                    limpia(46,71,9,9);
                    dibujaCuadradoGordo(46,71,5,19,7);
                    color(3);
                    gotoxy(x,y);
                    printf("Cargar consumo");
                    gotoxy(x,y+2);
                    printf("Mostrar lista ");
                    gotoxy(x,y+4);
                    printf("Buscar consumos");
                    gotoxy(x,y+6);
                    printf("Modificar consumo");
                    gotoxy(x,y+8);
                    printf("Salir");

                    opcion = control(48,9,5);
                    switch(opcion)
                    {
                    case 1:
                        limpia(3,117,3,25);

                        encontrado = cargaConsumo(x-35,y,encontrado);

                        limpia(15,100,4,23,1);
                        limpia(49,80,0,5);
                        dibujarLinea(49,80,0,196);
                        break;

                    case 3:
                        limpia(3,117,3,25);
                        muestraListaConsumos(x,y,encontrado->consumos);
                        dibujaCuadrado(0,118,0,25,1);
                        empleadoYRol(empleado);

                        break;

                    case 5:

                        limpia(3,117,3,25);
                        buscaConsumos(x-45,y,lista, empleado);
                        dibujaCuadrado(0,118,0,25,1);
                        empleadoYRol(empleado);
                        limpia(2,100,4,23,1);
                        limpia(47,80,0,5);
                        dibujarLinea(49,80,0,196);

                        break;
                    case 7:
                        //modifica
                        break;
                    case 9:
                        //elimina nodo
                        break;
                    case 11:

                        break;
                    }
                }
                while(opcion !=11);

            }
            else if(!encontrado)
            {
                dibujaCuadrado(85,115,21,23,1);
                gotoxy(86,22);
                color(4);
                printf("No existe cliente con esa ID!");
                c = getch();
            }
        }
        else
        {
            dibujaCuadrado(85,115,21,23,1);
            color(4);
            gotoxy(86,22);
            printf("No existe cliente con esa ID!");
            c = getch();
        }
    }
    while(!encontrado);

    return encontrado;
}

nodoArbolCliente * cargaConsumo(int x, int y, nodoArbolCliente * cliente)
{
    dibujaTituloMenus(49,74,0,2,"Creador de consumos");
    dibujaCuadrado(15,70,6,20,1);


    int auxY = -2, opcion, opcion2 =0;
    stConsumo nuevo;

    gotoxy(x+4,y+auxY);
    auxY +=2;
    printf("ID de cliente: ");

    gotoxy(x+4,y+auxY);
    printf("A%co: ",164);

    auxY +=2;
    gotoxy(x+4,y+auxY);
    printf("Mes: ");

    auxY +=2;
    gotoxy(x+4,y+auxY);
    printf("Dia: ");

    auxY +=2;
    gotoxy(x+4,y+auxY);
    printf("Datos consumidos: ");

    auxY +=2;
    gotoxy(x+4,y+auxY);
    printf("Baja: ");

    auxY +=2;
    gotoxy(x+4,y+auxY);
    printf("Aceptar");


    do
    {
        limpia(78,105,6,16);

        opcion = control(x,y-2,7);
        switch(opcion)
        {
        case 1:
            limpia(x+18,x+40,y-2,y-2);
            gotoxy(x+18,y-2);
            hidecursor(1);
            color(11);
            scanf("%i",&nuevo.id);
            color(1);
            hidecursor(0);
            break;

        case 3:
            limpia(x+8,x+40,y,y);
            gotoxy(x+8,y);
            hidecursor(1);
            color(11);
            scanf("%i",&nuevo.anio);
            color(1);
            hidecursor(0);
            break;

        case 5:
            limpia(x+8,x+40,y+2,y+2);
            gotoxy(x+8,y+2);
            hidecursor(1);
            color(11);
            scanf("%i",&nuevo.mes);
            color(1);
            hidecursor(0);
            break;

        case 7:
            limpia(x+8,x+40,y+4,y+4);
            gotoxy(x+8,y+4);
            hidecursor(1);
            color(11);
            scanf("%i",&nuevo.dia);
            color(1);
            hidecursor(0);
            break;
        case 9:
            limpia(x+21,x+40,y+6,y+6);
            gotoxy(x+21,y+6);
            hidecursor(1);
            color(11);
            scanf("%i",&nuevo.datosConsumidos);
            color(1);
            hidecursor(0);
            break;
        case 11:
            limpia(x+9,x+40,y+8,y+8);
            gotoxy(x+9,y+8);
            hidecursor(1);
            color(11);
            scanf("%i",&nuevo.baja);
            color(1);
            hidecursor(0);
            break;
        case 13:
            dibujaCuadrado(78,98,6,12,1);
            gotoxy(81,7);
            printf("Desea cargarlo?");
            gotoxy(83,9);
            printf("No");
            gotoxy(83,11);
            printf("Si");
            opcion2=control(79,9,2);
            break;
        }
    }
    while(opcion2 !=3 );

    cliente->consumos = carga_consumo_por_fecha(cliente->consumos, nuevo_nodo_consumo(nuevo));

    return cliente;
}



void muestraListaConsumos(int x, int y, nodoListaConsumo * lista)
{
    limpia(0,118,25,25);
    int posX =0, posY =0;
    char c = 0;
    dibujaCuadrado(0,118,0,posY+6,1);
    dibujaTituloMenus(49,74,0,2,"Lista de Consumos");

    color(7);
    gotoxy(114,1);
    printf("ESC");
    color(1);
    dibujarLinea(113,118,2,196);
    dibujarLineaV(112,1,2,179);

    gotoxy(112,2);
    printf("%c",192);

    gotoxy(112,0);
    printf("%c",194);

    gotoxy(118,2);
    printf("%c",180);


    do
    {
        if(!lista)
        {
            dibujaCuadrado(85,115,21,23,1);
            color(4);
            gotoxy(86,22);
            printf("No hay consumos cargados!");
        }
        else
        {
            while(lista)
            {
                while(posX <4 && lista)
                {
                    if(posX ==0)
                    {
                        muestraConsumo(x,y+posY, lista->dato);
                    }
                    else if(posX ==1)
                    {
                        muestraConsumo(x+37,y+posY, lista->dato);
                    }
                    else if(posX ==2)
                    {
                        muestraConsumo(x+74,y+posY, lista->dato);
                    }
                    else if(posX ==3)
                    {
                        muestraConsumo(x+111,y+posY, lista->dato);
                    }
                    posX++;
                    lista = lista->siguiente;
                }
                posX=0;
                posY+=15;
            }
        }
        gotoxy(0,0);
        c =getch();

    }
    while(c !=27);

    system("cls");

}

//CAMBIAR LOS PARAMETROS DE ESTA WEA PA Q TENGA LISTA
void muestraListaConsumosSub(int x, int y)
{
    limpia(0,118,25,25);
    int posX =0, posY =0, i=0;
    char c = 0;
    do
    {
        while(i<15)
        {
            while(posX <4 )
            {
                if(posX ==0)
                {
//                    muestraConsumo(x,y+posY, lista->dato);
                    muestraConsumo(x+1,y+posY);
                }
                else if(posX ==1)
                {
//                    muestraConsumo(x+37,y+posY, lista->dato);
                    muestraConsumo(x+28,y+posY);
                }
                else if(posX ==2)
                {
//                    muestraConsumo(x+74,y+posY, lista->dato);
                    muestraConsumo(x+55,y+posY);
                }
                posX++;
                i++;
            }
            posX=0;
            posY+=10;
        }
        gotoxy(0,0);
        dibujaCuadrado(0,118,0,posY+6,1);

        color(7);
        gotoxy(114,1);
        printf("ESC");
        color(1);
        dibujarLinea(113,118,2,196);
        dibujarLineaV(112,1,2,179);

        gotoxy(112,2);
        printf("%c",192);

        gotoxy(112,0);
        printf("%c",194);

        gotoxy(118,2);
        printf("%c",180);

        c =getch();
    }
    while(c !=27);

    system("cls");

}
//HAY QUE AGREGARLE EL PARAMETRO DEL DATO DEL CONSUMO MAGUI/MARIAN
void muestraConsumo(int x, int y)
{

    dibujaCuadrado(x-10,x+15,y-5, y+3,1);

    /*
    gotoxy(x-8,y-2);
    printf("ID: %i", consumo.id);

    gotoxy(x-8,y-1);
    printf("ID cliente: %i", consumo.idCliente);

    gotoxy(x-8,y);
    printf("A%co: %i",164, consumo.anio);

    gotoxy(x-8,y+1);
    printf("Mes: %i", consumo.mes);

    gotoxy(x-8,y+2);
    printf("Dia: %i", consumo.dia);

    gotoxy(x-8,y+3);
    printf("Datos Consumidos: %i", consumo.datosConsumidos);

    gotoxy(x-8,y+4);
    printf("Baja: %i", consumo.baja);

    */

    gotoxy(x-8,y-4);
    printf("ID: %i", 1);

    gotoxy(x-8,y-3);
    printf("ID cliente: %i", 1);

    gotoxy(x-8,y-2);
    printf("A%co: %i",164, 1);

    gotoxy(x-8,y-1);
    printf("Mes: %i", 1);

    gotoxy(x-8,y);
    printf("Dia: %i", 1);

    gotoxy(x-8,y+1);
    printf("Datos Consumidos: %i", 1);

    gotoxy(x-8,y+2);
    printf("Baja: %i", 0);


}


void buscaConsumos(int x, int y, nodoListaConsumo* lista, stEmpleado empleado)
{
    int opcion, busca=-1;
    char c=0;
    nodoListaConsumo * xd = NULL;


    do
    {
        dibujaCuadrado(0,118,0,25,1);
        empleadoYRol(empleado);
        dibujaTituloMenus(48,74,0,2,"Listados de Consumos");
        gotoxy(x,y-4);
        printf("Buscar por ID:");
        gotoxy(x,y-2);
        printf("Buscar por Dia:");
        gotoxy(x,y);
        printf("Buscar por Mes:");
        gotoxy(x,y+2);
        printf("Buscar por A%co:", 164);
        gotoxy(x,y+4);
        printf("Buscar por cliente:");
        gotoxy(x,y+6);
        printf("Salir");

        dibujaCuadrado(3,30,4,16,1);
        opcion = control(x-2,y-4,7);
        switch(opcion)
        {
        case 1:
            limpia(x+15,x+20,y-4,y-4);
            gotoxy(x+15,y-4);
            hidecursor(1);
            color(11);
            scanf("%i",&busca);
            color(1);
            hidecursor(0);

            //SUSTITUIR EL CONSUMO DE ACA POR LA FUNCION QUE BUSCA POR ID MAGUI/MARIAN
            muestraConsumo(x+40,y);
            c = getch();
            if(c == 27 || c== ENTER )
            {
                limpia(x+20,x+60,y-5,y+10);
                limpia(x+15,x+20,y-4,y-2);
            }
            break;

        case 3:
            limpia(x+15,x+20,y-2,y-2);
            gotoxy(x+15,y-2);
            hidecursor(1);
            color(11);
            scanf("%i",&busca);
            color(1);
            hidecursor(0);

            //SUSTITUIR EL CONSUMO DE ACA POR LA FUNCION QUE BUSCA POR DIA MAGUI/MARIAN ADEMAS HAY QUE AGREGARLE
            //EL PARAMETRO DE LA LISTA QUE SE LO SAQUE PO Q NO FUNCA

            muestraListaConsumosSub(x+35,y);
            break;

        case 5:
            limpia(x+15,x+20,y,y);
            gotoxy(x+15,y);
            hidecursor(1);
            color(11);
            scanf("%i",&busca);
            color(1);
            hidecursor(0);

            //SUSTITUIR EL CONSUMO DE ACA POR LA FUNCION QUE BUSCA POR MES MAGUI/MARIAN ADEMAS HAY QUE AGREGARLE
            //EL PARAMETRO DE LA LISTA QUE SE LO SAQUE PO Q NO FUNCA

            muestraListaConsumosSub(x+35,y);

            break;
        case 7:
            limpia(x+15,x+20,y+2,y+2);
            gotoxy(x+15,y+2);
            hidecursor(1);
            color(11);
            scanf("%i",&busca);
            color(1);
            hidecursor(0);

            //SUSTITUIR EL CONSUMO DE ACA POR LA FUNCION QUE BUSCA POR AÑO
            // MAGUI/MARIAN ADEMAS HAY QUE AGREGARLE
            //EL PARAMETRO DE LA LISTA QUE SE LO SAQUE PO Q NO FUNCA

            muestraListaConsumosSub(x+35,y);

            break;
        case 9:
            limpia(x+19,x+23,y+4,y+4);
            gotoxy(x+19,y+4);
            hidecursor(1);
            color(11);
            scanf("%i",&busca);
            color(1);
            hidecursor(0);

            //SUSTITUIR EL CONSUMO DE ACA POR LA FUNCION QUE BUSCA POR NUMERO DE CLIENTE
            // MAGUI/MARIAN ADEMAS HAY QUE AGREGARLE
            //EL PARAMETRO DE LA LISTA QUE SE LO SAQUE PO Q NO FUNCA

            muestraListaConsumosSub(x+35,y);

            break;
        case 11:
            break;
        }
    }
    while(opcion !=11 );

}




/*-------------------------------USUARIOS-------------------------------*/

void caseLogueo()
{
//    dibujaInicial();
    /*----------------------TEMP------------------- tomy*/
    stEmpleado thomo;
    strcpy(thomo.apellido, "Urroz");
    strcpy(thomo.nombre, "Tomas");
    strcpy(thomo.password, "123");
    thomo.rol = 1;
    thomo.id = 0;

//    int opcion, x=56,y=12, flag = 0;
//    char usuario[20], password[20];
//    do{
//        opcion = control(46, 12, 3);
//        switch(opcion){
//
//            case 1:
//
//            limpia(x,x +20,y,y);
//            gotoxy(x,y);
//            hidecursor(1);
//            color(11);
//            fflush(stdin);
//            gets(usuario);
//            color(1);
//            hidecursor(0);
//            break;
//
//            case 3:
//            limpia(x +3,x +20,y +5 ,y +5);
//            gotoxy(x + 3 ,y + 2);
//            hidecursor(1);
//            color(11);
//            gets(password);
//            color(1);
//            hidecursor(0);
//            break;
//
//             case 5:
//                flag = login(usuario, password);
//                e = buscarEmpleado("empleados.dat", usuario);
//            break;
//        }
//
//
//    }
//    while(flag == 0);
//    limpia(0, 120, 0, 30);
    caseMenu(thomo);
}

int login(char usu[], char pass[])
{
    FILE * archi = fopen("empleados.dat", "rb");
    int rta = 0;
    stEmpleado e;
    if(archi)
    {

        while(fread(&e, sizeof(stEmpleado), 1, archi) > 0)
        {
            if(strcmp(e.usuario, usu) == 0  && strcmp(e.password,pass) == 0)
            {
                rta = 1;
            }
        }
        fclose(archi);
    }
    mostrarUnEmpleado(e);
    return rta;
}


void caseUsuario(stEmpleado empleado)
{
    int x=88, y=9, opcion;
    //Case entrar cliente
    limpia(83,108,9,9);
    color(3);
    gotoxy(x,y);
    printf("Modificar");

    if(empleado.rol ==1)
    {
        gotoxy(x,y+2);
        printf("Crear Usuario");
        gotoxy(x,y+4);
        printf("Lista Usuarios");
        gotoxy(x,y+6);
        printf("Modificar Usuario");
        gotoxy(x,y+8);
        printf("Salir");

        dibujaCuadradoGordo(83,108,5,19,7);

        do
        {
            opcion = control(86,9,5);
            switch(opcion)
            {
            case 1:
                //Modifica usuario actual
                break;

            case 3:
                //Cargar usuario
                break;

            case 5:
                //Lista de usuarios
                break;

            case 7:
                //Modificar usuario (una vez aca dentro se tendria que eleji porque buscar) y haber una
                //funcion que te deje listarlos una vez en el otro menu
                break;
            case 9:

                break;
            }
        }
        while(opcion !=9);

    }
    else
    {
        gotoxy(x,y+2);
        printf("Salir");

        dibujaCuadradoGordo(83,108,5,12,7);

        do
        {
            opcion = control(86,9,2);
            switch(opcion)
            {
            case 1:
                //Modifica usuario actual
                break;

            case 3:


                break;
            }
        }
        while(opcion !=3);

    }

}





