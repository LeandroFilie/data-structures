#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h" //Protótipos

struct lista{ //definição da lista
    int prox;
    struct aluno alunos[MAX];//MAX posições no vetor
};

Lista* criaLista(){
    Lista *list; //cria ponteiro
    list = (Lista*) malloc(sizeof(struct lista)); //aloca espaço
    if(list != NULL)
        list->prox = 0; //se criou, indico que a próxima posição vazia é a 1ª
    return list;
}

int insereFinal(Lista* list, struct aluno al){
    if(list == NULL)//há algo de errado com a lista (não foi criada, p. ex.)
        return 0;
    if(list->prox == MAX)//lista cheia 
        return 0;
    list->alunos[list->prox] = al;
    list->prox++;
    return 1;
}

int insereInicio(Lista* list, struct aluno al){
    if(list == NULL)
        return 0;
    if(list->prox == MAX)//lista cheia
        return 0;
    int i;
    for(i=list->prox-1; i>=0; i--) //de trás p/ frente p/ não sobrescrever posições
        list->alunos[i+1] = list->alunos[i];//desloca 1 posição p/ frente(todos elementos)
    list->alunos[0] = al;
    list->prox++;
    return 1;
}

int insereOrdenada(Lista* list, struct aluno al){
    if(list == NULL)//lista válida
        return 0;
    if(list->prox == MAX)//lista cheia
        return 0;
    int k,i = 0;
    while(i<list->prox && list->alunos[i].matricula < al.matricula) //busca onde inserir
        i++; //posição a ser ocupada

    for(k=list->prox-1; k >= i; k--) //liberar pos: desloca elem (p/ frente) do final até 
        list->alunos[k+1] = list->alunos[k];						//posição encontrada.

    list->alunos[i] = al; //insere na pos encontrada
    list->prox++;
    return 1;
}

int removeMatricula(Lista* list, int mat){//remove elemento (aluno) informado
    if(list == NULL)//lista inválida
        return 0;
    if(list->prox == 0)//lista vazia
        return 0;
    int k,i = 0;
    while(i<list->prox && list->alunos[i].matricula != mat)//percorro a lista e até encontrar o 
		i++;													//aluno ou até chegar no final.      
    if(i == list->prox)//chegou no final e não encontrou elemento na lista
        return 0;

    for(k=i; k< list->prox-1; k++) //desloca todos os elementos seguintes para a posição anterior
        list->alunos[k] = list->alunos[k+1];
    list->prox--; //atualiza próx
    return 1;
}

int removeInicio(Lista* list){
    if(list == NULL)//lista inválida
        return 0;
    if(list->prox == 0)//lista vazia
        return 0;
    int k = 0;
    for(k=0; k< list->prox-1; k++)//desloca todos os elementos para posição anterior
        list->alunos[k] = list->alunos[k+1];
    list->prox--;//decrementa próx
    return 1;
}

int removeFinal(Lista* list){
    if(list == NULL)//lista inválida
        return 0;
    if(list->prox == 0) //lista vazia - não pode remover
        return 0;
    list->prox--; //não precisa de realocação, apenas atualiza próx
    return 1;
}

int tamLista(Lista* list){
    if(list == NULL) 
        return -1;
    else
        return list->prox; //se ok, retorno o tamanho - semelhante a (*list).prox
}

int listaCheia(Lista* list){
    if(list == NULL) //problema na lsita
        return -1;
    return (list->prox == MAX); //MAX posições preenchidas, prox = MAX; retorna 1 (cheia)
}

int listaVazia(Lista* list){
    if(list == NULL)
        return -1;
    return (list->prox == 0);//se VERDADE (prox é == 0) --> retorna 1 (vazia)
}

//passo ponteiro p/ struct aluno que é onde vou guardar os dados encontrados
int consultaPosicao(Lista* list, int pos, struct aluno *estudante){
    if(list == NULL || pos <= 0 ||  pos > list->prox)//lista inválida, pos inválida
        return 0;
    *estudante = list->alunos[pos]; //devolvo os dados que estão na posição informada 
    return 1;
}

int consultaMatricula(Lista* list, int nroMat, struct aluno *estudante){//consulta pelo norMatricula
    if(list == NULL)//lista inválida
        return 0;
    int i = 0;
    while(i<list->prox && list->alunos[i].matricula != nroMat)//busca o elemento e recupera sua pos
        i++;
    if(i == list->prox)//final da lista e elemento nao encontrado
        return 0;

    *estudante = list->alunos[i];//devolvo os dados da posição encontrada dentro da estrutura auxiliar.
    return 1;
}

void imprimeLista(Lista* list){
    if(list == NULL)
        return;
    int i;
    printf("\n\n\t\tDADOS DE ALUNOS\n");
	printf("\t-------------------------------\n\n");    
    for(i=0; i< list->prox; i++){
		printf("\tMatricula: %d\n",list->alunos[i].matricula);
        printf("\tNome: %s\n",list->alunos[i].nome);
        printf("\tNotas: N1 = %4.2f; N2 = %4.2f e N3 = %4.2f\n",list->alunos[i].n1, list->alunos[i].n2, 
																					list->alunos[i].n3);
        printf("\t-------------------------------\n");
    }
}

void apagaLista(Lista* list){
    free(list);
}
