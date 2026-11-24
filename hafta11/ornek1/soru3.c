#include <stdio.h>
#include <stdbool.h>

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

    int uzaklik[N];
    int renk[N]; // 0: Mavi (Cift), 1: Kirmizi (Tek)

    for (int i = 0; i < N; i++) {
        uzaklik[i] = -1; 
        renk[i] = -1;
    }

    
    int kuyruk[N];
    int front = 0, rear = 0;

   
    int baslangic = 0;
    uzaklik[baslangic] = 0;
    renk[baslangic] = 0;
    kuyruk[rear++] = baslangic;

    bool isBipartite = true;

    while (front < rear) {
        int u = kuyruk[front++];

        for (int v = 0; v < N; v++) {
            if (adjMatrix[u][v] == 1) {
                
                if (uzaklik[v] == -1) {
                    uzaklik[v] = uzaklik[u] + 1;
                    renk[v] = uzaklik[v] % 2; // Cift -> 0 (Mavi), Tek -> 1 (Kirmizi)
                    kuyruk[rear++] = v;
                } 
                
                else if (renk[v] == renk[u]) {
                    isBipartite = false;
                }
            }
        }
    }

    printf("Dugum Uzakliklari ve Renkleri (Baslangic: 1. Dugum):\n");
    for (int i = 0; i < N; i++) {
        printf("%d. Dugum -> Uzaklik: %d | Parite/Renk: %d (%s)\n",
               i + 1,
               uzaklik[i],
               renk[i],
               renk[i] == 0 ? "Cift / Mavi" : "Tek / Kirmizi");
    }

    printf("\nSonuc: ");
    if (isBipartite) {
        printf("Graf Iki Parcalidir (Bipartite).\n");
    } else {
        printf("Graf Iki Parcali Degildir (Bipartite Degil).\n");
    }

    return 0;
}