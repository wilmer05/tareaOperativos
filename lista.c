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



int comparador(caja *c1, caja *c2){
	return strcmp(((file *)(c1->cont))->nombre,((file *)(c2->cont))->nombre);
}

void inicializar(lista *l){
	l->first=NULL;
	l->tam=0;
}

void agregar_elem(lista *l, caja *c, int (*fptr)(caja *,caja *)){
	if(esta(lista,c,fptr,0)!=NULL){
		c->next = l->first;
		c->prev = NULL;

		if(l->first!=NULL)
			(l->first)->prev = c;

		(l->tam)++;
		l->first = c;
	}
	else liberar(c);
}

void eliminar_elem(lista *l, caja *c, int (*fptr)(caja *,caja *)){
	esta(lista,c,fptr,1);
	liberar(c);
}


void liberar(caja *c){
	c->next=c->prev=NULL;
	file *ptr = (file *) cont;
	free(ptr->hijos);
	free(ptr->nombre);
	free(ptr);
	free(c);
}


int puedoBorrar(caja *borrar){
	if(borrar==NULL) return 0;

	file *ptr = (file *)(borrar->cont);

	//Si es un archivo puedo borrar
	if(file->tipo) return 1;
	
	//Si no lo es, es un directorio por lo que verifico si tiene hijos
	return !((file->hijos)->tam);
}


caja *esta(lista *l, caja *c, int(*fptr (caja *, caja *)), int opcion){
	caja *buscar = l->first;

	while(buscar!=NULL){
		if((*fptr)(buscar, c)) 
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
	return NULL;

}
