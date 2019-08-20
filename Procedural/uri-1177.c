#include <stdio.h>

int main(int argc, char const *argv[])
{
	int value = 0;
	int vet[1000];
  int num = 0;


	scanf("%d", &value);

	for (int i = 0; i < 1000; i+=value)
	{
    num = 0;
		for(int j = i; j <= i+value; j++){
			vet[j] = num;
      num++;	
		}	
	}
	for (int i = 0; i < 1000; ++i)
	{
		printf("N[%d] = %d\n", i, vet[i]);
	}
	return 0;
}
