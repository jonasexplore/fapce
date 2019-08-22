#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int M = 0, H = 0, rpt = 1, count = 0;
    float alt = 0, altH = 0, altM = 0, altMaior = 0;
    char sex;
    do {
        sex = ' ';
        printf("\tCadastro %i\n\n", count + 1);
        printf("\tUse H para Homem e M para muler\nSexo: ");
        setbuf(stdin, NULL);
        scanf("%c", &sex);
        if (sex == 'h' || sex == 'H') H++;
            else if (sex == 'm' || sex == 'M') M++;
        printf("\tUse o formato [ x.x ]\nAltura: ");
        scanf("%f", &alt);
        if (sex == 'h' || sex == 'H') altH += alt;
            else if (sex == 'm' || sex == 'M') altM += alt;
        if (alt > altMaior) altMaior = alt;
        printf("\n\tDigite 1 para continuar e 0 para sair\n#");
        scanf("%i", &rpt);
        count++;
        system("clear");
    } while (rpt != 0 && count < 100);
    printf("\nAltura média das %i pessoas: %.2fm\n", count, ((altH + altM) / count));
    printf("Maior altura encontrada: %.2fm\n", altMaior);
    printf("Altura média das mulheres: %.2fm\n", (M <= 1) ? altM : altM / M);
    printf("Altura média dos homens: %.2fm\n", (H <= 1) ? altH : altH / H);
    printf("Quantidade de homens cadastrados: %i\n", H);
    return (EXIT_SUCCESS);
}
