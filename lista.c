#ifndef std
	#define std
	#include<stdio.h>
	#include<string.h>
#endif

#ifndef estructuras
	#include"estructura.h"
#endif



void inicializar(lista *l){
	l->primero=NULL;
	l->tam=0;
}

void agregar_elem(lista *l, caja *c, int (*fptr)(void *,void *)){
	if(esta(lista,c,fptr,0)!=NULL){
		c->next = l->first;
		c->prev = NULL;

		if(l->first!=NULL)
			(l->first)->prev = c;

		(l->tam)++;
		l->first = c;
	}
}

void eliminar_elem(lista *l, caja *c, int (*fptr)(void *,void *)){
	esta(lista,c,fptr,1);
}


int puedoBorrar(caja *borrar){
	if(borrar==NULL) return 0;

	file *ptr = (file *)(borrar->cont);

	//Si es un archivo puedo borrar
	if(file->tipo) return 1;
	
	//Si no lo es, es un directorio por lo que verifico si tiene hijos
	return !((file->hijos)->tam);
}


caja *esta(lista *l, caja *c, int(*fptr (void *, void *)), int opcion){
	caja *buscar = l->first;

	while(buscar!=NULL){
		if(fptr((void *) buscar, (void *) c)) 
			break;
		buscar = buscar-> next;
	}

	
	//Si solo tengo que buscar, retorno
	if(!opcion) return buscar;

	//Si tengo que borrar libero memoria y actualizo
	if(puedoBorrar(buscar)){
		if(buscar->prev==NULL) 
			l->first = buscar->next;
		else
			(buscar->prev)->next = buscar->next;

		if(buscar->next!=NULL)
			(buscar->next)->prev = buscar->prev;

		(l->tam)--;
		liberar(buscar);
	}
	return 1;

}
