#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int q[MAX];
int front = -1, rear = -1;
int n;

void enqueue(int item) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    q[++rear] = item;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return q[front++];
}

void dfs(int v) {
    printf("%d ", v);
    visited[v] = true;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

void bfs(int start) {
    for (int i = 0; i < n; i++) visited[i] = false;

    enqueue(start);
    visited[start] = true;

    while (front <= rear && front != -1) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int i, j, startNode;

    printf("Dugum sayisi: ");
    scanf("%d", &n);

    printf("Matris degerlerini girin:\n");
    for (i = 0; i < n; i++) {
        visited[i] = false;
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Baslangic dugumu (0-%d arasi): ", n-1);
    scanf("%d", &startNode);

    printf("DFS Sonucu: ");
    dfs(startNode);
    printf("\n");

    printf("BFS Sonucu: ");
    bfs(startNode);
    printf("\n");

    return 0;
}