#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listaHeterogenea.h"

struct tipoNo {
    void *dado;
    int tipo; // 1-Retangulo | 2-Circulo | 3-Triangulo
    struct tipoNo *prox;
};

typedef struct tipoNo noLista;

typedef struct retangulo Retangulo;
typedef struct triangulo Triangulo;
typedef struct circulo Circulo;

Lista* criaLista(){
    Lista *list = (Lista*) malloc(sizeof(Lista));

    if(list != NULL) *list = NULL;

    return list;
}

int insereRetangulo(Lista *inicio, float base, float altura){
    if(inicio == NULL) return;

    noLista *novoNo = (noLista*) malloc(sizeof(noLista));

    if(novoNo == NULL) return;

    Retangulo *r = (Retangulo*) malloc(sizeof(sizeof(Retangulo)));

    if(r == NULL) return;

    r->altura = altura;
    r->base = base;

    novoNo->tipo = 1;
    novoNo->dado = r;
    novoNo->prox = (*inicio);
    *inicio = novoNo;

    return 1;
}

int insereCirculo(Lista *inicio, float raio){
    if(inicio == NULL) return;

    noLista *novoNo = (noLista*) malloc(sizeof(noLista));

    if(novoNo == NULL) return;

    Circulo *c = (Circulo*) malloc(sizeof(sizeof(Circulo)));

    if(c == NULL) return;

    c->raio = raio;

    novoNo->tipo = 2;
    novoNo->dado = c;
    novoNo->prox = (*inicio);
    *inicio = novoNo;

    return 1;
}

int insereTriangulo(Lista *inicio, float base, float altura){
    if(inicio == NULL) return;

    noLista *novoNo = (noLista*) malloc(sizeof(noLista));

    if(novoNo == NULL) return;

    Triangulo *t = (Triangulo*) malloc(sizeof(sizeof(Triangulo)));

    if(t == NULL) return;

    t->altura = altura;
    t->base = base;

    novoNo->tipo = 3;
    novoNo->dado = t;
    novoNo->prox = (*inicio);
    *inicio = novoNo;

    return 1;
}

float calculaAreaRetangulo(float base, float altura){
    return (base*altura);
}

float calculaAreaTriangulo(float base, float altura){
    return (base*altura) / 2;
}

float calculaAreaCirculo(float raio){
    return (raio*raio)*M_PI;
}

void imprimeLista(Lista *inicio){
    if(inicio == NULL) return;

    noLista *aux = *inicio;

    while(aux != NULL){
        if(aux->tipo == 1){
            Retangulo *r = (Retangulo*) aux->dado;
            printf("Retangulo\nBase: %.2f\nAltura: %.2f\nArea: %.2f\n\n", r->base, r->altura, calculaAreaRetangulo(r->base, r->altura));

        } else if(aux->tipo == 2){
            Circulo *c = (Circulo*) aux->dado;
            printf("Circulo\nRaio: %.2f\nArea: %.2f\n\n", c->raio, calculaAreaCirculo(c->raio));

        } else {
            Triangulo *t = (Triangulo*) aux->dado;
            printf("Triangulo\nBase: %.2f\nAltura: %.2f\nArea: %.2f\n\n", t->base, t->altura, calculaAreaTriangulo(t->base, t->altura));

        }
        aux = aux->prox;
    }
}
