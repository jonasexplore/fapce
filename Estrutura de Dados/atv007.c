/*
* Atividade de Estrutura de dados
* Verificando se uma palavra é um palindromo.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAVBAR "###########################"

typedef struct {
    char palavra[24];
    int letras;
} pilha;

void criarPilha(pilha *p){
    /* Criando a pilha incializando a variável letra. */
    if(p -> letras == -1) p -> letras = 0;
}

void inserirPalavraPilha(pilha *p, char palavra[24]){
    for(int tamanho = 0; tamanho < strlen(palavra); tamanho++, p -> letras++) p -> palavra[p -> letras] = palavra[p -> letras];
}

int palindromo(pilha *p){
    int resultado = 1, tamanho = p -> letras;
    for(int i = 0; i < strlen(p -> palavra); i++, tamanho--){
        if(p -> palavra[i] != p -> palavra[tamanho-1]){
            resultado = 0;
            break;
        }
    }    
    return (resultado == 1)? 1:0;
}

void main(){
    char palavra[24];
    pilha *p = malloc(100); 
    
    p -> letras = 0;
    do {
        printf("%s\n# [Olá, seja bem vindo]\n# Informe uma palavra de ate 24 caracteres: ", NAVBAR);
        scanf("%s", palavra);
    } while(strlen(palavra) > 24);
   
    criarPilha(p);
    inserirPalavraPilha(p, palavra);
    
    if(palindromo(p)) printf("\n%s e um palindromo!\n", palavra);
    else printf("\n%s nao e um palindromo!\n", palavra);
    
    free(p);
   
}
