#include <stdio.h>
#include <stdlib.h>
#include "listaHeterogenea.h"

int main() {
    Lista *inicio = criaLista();

    insereRetangulo(inicio, 1, 5);
    insereCirculo(inicio,2);
    insereTriangulo(inicio, 13, 16+1);

    imprimeLista(inicio);
}
