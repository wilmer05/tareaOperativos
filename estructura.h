#ifndef std
	#define std
	#include<stdio.h>
	#include<string.h>
#endif

#ifndef largo
	#define largo 300
#endif

#ifndef estructuras
	#define estructuras
	typedef struct C{
		void *cont;
		C *next,*prev;
	}caja;

	typedef struct {
		caja *first;
		int tam;
	} lista;

	typedef struct F{
		char *nombre;
		int tipo;
		lista *hijos;
	} file;

#endif
