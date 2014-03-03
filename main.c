#ifndef std
	#include<stdio.h>
	#include<string.h>
#endif

#include"operaciones.h"

const int MAX_TAM = 10000;
char comando[MAX_TAM];


int main(int argc, char **argv){

	FILE *fptr;
	if(argc<2) {
		perror("Faltan argumentos, la llamada debe ser: Ejecutable < nombre_archivo >");
		return 1;
	}

	int (*funcptr)(caja *, caja *);
	funcptr = &comparador;

	fptr = fopen(argv,"r");
	if(f==NULL) {
		perror("Error al abrir archivo");
		return 1;
	}
	while(fgets(comando,MAX_TAM,f)!=NULL){
		int size = strlen(comando);
		int opcion=-1;
		if(comando[0]=='m') opcion=0;
		if(comando[0]=='r') opcion=1;
		if(opcion==-1) continue;
		


	}

	fclose(fptr);

	
	
	return 0;
}
