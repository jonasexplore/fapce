#include <stdio.h>

int main(int argc, char const *argv[])
{
	int num = 0, menor = 0, pos = 0;

	scanf("%i", &num);
	int vet[num];

	for (int i = 0; i < num; ++i){ 
		scanf("%i", &vet[i]);

		if ( i == 0) menor = vet[i];
		if ( vet[i] < menor ){ 
			menor = vet[i]; 
			pos = i;
		}
	}
	printf("Menor valor: %d\nPosicao: %d\n", menor, pos);

	
	return 0;
}
