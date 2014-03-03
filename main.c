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


	fptr = fopen(argv,"r");
	if(f==NULL) {
		perror("Error al abrir archivo");
		return 1;
	}



	int (*funcptr)(caja *, caja *);
	funcptr = &comparador;


	lista *arbol;
	inicializar(arbol);

	while(fgets(comando,MAX_TAM,f)!=NULL){
		int size = strlen(comando);
		int indice = size-1;

		while(indice>=0 && comando[indice]!='/') 
			indice--;
		indice++;

		int opcion=-1;
		if(comando[0]=='m') opcion=0;
		if(comando[1]=='m') opcion=1;
		if(opcion==-1) continue;
		caja *nueva;
		file *arch;
		nueva = (caja *) malloc(sizeof caja);
		arch = (file *) malloc(sizeof file);
		arch->hijos = (lista *) malloc(sizeof lista);
		inicializar(arch->hijos);
		arch->nombre= (char *) malloc(size-indice+10);
		memset(arch->nombre,0,sizeof (arch->nombre));

		if(!opcion && comando[1]=='d') arch->tipo = 0;
		else if(!opcion) arch->tipo=1;


		for(int i=indice;i<size;i++) 
			(arch->nombre)[i-indice]=comando[indice];
		
		nueva->next=nueva->prev=NULL;
		nueva->cont = (void *) arch;

		mk_md_rm(comando,arbol,nueva,3,indice,funcptr);		
	}

	fclose(fptr);

	
	
	return 0;
}
