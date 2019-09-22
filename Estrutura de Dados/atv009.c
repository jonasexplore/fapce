#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    float b = 2.50, qb = 2, u = 6.50, qu = 6, p = 10.22, qp = 10, st = 146.20, t = 153.51, i = 7.31;
    printf("Produtos | Preço unitário | Quantidade \t| Preço total\n");
    printf("Banana   | R$ %11.2f | %10.0f \t| R$ 5.00\n", b, qb);
    printf("Uva      | R$ %11.2f | %10.0f \t| R$ 39.00\n", u, qu);
    printf("Pessego  | R$ %11.2f | %10.0f \t| R$ 102.20\n", p, qp);
    printf("\t\t\t\tSubtotal| R$ %.2f\n", st);
    printf("\t\tImposto   | \t\t| R$ %.2f\n", i);
    printf("\t\t\t\tTotal   | %.2f\n", t);
    return (EXIT_SUCCESS);
}

