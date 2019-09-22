#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAVBAR "###########################"

typedef struct {
    char palavra[24];
    int letras;
} pilha;

typedef struct {
    pilha *item[10];
    int proximo;
    int anterior;
} lista;

void adicionarPilha(lista *l){
    l ->item[l -> proximo] = malloc(100);
    l -> item[l -> proximo] -> letras = 0;
    l -> proximo++;
}

void criarPilha(pilha *p){
    /* Criando a pilha incializando a variável letra. */
    if(p -> letras == -1) p -> letras = 0;
}

void inserirPalavraPilha(pilha *p, char palavra[24]){
    for(int tamanho = 0; tamanho < strlen(palavra); tamanho++, p -> letras++) p -> palavra[p -> letras] = palavra[p -> letras];
}


void main(){
    char palavra[24];
    int opcao, idPilha;
    lista *l = malloc(100);
    while(1){
        printf("\n# Bem vindo.\n# Voce pode criar ate 10 pilhas.\n"
                "# Em cada pilha você pode armazenar uma palavra."
                "# [1] Criar Pilha\n# [2] Inserir dados\n"
                "# [3] Excluir pilha\n# [4] ver pilhas\n# [5] sair\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:{
                adicionarPilha(l);
                printf("Pilha %d criada.", l -> proximo);
                break;
            }
            case 2:{
                printf("Informe qual pilha deseja manipular: ");
                scanf("%d", &idPilha);
                printf("Informe o a palavra de ate 24 caracteres: ");
                scanf("%s", palavra);

                inserirPalavraPilha(l -> item[idPilha-1], palavra);
                break;
            }
            case 3:{
                printf("Informe qual pilha deseja deletar: ");
                scanf("%d", &idPilha);
                l -> item[idPilha-1] = NULL;
                l -> proximo--;
                printf("Pilha %d deletada.", idPilha);
                break;
            }
            case 4:{
                printf("Informe qual pilha deseja visualizar: ");
                scanf("%d", &idPilha);
                printf("%s", l -> item[idPilha-1] -> palavra);
                break;
            }
            case 5:{
                exit(-1);
            }

        }
    }
}
