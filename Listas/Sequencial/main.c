#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"//protóripos

#define qtde 5

main(){
    struct aluno vetAlunos[qtde] = {
						 {3,"Lucas Pedro",8.2,7.5,7.8},
                         {4,"Beatriz Alfredo",6.5,8.3,8.8},
                         {1,"Mariana Oliveira",9.1,7.8,7.5},
                         {9,"Joao Junior",7.6,8.1,6.4},
                         {7,"Carlos Alberto",7.6,8.1,6.4}
	};
                         
    Lista* list = criaLista(); //Lista* list --> ponteiro para a lista
    
    int i;
    for(i=0; i < qtde; i++)
        insereOrdenada(list, vetAlunos[i]);

    imprimeLista(list);
    
    printf("\n\n\n\n");      
    struct aluno alunoEncontrado;
    
    /*
    int pos;
    printf("Digite a posicao a ser localizada: "); scanf("%d", &pos);            
    int achou = consultaPosicao(list, pos, &alunoEncontrado);//devolve (referência) dados do aluno 
																	//encontrado na posição informada
   */
    
	int nroMat;   
    printf("Digite o numero de matricula a ser localizado: "); scanf("%d", &nroMat);
    int achou = consultaMatricula(list, nroMat, &alunoEncontrado); //consulta pelo nroMat. Devolve 
																			//(ref) dados do aluno.
    
    
    if (achou == 1){	
		printf("\n\n\t\tDADO DO/A ALUNO/A\n");
		printf("\t-------------------------------\n");
	    printf("\tMatricula: %d\n",alunoEncontrado.matricula);
	    printf("\tNome: %s\n",alunoEncontrado.nome);
	    printf("\tNotas: N1 = %4.2f; N2 = %4.2f e N3 = %4.2f\n",alunoEncontrado.n1, alunoEncontrado.n2, 
																					alunoEncontrado.n3);
	    printf("\t-------------------------------\n");
    }
    else{	
    	printf("\n\n\tALUNO NAO ENCONTRADO");
	}
	
	apagaLista(list);
	printf("\n\n\n\n");
    system("pause");
}



