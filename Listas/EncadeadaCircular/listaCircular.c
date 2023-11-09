#include <stdio.h>
#include <stdlib.h>
#include "listaCircular.h" 

struct tipoNo{
    struct elemento dado;
    struct tipoNo *prox;
};

typedef struct tipoNo noLista; 

Lista* criaLista(){
    Lista* inicio = (Lista*) malloc(sizeof(Lista));
    if(inicio != NULL)
        *inicio = NULL;
    return inicio;
}

int tamLista(Lista* inicio){
    if(inicio == NULL || (*inicio) == NULL)
        return 0;
    int cont = 0;
    noLista *no = *inicio;
    do{
        cont++;
        no = no->prox;
    }while(no != (*inicio));
    return cont;
}


int listaVazia(Lista* inicio){
    if(inicio == NULL)
        return 1;
    if(*inicio == NULL)
        return 1;
    return 0;
}

int consultaPosicao(Lista* inicio, int pos, struct elemento *aluno){
    if(inicio == NULL || (*inicio) == NULL || pos <= 0)
        return 0;
    noLista *no = *inicio;
    int i = 1;
    while(no->prox != (*inicio) && i < pos){
        no = no->prox;
        i++;
    }
    if(i != pos)
        return 0;
    else{
        *aluno = no->dado;
        return 1;
    }
}

int consultaMatricula(Lista* inicio, int mat, struct elemento *aluno){
    if(inicio == NULL || (*inicio) == NULL)
        return 0;
    noLista *no = *inicio;
    while(no->prox != (*inicio) && no->dado.matricula != mat)
        no = no->prox;
    if(no->dado.matricula != mat)
        return 0;
    else{
        *aluno = no->dado;
        return 1;
    }
}

int insereFinal(Lista* inicio, struct elemento aluno){
    if(inicio == NULL)
        return 0;
    noLista *no = (noLista*) malloc(sizeof(noLista));
    if(no == NULL)
        return 0;
    no->dado = aluno;
    if((*inicio) == NULL){//lista vazia    : insere início
        *inicio = no;
        no->prox = no;
    }else{
        noLista *atual = *inicio;
        while(atual->prox != (*inicio)){
            atual = atual->prox;
        }
        atual->prox = no;
        no->prox = *inicio;
    }
    return 1;
}

int insereInicio(Lista* inicio, struct elemento aluno){
    if(inicio == NULL)
        return 0;
    noLista *no = (noLista*) malloc(sizeof(noLista));
    if(no == NULL)
        return 0;
    no->dado = aluno;
    if((*inicio) == NULL){//lista vazia: insere início
        *inicio = no;
        no->prox = no;
    }else{
        noLista *atual = *inicio;
        while(atual->prox != (*inicio)){
            atual = atual->prox;
        }
        atual->prox = no;
        no->prox = *inicio;
        *inicio = no;
    }
    return 1;
}

int insereOrdenada(Lista* inicio, struct elemento aluno){//TERMINAR
    if(inicio == NULL)
        return 0;
    noLista *no = (noLista*) malloc(sizeof(noLista));
    if(no == NULL)
        return 0;
    no->dado = aluno;
    if((*inicio) == NULL){//insere início em lista vazia
        *inicio = no;
        no->prox = no;
        return 1;
    }
    else{
        if((*inicio)->dado.matricula > aluno.matricula){
			//insere início em lista não vazia
            noLista *atual = *inicio;
            while(atual->prox != (*inicio))//procura o último
                atual = atual->prox;
            no->prox = *inicio;
            atual->prox = no;
            *inicio = no;
            return 1;
        }
        noLista *anterior = *inicio, *atual = (*inicio)->prox;
        while(atual != (*inicio) && atual->dado.matricula < aluno.matricula){
            anterior = atual;
            atual = atual->prox;
        }
        anterior->prox = no;
        no->prox = atual;
        return 1;
    }
}


int removeMatricula(Lista* inicio, int mat){
    if(inicio == NULL)
        return 0;
    if((*inicio) == NULL)//lista vazia
        return 0;
    noLista *no = *inicio;
    if(no->dado.matricula == mat){//remover do início
        if(no == no->prox){//lista ficará vazia
            free(no);
            *inicio = NULL;
            return 1;
        }else{
            noLista *ultimo = *inicio;
            while(ultimo->prox != (*inicio))//procura o último
                ultimo = ultimo->prox;
            ultimo->prox = (*inicio)->prox;
            *inicio = (*inicio)->prox;
            free(no);
            return 1;
        }
    }
    noLista *anterior = no;
    no = no->prox;
    while(no != (*inicio) && no->dado.matricula != mat){
        anterior = no;
        no = no->prox;
    }
    if(no == *inicio)//não encontrado
        return 0;

    anterior->prox = no->prox;
    free(no);
    return 1;
}


int removeInicio(Lista* inicio){
    if(inicio == NULL)
        return 0;
    if((*inicio) == NULL)//lista vazia
        return 0;

    if((*inicio) == (*inicio)->prox){//lista ficará vazia
        free(*inicio);
        *inicio = NULL;
        return 1;
    }
    noLista *atual = *inicio;
    while(atual->prox != (*inicio))//procura o último
        atual = atual->prox;

    noLista *no = *inicio;
    atual->prox = no->prox;
    *inicio = no->prox;
    free(no);
    return 1;
}

int removeFinal(Lista* inicio){
    if(inicio == NULL)
        return 0;
    if((*inicio) == NULL)//lista vazia
        return 0;

    if((*inicio) == (*inicio)->prox){//lista ficará vazia
        free(*inicio);
        *inicio = NULL;
        return 1;
    }
    noLista *anterior, *no = *inicio;
    while(no->prox != (*inicio)){//procura o último
        anterior = no;
        no = no->prox;
    }
    anterior->prox = no->prox;
    free(no);
    return 1;
}


void imprimeLista(Lista* inicio){
    if(inicio == NULL || (*inicio) == NULL)
        return;
    noLista *no = *inicio;
    do{
        printf("\tMatricula: %d\n",no->dado.matricula);
        printf("\tNome: %s\n",no->dado.nome);
        printf("\tNotas: N1 = %4.2f; N2 = %4.2f N3 = %4.2f\n",
								no->dado.n1,
                                no->dado.n2,
                                no->dado.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }while(no != (*inicio));
}


void apagaLista(Lista* inicio){
    if(inicio != NULL && (*inicio) != NULL){ //É lista válida (tenho ponteiro) e NÃO VAZIA
        noLista *anterior, *no = *inicio;
        while((*inicio) != no->prox){ //SE IGUAIS, ÚLTIMO ELEMENTO
            anterior = no;
            no = no->prox;
            free(anterior);
        }
        free(no);
        free(inicio);
    }
}
