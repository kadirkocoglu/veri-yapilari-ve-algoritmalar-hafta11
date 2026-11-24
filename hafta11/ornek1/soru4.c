#include <stdio.h>
#include <stdbool.h>

#define N 6

void bipartiteKontrol(int adjMatrix[N][N]) {
    int uzaklik[N];
    int renk[N]; // 0: Mavi (Cift), 1: Kirmizi (Tek)

    for (int i = 0; i < N; i++) {
        uzaklik[i] = -1;
        renk[i] = -1;
    }

    int kuyruk[N];
    int front = 0, rear = 0;

    
    uzaklik[0] = 0;
    renk[0] = 0;
    kuyruk[rear++] = 0;

    bool isBipartite = true;

    while (front < rear) {
        int u = kuyruk[front++];

        for (int v = 0; v < N; v++) {
            if (adjMatrix[u][v] == 1) {
                if (uzaklik[v] == -1) {
                    uzaklik[v] = uzaklik[u] + 1;
                    renk[v] = uzaklik[v] % 2;
                    kuyruk[rear++] = v;
                } else if (renk[v] == renk[u]) {
                    isBipartite = false;
                    printf("[!] Cakisma Tespit Edildi: %d. Dugum ve %d. Dugum ayni renge/pariteye (%d) sahip!\n",
                           u + 1, v + 1, renk[u]);
                }
            }
        }
    }

    printf("\nDugum Durumlari:\n");
    for (int i = 0; i < N; i++) {
        printf("%d. Dugum -> Uzaklik: %d | Parite/Renk: %d (%s)\n",
               i + 1, uzaklik[i], renk[i], renk[i] == 0 ? "Cift / Mavi" : "Tek / Kirmizi");
    }

    printf("\nSonuc: %s\n", isBipartite ? "Graf Iki Parcalidir (Bipartite)." : "Graf Iki Parcali Degildir (Bipartite Degil).");
}

int main() {
    int adjMatrix[N][N] = {
        {0, 1, 0, 1, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 1, 0, 1, 0}
    };

    // Dinamik Test: Kenar listesine (2, 4) baglantisi ekleniyor (indeks 1 ve 3)
    int u = 2, v = 4;
    adjMatrix[u - 1][v - 1] = 1;
    adjMatrix[v - 1][u - 1] = 1;

    printf("Kenar listesine (%d, %d) baglantisi eklendi...\n\n", u, v);
    bipartiteKontrol(adjMatrix);

    return 0;
}