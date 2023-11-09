#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"

#define qtde 5

main(){
    struct elemento aluno, vetAlunos[qtde] = {
						{3,"Lucas Pedro",8.2,7.5,7.8},
                        {4,"Beatriz Alfredo",6.5,8.3,8.8},
                        {1,"Mariana Oliveira",9.1,7.8,7.5},
                        {9,"Joao Junior",7.6,8.1,6.4},
                        {7,"Carlos Alberto",7.8,7.1,6.3}
	};
	
    Fila *fila = criaFila();
    
    printf(" --> Tamanho atual da fila: %d\n", tamFila(fila));
    system("pause");
	system("cls"); 
	
    int i;
    for(i=0; i < qtde; i++){   
    	printf("\n.....Inserindo no fim da fila...");
        insereFila(fila, vetAlunos[i]);    
		            
        printf("\n\n------ DADOS NA FILA\n");
        imprimeFila(fila);
                        
        printf("\n --> Tamanho atual da fila: %d\n\n\n",tamFila(fila));
        system("pause");
		system("cls");         
	}    
	
    for(i=0; i < qtde; i++){   
    	printf("\n.....Removendo do inicio da fila...");
        removeFila(fila);                    
            
        printf("\n\n------ DADOS NA FILA\n");
        imprimeFila(fila);        
                
        printf("\n --> Tamanho atual da fila: %d\n\n\n",tamFila(fila));
        system("pause");
		system("cls");         
	}   	



    printf("\n --> Tamanho atual da fila: %d\n\n\n",tamFila(fila));
    imprimeFila(fila);

    apagaFila(fila);
    
    system("pause");
}


