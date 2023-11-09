#include <stdio.h>
#include <stdlib.h>
#include "listaCircular.h"

#define qtde 5

main(){
    struct elemento vetAlunos[qtde] = {
						{3,"Lucas Pedro",8.2,7.5,7.8},
                        {4,"Beatriz Alfredo",6.5,8.3,8.8},
                        {1,"Mariana Oliveira",9.1,7.8,7.5},
                        {9,"Joao Junior",7.6,8.1,6.4},
                        {7,"Carlos Alberto",7.8,7.1,6.3}
	};
	
    Lista *inicio = criaLista();
    int i;
    
    printf(" --> Tamanho atual da lista: %d\n", tamLista(inicio));
    system("pause");
	system("cls"); 
	
	
    for(i=0; i < qtde; i++){   
    	printf("\n.....Inserindo elemento no inicio: %d", i);
        insereInicio(inicio, vetAlunos[i]);

        printf("\n\n------ DADOS NA LISTA\n");
        imprimeLista(inicio);
        printf("\n --> Tamanho atual da lista: %d\n\n\n",tamLista(inicio));
        system("pause");
		system("cls"); 
	}

	printf("\n\n\n------ DADOS NA LISTA ------\n");
    imprimeLista(inicio);
	printf("\n --> Tamanho atual da lista: %d\n\n\n",tamLista(inicio));
	
	system("pause");
	system("cls");
	

    for(i=0; i < qtde; i++){
    	printf("\n.....Removendo elemento da posicao: %d", i);
        removeMatricula(inicio, i+1);								//+1??
        printf("\n\n------ DADOS NA LISTA\n");
        imprimeLista(inicio);
        printf("\n --> Tamanho atual da lista: %d\n\n\n",tamLista(inicio));
        system("pause");
		system("cls");
    }
	system("pause");
	
	/*
    for(i=0; i < qtde; i++){ 
        //remove_lista(li,i+1);
        if(!remove_lista(li,i+1))
            printf("Erro!!!!!!!!!\n");
        imprime_lista(li);
        printf("\n\n======================\n\n");
    }
    for(i=0; i < 4; i++)
        insere_lista_ordenada(li,a[i]);

    imprime_lista(li);
    libera_lista(li);
    system("pause");
    return 0;*/
    
}

