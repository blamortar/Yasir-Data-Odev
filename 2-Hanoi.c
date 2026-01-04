#include <stdio.h>

void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Disk 1 tasi: %c -> %c\n", from_rod, to_rod);
        return;
    }
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Disk %d tasi: %c -> %c\n", n, from_rod, to_rod);
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    printf("Disk sayisini girin: ");
    scanf("%d", &n);
    
    hanoi(n, 'A', 'C', 'B');
    return 0;
}