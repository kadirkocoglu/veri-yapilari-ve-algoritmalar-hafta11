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

    
    printf("Komsuluk Matrisi:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}