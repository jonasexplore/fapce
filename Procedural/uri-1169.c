#include <stdio.h>

int qtdRise(int houses);
int calcKg(int rise);

int main(int argc, char const *argv[])
{
	int requisit = 0;	

	scanf("%i", &requisit);

	int vet[requisit];

	for (int i = 0; i < requisit; i++){
		scanf("%d", &vet[i]);	
	}

  for (int i = 0; i < requisit; i++){
    printf("%d Kg\n", calcKg(qtdRise(vet[i])));
  }
	return 0;
}

// Amount of rise.
int qtdRise(int houses){
	int qtd = 1;
  if (houses == 1) return 1;
  else {
    for (int i = 0; i < houses; i++){
      qtd *= 2;
    }
  }
	return qtd;
}

// Amount in KG.
int calcKg(int rise){
	float gramas = 0;
	gramas = rise/12;
	return gramas/1000;
}
