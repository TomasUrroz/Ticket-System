#include <stdio.h>
#include <stdlib.h>


#include "consumos.h"





void muestraUnConsumo(stConsumo c)
{
    printf("\n----------------------------------");
    printf("\n ID Cliente........: %d ", c.idCliente);
    printf("\n Año...............: %d ", c.anio);
    printf("\n Mes...............: %d ", c.mes);
    printf("\n Dia...............: %d ", c.dia);
    printf("\n Datos Consumidos..: %d ", c.datosConsumidos);
    printf("\n Baja..............: %d ", c.baja);
    printf("\n----------------------------------");
}



int check_date_consumo(int dia, int mes, int anio)
{
    int diaMaximo;
    int flag=0;

    if (mes>=1 && mes<=12 )
        {
        switch(mes)
            {
            case  1 :
            case  3 :
            case  5 :
            case  7 :
            case  8 :
            case 10 :
            case 12 :
            diaMaximo = 31;
            break;
            case  4 :
            case  6 :
            case  9 :
            case 11 :
            diaMaximo = 30;
            break;
            case  2 :
                if (anio%4 == 0 && anio%100 != 0 || anio % 400 == 0)
                    {
                    diaMaximo = 29;
                    }
                else
                    {
                    diaMaximo = 28;
                    }
            }
        if (dia>=1 && dia<=diaMaximo)
            {
            flag = 1;
            }
        }

    return flag;
}



