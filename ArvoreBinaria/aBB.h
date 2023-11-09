
typedef struct no* arvoreBinaria;

arvoreBinaria* criaArvBin();

void liberaArvBin(arvoreBinaria *raiz);

int insereOrdenadoArvBin(arvoreBinaria* raiz, int valor);

int removeArvBin(arvoreBinaria *raiz, int valor);

int estaVaziaArvBin(arvoreBinaria *raiz);

void preOrdemArvBin(arvoreBinaria *raiz);

int igual(arvoreBinaria* a, arvoreBinaria* b);
