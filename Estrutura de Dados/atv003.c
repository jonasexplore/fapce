#include <stdio.h>

#define banana "banana"
#define uva "uva"
#define pessego "pessego"

void main(){
	float vlBanana, vlUva, vlPessego, vlTotal, vlImposto;
	int qtdBanana, qtdUva, qtdPessego;

	printf("Valor banana: ");
	scanf("%f", &vlBanana);
	printf("Quantidade: ");
	scanf("%i", &qtdBanana);
	printf("Valor uva: ");
	scanf("%f", &vlUva);
	printf("Quantidade: ");
	scanf("%i", &qtdUva);
	printf("Valor pessego: ");
	scanf("%f", &vlPessego);
	printf("Quantidade: ");
	scanf("%i", &qtdPessego);

	vlTotal = (vlBanana*qtdBanana)+(vlUva*qtdUva)+(vlPessego*qtdPessego);
    printf("----------------------------------------------------------------\n");
	printf("Produtos\t| Preco unitario | Quantidade | Preco Total\n");
	printf("----------------------------------------------------------------\n");
	printf("banana  \t| %10.2f| %10i| %10.2f|\n", vlBanana, qtdBanana, (vlBanana*qtdBanana));
	printf("Uva     \t| %10.2f| %10i| %10.2f|\n", vlUva, qtdUva, (vlUva*qtdUva));
	printf("Pessego \t| %10.2f| %10i| %10.2f|\n", vlPessego, qtdPessego, (vlPessego*qtdPessego));
	printf("\nSub-total\t| %10.2f\n", vlTotal);
	printf("-------------------------------------------------\n");
	printf("\t\t\tImposto (5%) %.2f\n",vlTotal*0.05);
	printf("\t\t\tTotal %.2f\n", (vlTotal+vlTotal*0.05));

}
