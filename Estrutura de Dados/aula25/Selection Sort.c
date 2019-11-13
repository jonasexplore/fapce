#include <stdio.h>

void selection_sort(int num[], int tam) {
  tam = 16; 
  int i, j, min, aux;
  for (i = 0; i < (tam-1); i++) 
  {
     min = i;
     for (j = (i+1); j < tam; j++) {
       if(num[j] < num[min]) 
         min = j;
     }
     if (num[i] != num[min]) {
       aux = num[i];
       num[i] = num[min];
       num[min] = aux;
     }
  }
  for(int k = tam-1; k >= 0; k--){
    printf("%d", num[k]);
  }
}

int main(void) {
  int vet[] = {3,4,9,2,5,8,2,1,7,4,6,2,9,8,5,1};
  selection_sort(vet, 16);

  return 0;
}


