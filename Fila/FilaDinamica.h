struct elemento{
    int matricula;
    char nome[40];
    float n1, n2, n3;
};

typedef struct tipoFila Fila; //N�O � PONTEIRO P/ PONTEIRO **

Fila* criaFila();

void apagaFila(Fila* fila);

//consulta apenas 1� n� fila->inicio->dado; 
//n�o faz sentido consultar/retornar outros n�s em fila
int consultaFila(Fila* fila, struct elemento *aluno);

int insereFila(Fila* fila, struct elemento aluno);

void imprimeFila(Fila* fila);

int tamanhoFila(Fila* fila);

int filaVazia(Fila* fila);

int removeFila(Fila* fila);


