#include <stdio.h>

int main() {
    int arr[100];
    int n, i, pos, val, choice;

    printf("Dizi kac elemanli olsun: ");
    scanf("%d", &n);

    printf("Elemanlari girin:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n1. Ekleme\n2. Silme\nSecim yapin: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Hangi siraya eklenecek: ");
        scanf("%d", &pos);
        printf("Hangi sayi eklenecek: ");
        scanf("%d", &val);

        for (i = n - 1; i >= pos - 1; i--) {
            arr[i + 1] = arr[i];
        }
        arr[pos - 1] = val;
        n++;
    } 
    else if (choice == 2) {
        printf("Kacinci siradaki eleman silinsin: ");
        scanf("%d", &pos);

        if (pos <= n) {
            for (i = pos - 1; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;
        }
    }

    printf("Guncel Dizi:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}