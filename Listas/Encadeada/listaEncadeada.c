#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

struct tipoNo{
    struct elemento dado;
    struct tipoNo *prox;
};

typedef struct tipoNo noLista; //tipoNo == noLista neste arquivo
// o typedef anterior tbm pode ser definido da seguinte forma (sem especificar o nome, apenas o sin�nimo = noLista):
/*typedef struct{
    struct elemento dado;
    struct tipoNo *prox;
}noLista;*/

Lista* criaLista(){
    Lista* list = (Lista*) malloc(sizeof(Lista));
						//reserva espa�o para o primeiro n� da lista
						// list == ponteiro para estrutura com 2 campos (Lista)
    if(list != NULL)//criou corretamente
        *list = NULL; //ponteiro list est� vazio - aponta para NULL
    return list;
}

int tamLista(Lista* inicio){
    if(inicio == NULL)
        return 0;
    int cont = 0;
    noLista* no = *inicio;  //cria no aux (no), 
							//que apontar�, inicialmente, 
							//para onde inicio aponta
    						//na sequ�ncia, correr� por 
							//todos os elementos do encadeamento (prox) 
							//at� encontrar NULL.
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int listaCheia(Lista* inicio){
    return 0;
}

int listaVazia(Lista* inicio){
    if(inicio == NULL)//verifica se a cabe�a existe (lista v�lida)
        return 1;
    if(*inicio == NULL)//verifica se o conte�do dela (p/ quem aponta) � NULL
        return 1;
    return 0;
}

int consultaPosicao(Lista* inicio, int pos, struct elemento *aluno){
    if(inicio == NULL || pos <= 0)
        return 0;
    noLista *no = *inicio;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else{
        *aluno = no->dado;
        return 1;
    }
}

int consultaMatricula(Lista* inicio, int mat, struct elemento *aluno){
    if(inicio == NULL)
        return 0;
    noLista *no = *inicio;
    while(no != NULL && no->dado.matricula != mat){
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    else{
        *aluno = no->dado;
        return 1;
    }
}

int insereFinal(Lista* inicio, struct elemento aluno){
    if(inicio == NULL)
        return 0;
    noLista *no; //define ponteiro no do tipo noLista
    no = (noLista*) malloc(sizeof(noLista));
    if(no == NULL)
        return 0;
    no->dado = aluno;
    no->prox = NULL;
    if((*inicio) == NULL){//lista vazia: insere in�cio
        *inicio = no;
    }else{
        noLista *aux;
        aux = *inicio;
        while(aux->prox != NULL){
            aux = aux->prox; //			
        }
        aux->prox = no;
    }
    return 1;
}

int insereInicio(Lista* inicio, struct elemento aluno){
    if(inicio == NULL)
        return 0;
    noLista* no;
    no = (noLista*) malloc(sizeof(noLista));
    if(no == NULL)
        return 0;
    no->dado = aluno;
    no->prox = (*inicio);
    *inicio = no;
    return 1;
}

int insereOrdenada(Lista* inicio, struct elemento aluno){
    if(inicio == NULL)
        return 0;
    noLista *no = (noLista*) malloc(sizeof(noLista));
    if(no == NULL)
        return 0;
    no->dado = aluno;
    if((*inicio) == NULL){//lista vazia: insere in�cio
        no->prox = NULL;
        *inicio = no;
        return 1;
    }
    else{
        noLista *ant, *atual = *inicio;
        while(atual != NULL && atual->dado.matricula < aluno.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *inicio){//insere in�cio
            no->prox = (*inicio);
            *inicio = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

int removeMatricula(Lista* inicio, int mat){
    if(inicio == NULL)
        return 0;
    if((*inicio) == NULL)//lista vazia
        return 0;
    noLista *ant, *no = *inicio;
    while(no != NULL && no->dado.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL)//n�o encontrado
        return 0;

    if(no == *inicio)//remover o primeiro?
        *inicio = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int removeInicio(Lista* inicio){
    if(inicio == NULL)
        return 0;
    if((*inicio) == NULL)//lista vazia
        return 0;

    noLista *no = *inicio;
    *inicio = no->prox;
    free(no);
    return 1;
}

int removeFinal(Lista* inicio){
    if(inicio == NULL)
        return 0;
    if((*inicio) == NULL)//lista vazia
        return 0;

    noLista *ant, *no = *inicio;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*inicio))//remover o primeiro?
        *inicio = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

void imprimeLista(Lista* inicio){
    if(inicio == NULL)
        return;
    noLista* no = *inicio;
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


void apagaLista(Lista* inicio){
    if(inicio != NULL){
        noLista* no;
        while((*inicio) != NULL){ 		 //retira cada n� at� encontrar fim da lista (NULL)
            no = *inicio; 				//no aux recebe o in�cio da lista ("1�..." elemento)
            *inicio = (*inicio)->prox; //in�cio da lista passa a apontar p/ "2�..." elemento
            free(no); 				  //libero mem�ria do "1�..." elemento da lista
        } 
        free(inicio); //libero cabe�a da lista
    }
}
