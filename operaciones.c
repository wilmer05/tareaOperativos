#ifndef operaciones
	#define operaciones
	#include"operaciones.h"
#endif



void mk_md_rm(char *ruta, lista *l, caja *c,int ind1, int ind2, int opc, int (*fptr)(caja *, caja*)){
	if(ind1>=ind2){
		if(!opc) agregar_elem(l,c,fptr);
		else eliminar_elem(l,c,fptr); 
	}

	char *sig;
	int tmp = ind1;
	while(ruta[ind1]!='/') ind1++;
	int tam = ind1-tmp+5;
	sig = (char *) malloc(tam*(sizeof char));
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
	mk_md_rm(ruta,l,c,ind1,ind2,opc,fptr);

}
