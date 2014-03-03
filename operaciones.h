#ifndef std
	#define std
	#include<stdio.h>
	#include<string.h>
#endif

#ifndef estructuras
	#define estructuras
	#include"estructura.h"
#endif
 
#ifndef lista
	#define lista
	#include"lista.h"
#endif

void mk_md_rm(char *, lista *, caja *,int, int, int, int (*fptr)(caja *, caja*));

