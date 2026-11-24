#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define N 6
#define INF 99999


const char dugumler[N] = {'A', 'B', 'C', 'D', 'E', 'F'};


void yoluYazdir(int path[], int hedef) {
    if (path[hedef] == -1) {
        printf("%c", dugumler[hedef]);
        return;
    }
    yoluYazdir(path, path[hedef]);
    printf(" -> %c", dugumler[hedef]);
}


void tabloYazdir(int adim, char secilen, int known[], int dist[], int path[]) {
    printf("\n--- ADIM %d (Secilen Dugum: %c) ---\n", adim, secilen);
    printf("%-8s %-15s %-18s %-12s\n", "Dugum", "Isaret (Known)", "Maliyet (Dist)", "Yol (Path)");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < N; i++) {
        printf("%-8c %-15d ", dugumler[i], known[i]);

        if (dist[i] == INF) {
            printf("%-18s ", "INF");
        } else {
            printf("%-18d ", dist[i]);
        }

        if (path[i] == -1) {
            printf("-\n");
        } else {
            printf("%c\n", dugumler[path[i]]);
        }
    }
}

void dijkstra(int graf[N][N], int kok) {
    int known[N]; 
    int dist[N];  
    int path[N];  

    for (int i = 0; i < N; i++) {
        known[i] = 0;
        dist[i] = INF;
        path[i] = -1;
    }

    dist[kok] = 0;

    for (int adim = 1; adim <= N; adim++) {
        
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
                path[v] = u;
            }
        }

        tabloYazdir(adim, dugumler[u], known, dist, path);
    }

    printf("\n=== %c MERKEZINDEN EN KISA TESLIMAT ROTALARI ===\n", dugumler[kok]);
    for (int i = 0; i < N; i++) {
        printf("%c -> %c | Maliyet: %2d | Rota: ", dugumler[kok], dugumler[i], dist[i]);
        yoluYazdir(path, i);
        printf("\n");
    }
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

    char giris;
    printf("Kok dugumu giriniz (A, B, C, D, E, F): ");
    scanf(" %c", &giris);
    giris = toupper(giris);

    int kokIndeks = -1;
    for (int i = 0; i < N; i++) {
        if (dugumler[i] == giris) {
            kokIndeks = i;
            break;
        }
    }

    if (kokIndeks == -1) {
        printf("Gecersiz dugum! Lutfen A-F arasinda bir harf giriniz.\n");
        return 1;
    }

    dijkstra(graf, kokIndeks);

    return 0;
}