#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

#define qtde 5

main(){
    struct elemento vetAlunos[qtde] = {
						{3,"Lucas Pedro",8.2,7.5,7.8},
                        {4,"Beatriz Alfredo",6.5,8.3,8.8},
                        {1,"Mariana Oliveira",9.1,7.8,7.5},
                        {9,"Joao Junior",7.6,8.1,6.4},
                        {7,"Carlos Alberto",7.8,7.1,6.3}
	};
	
    Lista *inicio = criaLista(); //cria ponteiro especial (inicio**) que aponta 
								//para outro ponteiro (Lista*), que é ponteiro para struct com 2 campos (tipoNo)
								//desta forma, o "início" da lista é ponteiro para ponteiro
    int i;
    
    printf(" --> Tamanho atual da lista: %d\n", tamLista(inicio));
    system("pause");
	system("cls"); 
		    
    for(i=0; i < qtde; i++){   
    	printf("\n.....Inserindo elemento na posicao: %d", i);
        insereFinal(inicio, vetAlunos[i]);
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
        removeInicio(inicio);
        printf("\n\n------ DADOS NA LISTA\n");
        imprimeLista(inicio);
        printf("\n --> Tamanho atual da lista: %d\n\n\n",tamLista(inicio));
        system("pause");
		system("cls");
    }
	system("pause");
	system("cls");
	
    for(i=0; i < qtde; i++){
    	printf("\n.....Inserindo elemento na posicao: %d", i);
        insereFinal(inicio,vetAlunos[i]);
        printf("\n\n------ DADOS NA LISTA\n");
        imprimeLista(inicio);
        printf("\n --> Tamanho atual da lista: %d\n\n\n",tamLista(inicio));
        system("pause");
		system("cls");        
	}


    apagaLista(inicio);
    system("pause");

}

