#include <stdio.h>
#include <stdlib.h>
#define T 10

int pesquisar(int e, int d, int v, int *vet);
int *organizar(int *vet);

int main() {
    int vet[T], aux, search;
    printf("Informe %d valores:\n", T);
    for (int i = 0; i < T; i++) scanf("%d", &vet[i]);
    organizar(vet);

    for (int i = 0; i < T; i++) printf("posicao (%d): valor(%i)\n", i, vet[i]);
}

int *organizar(int *vet) {
    int aux, i, j;

    aux = vet[0];
    for (i = 0; i < T; i++) {
        for (j = i; j < T; j++) {
            if (vet[i] > vet[j]) {
              aux = vet[i];
              vet[i] = vet[j];
              vet[j] = aux;
            }
        }
    }
    return vet;
}
