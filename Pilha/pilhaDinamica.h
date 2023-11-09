struct elemento{
    int matricula;
    char nome[40];
    float n1, n2, n3;
};

typedef struct tipoNo *Pilha; //PONTEIRO P/ PONTEIRO **, 
								//conforme usado na lista dinâmica

Pilha* criaPilha();

void apagaPilha(Pilha* topo);

int push(Pilha* topo, struct elemento aluno);

void imprimePilha(Pilha* topo);

int pop(Pilha* topo);

int consultaTopoPilha(Pilha* topo, struct elemento *aluno);

int tamPilha(Pilha* topo);

int pilhaVazia(Pilha* topo);




