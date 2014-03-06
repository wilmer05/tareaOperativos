#ifndef std
	#define std
	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
#endif

#ifndef estructuras
	#define estructuras
	#include"estructura.h"
#endif
 
#ifndef listas
	#define listas
	#include"lista.h"
#endif

#ifndef operaciones
	#define operaciones
#endif

void liberar_memoria(lista *);

void bfs(lista *);

void mk_md_rm(char *, lista *, caja *,int, int, int, int (*fptr)(caja *, caja*));

