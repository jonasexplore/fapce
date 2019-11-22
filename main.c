#include <stdio.h>
#include <stdlib.h>
 
// Define uma constante
// Define a constant
#define MAX 10
 
// Protótipo da função de ordenação
// Ordination function prototype
void shell_sort(int *a, int size);
 
// Função main
// Main Function
int main(int argc, char** argv)
{
 int i, vet[MAX];
 
 // Lê MAX ou 10 valores
 // Read MAX or 10 values
 for(i = 0; i < MAX; i++)
 {
  printf("Digite um valor: ");
  scanf("%d", &vet[i]);
 }
 
 // Ordena os valores
 // Order values
 shell_sort(vet, MAX);
 
 // Imprime os valores ordenados
 // Print values in order ascendant
 printf("nnValores ordenadosn");
 for(i = 0; i < MAX; i++)
 {
  printf("%dn", vet[i]);
 }
 system("pause");
 return 0;
}
 
// Função de ordenação Shell
// Shellsort function
void shell_sort(int *a, int size)
{
 int i , j , value;
 int gap = 1;
  
 do {
  gap = 3*gap+1;
 } while(gap < size);
  
 do {
  gap /= 3;
  for(i = gap; i < size; i++) {
   value = a[i];
   j = i - gap;
    
   while (j >= 0 && value < a[j]) {
    a[j + gap] = a[j];
    j -= gap;
   }
   a[j + gap] = value;
  }
 }while(gap > 1);
}