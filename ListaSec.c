#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include "ListaSec.h"

struct NoDe{
	int info;
	TNoDe *prox;
	TNoDe *ant;
};

TNoDe* criar(int v){
	TNoDe* ptno = (TNoDe *)malloc(sizeof(TNoDe));
	ptno->info = v;
	ptno->prox = NULL;
	ptno->ant = NULL;
	
	return ptno;
}

int tamanho(TNoDe *l){
	if(l == NULL) return -1;
	TNoDe *ptaux = l->prox;
	int n = 0;
	while(ptaux != NULL){
		n = n + 1;
		ptaux = ptaux->prox;
	}
	return n;
}

void inserir(TNoDe *l, int v){
	//inserir final
	if(l == NULL) return NULL;
	TNoDe *ptaux = l;
	while(ptaux->prox != NULL){
		ptaux = ptaux->prox;
	}
	TNoDe *ptnovo = criar(v);
	ptaux->prox = ptnovo;
	ptnovo->ant = ptaux;
}

void exibe(TNoDe *l){
	if(l == NULL) return NULL;
	TNoDe *ptaux = l->prox;
	printf("\n");
	while(ptaux != NULL){
		printf("%d", ptaux->info );
		ptaux = ptaux->prox;
	}
	printf("\n");
}

TNoDe* buscar(TNoDe *l, int v){
	if(l == NULL) return NULL;
	TNoDe *ptaux = l->prox;
	while(ptaux != NULL){
		if(ptaux->info == v){
			return ptaux;
		}else{
			ptaux = ptaux->prox;
		}
	}
	return NULL;
}

void exibeno(TNoDe *l){
	printf("%d", l->info);
}

void remover(TNoDe *l, int v){
	if(l == NULL) return NULL;
	TNoDe *ptaux = l->prox;
	while(ptaux != NULL){
		if(ptaux->info == v){
			ptaux->ant->prox = ptaux->prox;
			if(ptaux->prox =! NULL){
				ptaux->prox->ant = ptaux->ant;
			}
			free(ptaux);
			return;
		}
		ptaux = ptaux->prox;
	
	}
}
/*
void inserir_pos(TNoDE *l, int v,int pos){
    if(l == NULL) return NULL;
    TNoDE *ptaux = l->prox, *novo;
    int i = 1;
    while(i < pos){
        ptaux = ptaux->prox;
        i++;
    }
    novo = (TNoDE*) malloc(sizeof(TNoDE));
    novo->info = v;
    ptaux->prox->ant = novo;
    novo->prox = ptaux->prox;
    ptaux->prox = novo;
    novo->ant = ptaux;
}*/


void inserir_pos(TNoDe *lista, int posicao, int valor) {
    TNoDe* listaAuxiliar = lista;
	TNoDe* novoElemento = (TNoDe*) malloc(sizeof(TNoDe));
	novoElemento->info = valor;
	
	int contadorDaLista = 0; 
	if(lista == NULL) return;	
			
	for (contadorDaLista = 0; contadorDaLista < posicao; contadorDaLista++){
		listaAuxiliar = listaAuxiliar->prox;
	}

    if (listaAuxiliar->prox != NULL){
		novoElemento->prox = listaAuxiliar->prox;
	}
	novoElemento->ant = listaAuxiliar;	
			
    if (listaAuxiliar->prox != NULL){
		listaAuxiliar->prox->ant = novoElemento;
	}	
    listaAuxiliar->prox = novoElemento;
            
}




void tornar_circular(TNoDe *no){
        TNoDe *noAuxiliar = no;
        TNoDe *noContador = no;
        TNoDe *noSentinela = no;
        int Contador = 0;
        int index = 0;

        if(noContador == NULL){
            printf("Alocação Invalida, lista cheia ou vazia \n");
        }

        while(noContador != NULL){
            noContador = noContador->prox;
            Contador = Contador + 1;
        }

        for (index = 0; index < Contador; index++){
            noAuxiliar = noAuxiliar -> prox;
                if(noAuxiliar->prox == NULL) {
                    noAuxiliar->prox = noSentinela;
                    noSentinela->ant = noAuxiliar;
                return 0;
                }
        }
}
