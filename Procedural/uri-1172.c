#include <stdio.h>

int main(int argc, char const *argv[])
{
	int vet[10];

	for (int i = 0; i < 10; ++i){
		scanf("%d", &vet[i]);
		(vet[i] < 1)?(vet[i] = 1):(vet[i]=vet[i]);
	}
	for (int i = 0; i < 10; ++i){
		printf("X[%d] = %d\n", i, vet[i]);
	}
	return 0;
}
