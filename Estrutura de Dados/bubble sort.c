#include <stdio.h>
#include <stdlib.h>

int *ordenador(int *array){
  int aux;
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      if (array[i] > array[j]) {
        aux = array[i];
        array[i] = array[j];
        array[j] = aux;
      } else continue;
    }
  }
  return (array);
}

int main(void) {
  int vetor[20] = {3, 4, 9, 2, 5, 8, 2, 1, 7, 4, 6, 2, 9, 8, 5, 1};
  ordenador(vetor);
  for (int i = 0; i < 16; i++)
    printf("%i", vetor[i]);
  return 0;
}
