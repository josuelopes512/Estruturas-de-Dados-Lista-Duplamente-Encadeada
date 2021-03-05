#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include "ListaSec.h"

int main(){
	TNoDe* l = criar(30);
	int i;
	
	inserir(l, 0);
	inserir(l, 1);
	inserir(l, 2);
	inserir(l, 3);


	//inserir_pos(l, 2, 6);
	
	tornar_circular(l);
	exibe(l);
}
