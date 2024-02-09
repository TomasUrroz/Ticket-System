#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

//typedef struct
//{
//    int id;
//    char apellido[50];
//    char name[50];
//    char dni[50];
//    char sexo;
//    char celular[50];
//    char email[50];
//    int nroCliente;
//    char domicilio[30];
//    int baja;           ///1 si esta de baja, 0 si esta de alta
//}stCliente;

typedef struct{
	int id; /// campo único y autoincremental
	int nroCliente;
	char nombre[30];
	char apellido[30];
	char dni[10];
	char email[30];
	char domicilio[45];
	char telefono[12];
	int eliminado; /// 0 si está activo - 1 si está eliminado
}stCliente;

int arch2arreglo(char nombreArchivo[], stCliente e[], int dim, int v);
stCliente modifCliente(stCliente nuevo);


#endif // CLIENTES_H_INCLUDED
