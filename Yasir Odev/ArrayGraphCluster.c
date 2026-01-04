#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int n;

void dfs(int v) {
    visited[v] = true;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int i, j;
    int clusterCount = 1;

    printf("Dugum sayisini girin: ");
    scanf("%d", &n);

    printf("Komsuluk matrisini girin:\n");
    for (i = 0; i < n; i++) {
        visited[i] = false;
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("\nBulunan Clusterlar:\n");
    for (i = 0; i < n; i++) {
        if (visited[i] == false) {
            printf("Cluster %d: ", clusterCount);
            dfs(i);
            printf("\n");
            clusterCount++;
        }
    }

    return 0;
}