#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h" 

struct tipoNo{
    struct elemento dado;
    struct tipoNo *prox;
};
typedef struct tipoNo noFila;

//Nó Descritor da Fila com 3 campos
struct tipoFila{
    struct tipoNo *inicio;
    struct tipoNo *fim;
    int qtd;
};

Fila* criaFila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    if(fila != NULL){
        fila->fim = NULL;
        fila->inicio = NULL;
        fila->qtd = 0;
    }
    return fila;
}

int insereFila(Fila* fila, struct elemento aluno){
    if(fila == NULL)
        return 0;
    noFila *novoNo = (noFila*) malloc(sizeof(noFila));
    if(novoNo == NULL)
        return 0;
    novoNo->dado = aluno;
    novoNo->prox = NULL;
    if(fila->fim == NULL)//fila vazia
        fila->inicio li= novoNo;
    else
        fila->fim->prox = novoNo;
    fila->fim = novoNo;
    fila->qtd++;
    return 1;
}

void imprimeFila(Fila* fila){
    if(fila == NULL)
        return;
    noFila* no = fila->inicio;
    while(no != NULL){
        printf("\tMatricula: %d\n",no->dado.matricula);
        printf("\tNome: %s\n",no->dado.nome);
        printf("\tNotas: N1 = %4.2f; N2 = %4.2f N3 = %4.2f\n",
								no->dado.n1,
                                no->dado.n2,
                                no->dado.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}

int removeFila(Fila* fila){
    if(fila == NULL)
        return 0;
    if(fila->inicio == NULL)//fila vazia
        return 0;
    noFila *aux = fila->inicio;
    fila->inicio = fila->inicio->prox;
    if(fila->inicio == NULL)//fila ficou vazia
        fila->fim = NULL;
    free(aux);
    fila->qtd--;
    return 1;
}

int consultaFila(Fila* fila, struct elemento *aluno){
    if(fila == NULL)
        return 0;
    if(fila->inicio == NULL)//fila vazia
        return 0;
    *aluno = fila->inicio->dado;
    return 1;
}

int tamFila(Fila* fila){
    if(fila == NULL)
        return 0;
    return fila->qtd;
}

int filaVazia(Fila* fila){
    if(fila == NULL)
        return 1;
    if(fila->inicio == NULL)
        return 1;
    return 0;
}

void apagaFila(Fila* fila){
    if(fila != NULL){
        noFila* aux;
        while(fila->inicio != NULL){
            aux = fila->inicio;
            fila->inicio = fila->inicio->prox;
            free(aux);
        }
        free(fila);
    }
}
