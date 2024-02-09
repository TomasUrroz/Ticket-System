#ifndef CONSUMOS_H_INCLUDED
#define CONSUMOS_H_INCLUDED


typedef struct
{
	int id; /// campo único y autoincremental
	int idCliente;
	int anio;
	int mes; /// 1 a 12
	int dia; /// 1 a … dependiendo del mes
	int datosConsumidos; /// expresados en mb.
	int baja; /// 0 si está activo - 1 si está eliminado
}stConsumo;





#endif // CONSUMOS_H_INCLUDED
