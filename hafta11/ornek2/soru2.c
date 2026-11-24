#include <stdio.h>
#include <stdbool.h>

#define N 6
#define INF 99999

const char dugumler[N] = {'A', 'B', 'C', 'D', 'E', 'F'};


void terstenRotaYazdir(int path[], int dist[], int kok, int hedef) {
    int yigin[N];
    int sayac = 0;
    int mevcut = hedef;

    
    while (mevcut != -1) {
        yigin[sayac++] = mevcut;
        mevcut = path[mevcut];
    }

    printf("%c -> %c En Dusuk Maliyetli Yol: ", dugumler[kok], dugumler[hedef]);
    
    for (int i = sayac - 1; i >= 0; i--) {
        printf("%c", dugumler[yigin[i]]);
        if (i > 0) {
            printf(" -> ");
        }
    }
    printf(" | Toplam Maliyet: %d\n", dist[hedef]);
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

    int known[N] = {0};
    int dist[N];
    int path[N];

    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        path[i] = -1;
    }

    int kok = 0; 
    dist[kok] = 0;

    
    for (int adim = 0; adim < N; adim++) {
        int minMaliyet = INF, u = -1;
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
                path[v] = u;
            }
        }
    }

    
    printf("Kok Dugum: %c\n\n", dugumler[kok]);
    terstenRotaYazdir(path, dist, kok, 1); 
    terstenRotaYazdir(path, dist, kok, 3); 

    return 0;
}