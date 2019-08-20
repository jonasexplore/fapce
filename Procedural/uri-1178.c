#include <stdio.h>

int main(int argc, char const *argv[])
{
	double vet[100];


	scanf("%lf", &vet[0]);

	for (int i = 1; i < 100; i++) vet[i] = vet[i-1]/2;			
	for (int i = 0; i < 1000; i++) printf("%.4lf\n", vet[i]);
	return 0;
}
