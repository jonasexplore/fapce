#include <stdio.h>

int main(int argc, char const *argv[])
{
	int vet[20];
  int num = 0.0;
  int j = 19;

	for (int i = 0; i < 20; i++){
		scanf("%d", &vet[i]);
	}
	for (int i = 0; i < 10; i++){
      num = vet[i];
      vet[i] = vet[j];
      vet[j] = num;
      j--;
	}
	for (int i = 0; i < 20; ++i){
		printf("%d\n", vet[i]);
	}
	return 0;
}
