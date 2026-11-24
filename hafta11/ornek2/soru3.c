#include <stdio.h>

#define N 6
#define INF 99999

const char dugumler[N] = {'A', 'B', 'C', 'D', 'E', 'F'};


int dijkstraToplamMaliyet(int graf[N][N], int kok, int dist[]) {
    int known[N] = {0};

    for (int i = 0; i < N; i++) {
        dist[i] = INF;
    }
    dist[kok] = 0;

    for (int adim = 0; adim < N; adim++) {
        int minMaliyet = INF;
        int u = -1;

        for (int i = 0; i < N; i++) {
            if (!known[i] && dist[i] < minMaliyet) {
                minMaliyet = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        known[u] = 1;

        for (int v = 0; v < N; v++) {
            if (!known[v] && graf[u][v] != INF && dist[u] + graf[u][v] < dist[v]) {
                dist[v] = dist[u] + graf[u][v];
            }
        }
    }

    int toplam = 0;
    for (int i = 0; i < N; i++) {
        toplam += dist[i];
    }
    return toplam;
}

int main() {
    int graf[N][N] = {
        // A    B    C    D    E    F
        {  0,   7,   5, INF, INF,   1}, // A
        {  7,   0,   1,   1,   3, INF}, // B
        {  5,   1,   0,   2,   1, INF}, // C
        {INF,   1,   2,   0, INF,   7}, // D
        {INF,   3,   1, INF,   0,   2}, // E
        {  1, INF, INF,   7,   2,   0}  // F
    };

    int toplamMaliyetler[N];
    int dist[N];
    int minToplamMaliyet = INF;

    printf("Kok Dugum   A   B   C   D   E   F  | Toplam Maliyet\n");
    printf("-----------------------------------------------------\n");

    
    for (int kok = 0; kok < N; kok++) {
        toplamMaliyetler[kok] = dijkstraToplamMaliyet(graf, kok, dist);

        printf("    %c     ", dugumler[kok]);
        for (int j = 0; j < N; j++) {
            printf("%3d ", dist[j]);
        }
        printf(" |      %2d\n", toplamMaliyetler[kok]);

        if (toplamMaliyetler[kok] < minToplamMaliyet) {
            minToplamMaliyet = toplamMaliyetler[kok];
        }
    }

    printf("\nEn Dusuk Toplam Maliyet: %d\n", minToplamMaliyet);
    printf("En Merkezi Dugum(ler) (Ana Aktarma Merkezi): ");
    for (int i = 0; i < N; i++) {
        if (toplamMaliyetler[i] == minToplamMaliyet) {
            printf("%c ", dugumler[i]);
        }
    }
    printf("\n");

    return 0;
}