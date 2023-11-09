#include <stdio.h>
#include <stdlib.h>
#include "pilhaDinamica.h"

#define qtde 5

main(){
    struct elemento vetAlunos[qtde] = {
						{3,"Lucas Pedro",8.2,7.5,7.8},
                        {4,"Beatriz Alfredo",6.5,8.3,8.8},
                        {1,"Mariana Oliveira",9.1,7.8,7.5},
                        {9,"Joao Junior",7.6,8.1,6.4},
                        {7,"Carlos Alberto",7.8,7.1,6.3}
	};
	
    Pilha *topo = criaPilha();
    
    printf(" --> Tamanho atual da pilha: %d\n", tamPilha(topo));
    system("pause");
	system("cls");     
    
    int i;
    for(i=0; i < qtde; i++){  
    	printf("\n.....Inserindo no topo da pilha...");
        push(topo, vetAlunos[i]);    
		            
        printf("\n\n------ DADOS NA PILHA\n");
        imprimePilha(topo);
                        
        printf("\n --> Tamanho atual da pilha: %d\n\n\n",tamPilha(topo));
        system("pause");
		system("cls");         
	}  

    printf("\n.....Removendo do topo da pilha...");
    pop(topo);  

	printf("\n\n------ DADOS NA PILHA\n");
    imprimePilha(topo);
		
    printf("\n --> Tamanho atual da pilha: %d\n\n\n",tamPilha(topo));
    system("pause");
	system("cls");    

    printf("\n.....Inserindo no topo da pilha...");				
	struct elemento novoNo = {43,"Gislaine Rosales",6.0,9.5,10.0};						
	push(topo, novoNo); 
	printf("\n\n------ DADOS NA PILHA\n");
    imprimePilha(topo);
	system("pause");
	system("cls");  
		
    printf("\n --> Tamanho atual da pilha: %d\n\n\n",tamPilha(topo));
    system("pause");
	system("cls");    
	
	printf("\n.....Apagando a pilha...");	
	apagaPilha(topo);

    system("pause");
}

