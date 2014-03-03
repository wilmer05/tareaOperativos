#ifndef std
	#include<stdio.h>
	#include<string.h>
#endif

#ifndef estructuras
	#include"estructura.h"
#endif


void inicializar(lista *);

void agregar_elem(lista *, caja *, int (*fptr)(void *,void *));

void eliminar_elem(lista *, caja *, int (*fptr)(void *,void *));

int puedoBorrar(caja *);

int esta(lista *, caja *, int(*fptr (void *, void *)), int);


