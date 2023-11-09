#include <stdio.h>
#include <stdlib.h>
#include "aBB.h"

struct no{
    int dado;
    struct no *sae;
    struct no *sad;
};

arvoreBinaria* criaArvBin(){
    arvoreBinaria* raiz = (arvoreBinaria*) malloc(sizeof(arvoreBinaria));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

int insereOrdenadoArvBin(arvoreBinaria* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct no* novoNo = (struct no*) malloc(sizeof(struct no));
    if(novoNo == NULL)
        return 0;
    novoNo->dado = valor;
    novoNo->sad = NULL;
    novoNo->sae = NULL;

    if(*raiz == NULL)
        *raiz = novoNo;
    else{
        struct no* atual = *raiz;
        struct no* anterior = NULL;
        while(atual != NULL){
            anterior = atual;
            if(valor == atual->dado){
                free(novoNo);
                return 0;
            }

            if(valor > atual->dado)
                atual = atual->sad;
            else
                atual = atual->sae;
        }
        if(valor > anterior->dado)
            anterior->sad = novoNo;
        else
            anterior->sae = novoNo;
    }
    return 1;
}

struct no* removeAtual(struct no* atual) {
    struct no *aux1, *aux2;

    if(atual->sae == NULL){
        aux2 = atual->sad;
        free(atual);
        return aux2;
    }

    aux1 = atual;
    aux2 = atual->sae;
    while(aux2->sad != NULL){
        aux1 = aux2;
        aux2 = aux2->sad;
    }

    if(aux1 != atual){
        aux1->sad = aux2->sae;
        aux2->sae = atual->sae;
    }
    aux2->sad = atual->sad;
    free(atual);
    return aux2;
}

int removeArvBin(arvoreBinaria *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct no *anterior = NULL;
    struct no *atual = *raiz;
    while(atual != NULL){
        if(valor == atual->dado){
            if(atual == *raiz)
                *raiz = removeAtual(atual);
            else{
                if(anterior->sad == atual)
                    anterior->sad = removeAtual(atual);
                else
                    anterior->sae = removeAtual(atual);
            }
            return 1;
        }

        anterior = atual;
        if(valor > atual->dado)
            atual = atual->sad;
        else
            atual = atual->sae;
    }
    return 0;
}

int estaVaziaArvBin(arvoreBinaria *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

void preOrdemArvBin(arvoreBinaria *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n",(*raiz)->dado);
        preOrdemArvBin(&((*raiz)->sae));
        preOrdemArvBin(&((*raiz)->sad));
    }
}

void liberaNo(struct no* pontNo){
    if(pontNo == NULL){
        return;
	}
	liberaNo(pontNo->sae);
    liberaNo(pontNo->sad);
	free(pontNo);
}


void liberaArvBin(arvoreBinaria* raiz){
    if(raiz == NULL)
        return;
    liberaNo(*raiz);//libera cada nó
    free(raiz);
}

int igual(arvoreBinaria* a, arvoreBinaria* b){
    if (((*a) == NULL) != ((*b) == NULL)) return 0;

    if ((*a) == (*b)) return 1;

    if ((*a)->dado != (*b)->dado) return 0;

    if (!igual(&((*a)->sae), &((*b)->sae))) return 0;

    if (!igual(&((*a)->sad), &((*b)->sad))) return 0;

    return 1;
}
