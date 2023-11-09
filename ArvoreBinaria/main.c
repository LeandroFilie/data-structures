#include <stdio.h>
#include <stdlib.h>
#include "aBB.h"

main()
{
    arvoreBinaria* a = criaArvBin();
    insereOrdenadoArvBin(a, 4);
    insereOrdenadoArvBin(a, 8);
    insereOrdenadoArvBin(a, 7);
    insereOrdenadoArvBin(a, 5);

    arvoreBinaria* b = criaArvBin();
    insereOrdenadoArvBin(b, 4);
    insereOrdenadoArvBin(b, 8);
    insereOrdenadoArvBin(b, 7);
    insereOrdenadoArvBin(b, 5);

    printf("Arvore A: \n");
    preOrdemArvBin(a);

    printf("\nArvore B: \n");
    preOrdemArvBin(b);

    int arvoresIguais = igual(a, b);

    if(arvoresIguais == 1){
        printf("\nArvores iguais\n");
    } else {
        printf("\nArvores diferentes\n");
    }

}
