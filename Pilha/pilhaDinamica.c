#include <stdio.h>
#include <stdlib.h>
#include "pilhaDinamica.h" 

struct tipoNo{
    struct elemento dado;
    struct tipoNo *prox;
};
typedef struct tipoNo noPilha;

Pilha* criaPilha(){
    Pilha* top = (Pilha*) malloc(sizeof(Pilha));
    if(top != NULL)
        *top = NULL;
    return top;
}

int push(Pilha* topo, struct elemento aluno){
    if(topo == NULL)
        return 0;
    noPilha* novoNo;
    novoNo = (noPilha*) malloc(sizeof(noPilha));
    if(novoNo == NULL)
        return 0;
    novoNo->dado = aluno;
    novoNo->prox = (*topo);
    *topo = novoNo;
    return 1;
}

void imprimePilha(Pilha* topo){
    if(topo == NULL)
        return;
    noPilha* atual = *topo;
    while(atual != NULL){
        printf("\tMatricula: %d\n",atual->dado.matricula);
        printf("\tNome: %s\n",atual->dado.nome);
        printf("\tNotas: N1 = %4.2f; N2 = %4.2f N3 = %4.2f\n",
								   atual->dado.n1,
                                   atual->dado.n2,
                                   atual->dado.n3);
        printf("-------------------------------\n");
        atual = atual->prox;
    }
}

int consultaTopoPilha(Pilha* topo, struct elemento *aluno){
    if(topo == NULL)
        return 0;
    if((*topo) == NULL)
        return 0;
    *aluno = (*topo)->dado; 
    return 1;
}


int pop(Pilha* topo){
    if(topo == NULL)
        return 0;
    if((*topo) == NULL)
        return 0;
    noPilha *aux = *topo;
    *topo = aux->prox;
    free(aux);
    return 1;
}


int tamPilha(Pilha* topo){
    if(topo == NULL)
        return 0;
    int cont = 0;
    noPilha* atual = *topo;
    while(atual != NULL){
        cont++;
        atual = atual->prox;
    }
    return cont;
}

int pilhaVazia(Pilha* topo){
    if(topo == NULL)
        return 1;
    if(*topo == NULL)
        return 1;
    return 0;
}

void apagaPilha(Pilha* topo){
    if(topo != NULL){
        noPilha* atual;
        int cont=0;
        while((*topo) != NULL){
            atual = *topo;
            *topo = (*topo)->prox;
            free(atual);   
            
            
            cont++;
			printf("\n\n cont = %i", cont);   
			if ((*topo) != NULL){
	            printf("\n\n Imprimindo dentro funcao apagaPilha, TOPO = %i \n\n", (*topo)->dado.matricula);
	            imprimePilha(topo);
	            printf("\n\n");
            }
            
            system("pause");
			system("cls");
        }
        
        free(topo);
    }
}
