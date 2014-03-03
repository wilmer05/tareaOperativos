#ifndef std
	#define std
	#include<stdio.h>
	#include<string.h>
#endif

#ifndef estructuras
	#include"estructura.h"
#endif

int comparador(caja *, caja *);

void inicializar(lista *);

void agregar_elem(lista *, caja *, int (*fptr)(caja *,caja *));

void eliminar_elem(lista *, caja *, int (*fptr)(caja *,caja *));

int puedoBorrar(caja *);

int liberar(caja *);

caja *esta(lista *, caja *, int(*fptr (caja *, caja *)), int);
