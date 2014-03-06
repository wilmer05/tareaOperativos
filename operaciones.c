#ifndef operaciones
	#define operaciones
	#include"operaciones.h"
#endif

#ifndef listas
	#define listas
	#include"lista.h"
#endif


void liberar_memoria(lista *arbol){
	caja *c = arbol->first;
	while(c!=NULL){
		caja *otr = c;
		liberar_memoria(((file *)(c->cont))->hijos);

		c = c->next;
		liberar(otr);
	}
}


void bfs(lista *arbol){
	lista *aux = (lista *) malloc(sizeof(lista));
	inicializar(aux);
	caja *f = arbol->first;
	while(f!=NULL){
		caja *nuev;
		nuev = (caja*) malloc(sizeof(caja));
		nuev->cont = (void *) f;
		//printf("%s\n",((file *)(f->cont))->nombre);
		f = f->next;
		agregar_elem(aux,nuev,&comparador2);
	}

	caja *recorrido = aux->first;
	
	while(NULL!=recorrido){
		file *ptr = (file *)(((caja *)(recorrido->cont))->cont);
		printf("%s\n",ptr->ruta);
		caja *ptr2 = (ptr->hijos)->first;
		while(ptr2!=NULL){
			caja *nuev;
			nuev = (caja *) malloc(sizeof(caja));
			nuev->cont=(void *) ptr2;
			agregar_elem(aux,nuev,&comparador2);
			ptr2=ptr2->next;
		}
		recorrido = recorrido->next;
		
	}

	recorrido = aux->first;

	while(NULL!=recorrido){
		f=  recorrido;
		recorrido = recorrido->next;
		free(f);

	}

	free(aux);
	
}


void mk_md_rm(char *ruta, lista *l, caja *c,int ind1, int ind2, int opc, int (*fptr)(caja *, caja*)){
	if(ind1>=ind2){
	//	printf("ya\n");
		if(!opc) agregar_elem(l,c,fptr);
		else eliminar_elem(l,c,fptr);
		return; 
	}

	char *sig;
	int tmp = ind1;
	while(ruta[ind1]!='/') ind1++;
	int tam = ind1-tmp+5;
	sig = (char *) malloc(tam);
	memset(sig,0,sizeof sig);

	for(int i = tmp ;i<ind1;i++) sig[i-tmp] = ruta[i];	
	caja *busc = l->first;
	
	while(busc!=NULL){
		if(!strcmp(sig,((file *)(busc->cont))->nombre)) break;
		busc=busc->next;
	}
	
	ind1++;
	free(sig);
	if(busc==NULL) return;
	if((((file *)(busc->cont))->tipo)==0)
		mk_md_rm(ruta,((file*)(busc->cont))->hijos,c,ind1,ind2,opc,fptr);
	else liberar(c);

}
