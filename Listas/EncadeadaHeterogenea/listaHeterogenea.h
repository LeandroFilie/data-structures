struct retangulo { // 1
    float base, altura;
};

struct triangulo { // 2
    float base, altura;
};

struct circulo { // 3
    float raio;
};

typedef struct tipoNo *Lista;

Lista* criaLista();

int insereRetangulo(Lista *inicio, float base, float altura);

int insereCirculo(Lista *inicio, float raio);

int insereTriangulo(Lista *inicio, float base, float altura);

void imprimeLista(Lista *inicio);
