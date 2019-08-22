#include <stdio.h>
#include <stdlib.h>
#define TAM 100

void main() {
    int array[TAM], seq, c1 = 1, c2 = 0, aux = 0, num = 0, impar = 0, par = 0, M50 = 0;

    for (int c = 0; c < TAM; c++) {
        array[c] = 0;
    }
    do {
        printf("Informe o tamanho da sequência a ser inserida, são permitidos até 100 numeros.\n# ");
        scanf("%i", &seq);
        if (seq > TAM || seq < 1) printf("\nDigite um valor entre 1 e 100\n");
        else break;
    } while (c1);
    for (int i = 0; i < seq; i++) {
        c1 = 0;
        do {
            do {
                printf("Informe o número: ");
                scanf("%i", &array[i]);
                if (array[i] > 255 || array[i] < 1) printf("\tValores permitidos entre 1 e 255\n");
                else break;
            } while (c1);

            if (array[i] % 2 == 0) par++;
            else {
                impar++;
                if (array[i] > 50) {
                    M50 = M50 + array[i];
                    c1++;
                }
            }
            c2 = 1;
        } while (c2 != 1);
    }
    for (int i = 0; i < seq; i++) {
        for (int j = i + 1; j < seq; j++) {
            if (array[i] > array[j]) {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
    for (int k = 0; k < seq; k++) printf("%i, ", array[k]);
    printf("\nImpar: %i\nPar: %i", impar, par);
    if (c1 != 0) printf("\nA media de impares maiores que 50 é: %i", M50 / c1);
    else printf("\nNão há numeros impares maiores que 50");
}
