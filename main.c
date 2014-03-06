#ifndef std
	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
#endif

#ifndef operaciones
	#define operaciones
	#include"operaciones.h"
#endif

const int MAX_TAM = 10000;

int main(int argc, char **argv){

	FILE *fptr;
	char comando[MAX_TAM];

	if(argc<2) {
		perror("Faltan argumentos, la llamada debe ser: Ejecutable < nombre_archivo >");
		return 1;
	}

//	printf("hola");
	fptr = fopen(argv[1],"r");
	if(fptr==NULL) {
		perror("Error al abrir archivo");
		return 1;
	}



	int (*funcptr)(caja *, caja *);
	funcptr = &comparador;

	//printf("bla");
	lista *arbol;
	arbol = (lista *) malloc(sizeof(lista));
	inicializar(arbol);

	while(fgets(comando,MAX_TAM,fptr)!=NULL){
		int size = strlen(comando);
		int indice = size-1;
		comando[indice]='\0';
		indice--;
		while(indice>=0 && comando[indice]!='/') 
			indice--;
		indice++;

		int opcion=-1;
		if(comando[0]=='m') opcion=0;
		if(comando[1]=='m') opcion=1;
		if(opcion==-1) continue;
		caja *nueva;
		file *arch;
		nueva = (caja *) malloc(sizeof(caja));
		arch = (file *) malloc(sizeof(file));
		arch->hijos = (lista *) malloc(sizeof(lista));
		inicializar(arch->hijos);
		arch->nombre= (char *) malloc((size-indice+100)*(sizeof(char)));
		arch->ruta= (char *) malloc(size*sizeof(char));

		memset(arch->nombre,0,sizeof (arch->nombre));

		if(!opcion && comando[1]=='d') arch->tipo = 0;
		else if(!opcion) arch->tipo=1;
		strcpy(arch->ruta,comando+3);	
		strcpy(arch->nombre,comando+indice);
		nueva->next=nueva->prev=NULL;
		nueva->cont = (void *) arch;
		mk_md_rm(comando,arbol,nueva,4,indice,opcion,funcptr);		
	}
	caja *tmp = arbol->first;

	bfs(arbol);
	fclose(fptr);
	liberar_memoria(arbol);
	free(arbol);	
	
	return 0;
}
