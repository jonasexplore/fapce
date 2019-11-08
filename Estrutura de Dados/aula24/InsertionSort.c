#include <stdio.h>
#include <stdlib.h>

/* Variáveis de controle */
int insertValue = 1;

int main() {
  int arry[] = {2, 3, 5, 1, 4}, i, j, k, value;

  for(j = 1; j < sizeof(arry) / sizeof(int); j++){
    value = arry[j];

    for(k = j - 1; k >= 0 && arry[k] > value; k--) arry[k+1] = arry[k];

    arry[k+1] = value;
  }

  for(int i = 0; i < sizeof(arry) / sizeof(int); i++){
    printf("%d\n", arry[i]);
  }
  
  return 0;
}
