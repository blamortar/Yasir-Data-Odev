#include <stdio.h>

int main() {
    int i, j, rows, cols;
    int count = 0;

    printf("Satir sayisini girin: ");
    scanf("%d", &rows);
    printf("Sutun sayisini girin: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    printf("Matris elemanlarini girin:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            if(matrix[i][j] != 0) {
                count++;
            }
        }
    }

    int sparseMatrix[count + 1][3];

    sparseMatrix[0][0] = rows;
    sparseMatrix[0][1] = cols;
    sparseMatrix[0][2] = count;

    int k = 1;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(matrix[i][j] != 0) {
                sparseMatrix[k][0] = i;
                sparseMatrix[k][1] = j;
                sparseMatrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    printf("\nSparse Matrix:\n");
    printf("Row\tCol\tValue\n");
    for(i = 0; i <= count; i++) {
        printf("%d\t%d\t%d\n", sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
    }

    return 0;
}