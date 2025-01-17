//PROGRAM TO READ 2D METRICES FROM CONSOLE, VERIFYING IF MULTIPLICATION IS POSSIBLE OR NOT .THEN MULTIPLYING TO GET 3RD METRICS
   #include <stdio.h>

    int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter number of rows for matrix 1: ");
    scanf("%d", &rows1);
    printf("Enter number of columns for matrix 1: ");
    scanf("%d", &cols1);

    printf("Enter number of rows for matrix 2: ");
    scanf("%d", &rows2);
    printf("Enter number of columns for matrix 2: ");
    scanf("%d", &cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible.\n");
        return 1;
    }

    int matrix1[rows1][cols1], matrix2[rows2][cols2], result[rows1][cols2];

    printf("Enter elements of matrix 1:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of matrix 2:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("Resultant matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
