#include <stdio.h>
#include <stdlib.h>

#define NAVBAR "##########################"
#define MAXLENGHT 15

typedef struct matrizmain {
    int matone[MAXLENGHT][MAXLENGHT];
    int mattwo[MAXLENGHT][MAXLENGHT];
    int matthr[MAXLENGHT][MAXLENGHT];
}matri;

struct matrizmain mtr;

int matriz1[MAXLENGHT][MAXLENGHT];
int matriz2[MAXLENGHT][MAXLENGHT];

int ordem = 0;
int option = 0;

void showMenu();
void execMenu(int option);


int **getMatriz(int **mtr);
void showMatriz(int **mtr);
void execSum(int **mtr1, int **mtr2);
void execMult(int **mtr1, int **mtr2);
float execDeter(int **mtr);
void gaussjordan();

int main(int argc, char** argv) {
    //matr();
    showMenu();
    return (EXIT_SUCCESS);
}

void showMenu() {
    printf(
            "\n"
            "\n%s"
            "\n[1] Somar matrizes"
            "\n[2] Encontrar determinante"
            "\n[3] Multiplicar Matrizes"
            "\n[4] Verificar se é singular"
            "\n[5] Metodo de Gauss-Jordan"
            "\n[6] Sair\n"
            "Opção: ", NAVBAR
            );
    scanf("%d", &option);
    execMenu(option);
}

void execMenu(int option) {
    if ((option >= 1) && (option < 5) && (option != 3)) {
        printf("Defina a ordem das matrizes: ");
        scanf("%d", &ordem);
    }
    switch (option) {
        case 1:
        {
            printf("Informe a primeira matriz: ");
            getMatriz(&mtr.matone);
            printf("Informe a segunda matriz: ");
            getMatriz(&mtr.mattwo);

            execSum(&mtr.matone, &mtr.mattwo);
            showMenu();
            break;
        }
        case 2:
        {
            printf("Informe a matriz: ");
            getMatriz(&mtr.matone);
            execDeter(&mtr.matone);
            showMenu();
            break;
        }
        case 3:
        {
            execMult(&mtr.matone, &mtr.mattwo);
            showMenu();
            break;
        }
        case 4:
        {
            printf("informe a matriz: ");
            getMatriz(&mtr.matone);
            if (execDeter(&mtr.matone) == 0) {
                printf("A matriz é singular.");
            } else {
                printf("A matriz não é singular.");
            }
            showMenu();
            break;
        }
        case 5:
        {
            gaussjordan();
            showMenu();
        }
        case 6:{
            exit(0);
        }
    }
}

int **getMatriz(int **mtr) {
    for (int i = 0; i < ordem; i++) {
        mtr[i] = (int *) malloc(ordem * sizeof (mtr[i]));
        for (int j = 0; j < ordem; j++) {
            scanf("%d", &mtr[i][j]);
        }
    }
    return mtr;
}

void showMatriz(int **mtr) {
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            printf("%d ", mtr[i][j]);
        }
        printf("\n");
    }
}

void execSum(int **mtr1, int **mtr2) {
    int matriztemp[MAXLENGHT][MAXLENGHT];
    int **mattemp = (int **) malloc(sizeof (int));
    for (int i = 0; i < ordem; i++) {
        mattemp[i] = (int *) malloc(ordem * sizeof (mattemp[i]));
        for (int j = 0; j < ordem; j++) {
            mattemp[i][j] = mtr1[i][j] + mtr2[i][j];
        }
    }
    printf("# Resultado da soma:\n");
    showMatriz(mattemp);
}

