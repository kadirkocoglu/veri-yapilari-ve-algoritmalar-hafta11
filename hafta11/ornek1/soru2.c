#include <stdio.h>

#define N 6

int main() {
    int adjMatrix[N][N] = {
        {0, 1, 0, 1, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 1, 0, 1, 0}
    };

    int genelDerece = 0;

    printf("Dugum Dereceleri:\n");
    for (int i = 0; i < N; i++) {
        int dugumDerecesi = 0;
        for (int j = 0; j < N; j++) {
            dugumDerecesi += adjMatrix[i][j];
        }
        printf("%d. Dugumun Derecesi: %d\n", i + 1, dugumDerecesi);
        genelDerece += dugumDerecesi;
    }

    printf("\nGrafin Genel Derecesi: %d\n", genelDerece);

    return 0;
}