
struct elemento{
    int matricula;
    char nome[40];
    float n1, n2, n3;
};

typedef struct tipoNo *Lista;

Lista* criaLista();

int consultaPosicao(Lista* inicio, int pos, struct elemento *aluno);
int consultaMatricula(Lista* inicio, int mat, struct elemento *aluno);

int insereFinal(Lista* inicio, struct elemento aluno);
int insereInincio(Lista* inicio, struct elemento aluno);
int insereOrdenada(Lista* inicio, struct elemento aluno);

int removeMatricula(Lista* inicio, int mat);
int removeInicio(Lista* inicio);
int removeFinal(Lista* inicio);

int tamLista(Lista* inicio);
int listaVazia(Lista* inicio);
void imprimeLista(Lista* inicio);
void apagalista(Lista* inicio);

