#include <stdio.h>
//max heap kodu, buyuktur kucuktur isaretlerini yer degisitrince min heap olur
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int array[], int size, int i) {
    if (size == 1) {
        printf("Tek eleman var\n");
    } else {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < size && array[l] > array[largest])
            largest = l;

        if (r < size && array[r] > array[largest])
            largest = r;

        if (largest != i) {
            swap(&array[i], &array[largest]);
            heapify(array, size, largest);
        }
    }
}

void insert(int array[], int *size, int newNum) {
    if (*size == 0) {
        array[0] = newNum;
        *size += 1;
    } else {
        array[*size] = newNum;
        *size += 1;
        for (int i = *size / 2 - 1; i >= 0; i--) {
            heapify(array, *size, i);
        }
    }
}

void deleteRoot(int array[], int *size) {
    int i;
    int lastElement = array[*size - 1];
    array[0] = lastElement;
    *size -= 1;
    heapify(array, *size, 0);
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int array[100];
    int size = 0;
    int choice, val;

    while(1) {
        printf("1. Ekle (Max Heap)\n2. Sil (Kok)\n3. Yazdir\n4. Cikis\nSecim: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Sayi girin: ");
            scanf("%d", &val);
            insert(array, &size, val);
        }
        else if(choice == 2) {
            deleteRoot(array, &size);
        }
        else if(choice == 3) {
            printArray(array, size);
        }
        else if(choice == 4) {
            break;
        }
    }
    return 0;
}