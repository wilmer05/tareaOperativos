#ifndef std
	#define std
	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
#endif

#ifndef largo
	#define largo 300
#endif

#ifndef estructuras
	#define estructuras
#endif

typedef struct Caja{
	void *cont;
	struct Caja *next,*prev;
} caja;

typedef struct {
	caja *first;
	int tam;
} lista;

typedef struct F{
	char *nombre;
	int tipo;
	lista *hijos;
} file;


typedef struct N{
	char *ruta;
	char *nombre;
	int tipo;
	lista *hijos;
} nodo;