void execMult(int **mtr1, int **mtr2) {
    float result = 0;
    int c1, c2, l1, l2;

    printf("Informe a ordem das matriz: ");
    scanf("%i", &l1);
    c1 = l1;
    l2 = l1;
    c2 = l1;

    if (c1 == c2 && l1 == l2) {
        printf("preencha a primeira matriz\n");
        float m1[l1][c1], m2[l2][c2], m3[l1][c2];
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < c1; j++) {
                scanf("%f", &m1[i][j]);
            }
        }
        printf("preencha a segunda matriz\n");
        for (int i = 0; i < l2; i++) {
            for (int j = 0; j < c2; j++) {
                scanf("%f", &m2[i][j]);
            }
        }
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < c1; j++) {
                for (int k = 0; k < l2; k++) {
                    result += m1[i][k] * m2[k][j];
                }
                m3[i][j] = result;
                result = 0;
            }
        }
        printf("Resultado\n");
        for (int i = 0; i < l2; i++) {
            for (int j = 0; j < c2; j++) {
                printf("|%.0f|", m3[i][j]);
            }
            printf("\n");
        }
    } else printf("Não é possível multiplicar as duas matrizes");
}

float execDeter(int **mtr) {
    // faz a transformação em um triangulo...
    int i = 0, k = 0, j = 0, factor = 0, count = 0;
    float temp = 0;
    for (i = 0; i < ordem - 1; i++) {
        if (mtr[i][i] == 0) {
            for (k = i; k < ordem; k++) {
                if (mtr[k][i] != 0) {
                    for (j = 0; j < ordem; j++) {
                        temp = mtr[i][j];
                        mtr[i][j] = mtr[k][j];
                        mtr[k][j] = temp;
                    }
                    k = ordem;
                }
            }
            count++;
        }

        if (mtr[i][i] != 0) {
            for (k = i + 1; k < ordem; k++) {
                factor = -1.0 * mtr[k][i] / mtr[i][i];
                for (j = i; j < ordem; j++) {
                    mtr[k][j] = mtr[k][j] + (factor * mtr[i][j]);
                }
            }
        }
    }
    temp = 1.0;
    // Calcula o determinante
    for (i = 0; i < ordem; i++)
        temp *= mtr[i][i];
    if (option != 4) {
        printf("\nDeterminante:\n");
        if (count % 2 == 0)
            printf("%8.0f \n", temp);
        else
            printf("%8.3f \n", -1.0 * temp);
    }

    return temp;
}

void gaussjordan() {
    float matriz[100][100];
    float pivo;
    int i, j, k, l, m, tamanho;


    printf("Informe o tamanho da matriz: ");
    scanf("%i", &tamanho);

    printf("informe os numeros da matriz: ");

    //Matriz principal
    for (i = 1; i <= tamanho; i++) {
        for (j = 1; j <= tamanho; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }
    //matriz identidade.
    for (i = 1; i <= tamanho; i++) {
        for (j = 1; j <= tamanho * 2; j++) {
            if (j == (i + tamanho)) matriz[i][j] = 1;
        }
    }
    for (int i = 1; i <= tamanho; i++) {
        for (int j = 1; j <= tamanho * 2; j++) {
            printf("%.0f    ", matriz[i][j]);
        }
        printf("\n");
    }

    for (i = tamanho; i > 1; i--) {
        if (matriz[i - 1][i] < matriz[i][1])
            for (j = 1; j <= tamanho * 2; j++) {
                pivo = matriz[i][j];
                matriz[i][j] = matriz[i - 1][j];
                matriz[i - 1][j] = pivo;
            }
    }

    for (i = 1; i <= tamanho; i++) {
        for (j = 1; j <= tamanho * 2; j++)
            if (j != i) {
                pivo = matriz[j][i] / matriz[i][i];
                for (k = 1; k <= tamanho * 2; k++)
                    matriz[j][k] -= matriz[i][k] * pivo;
            }
    }

    for (i = 1; i <= tamanho; i++) {
        pivo = matriz[i][i];
        for (j = 1; j <= tamanho * 2; j++) {
            matriz[i][j] = matriz[i][j] / pivo;
        }
    }
    printf("\n");
    for (int i = 1; i <= tamanho; i++) {
        for (int j = 1; j <= tamanho * 2; j++) {
            if(matriz[i][j] == 0) matriz[i][j] = abs(matriz[i][j]);
            printf("%.0f    ", matriz[i][j]);
        }
        printf("\n");
    }
}
