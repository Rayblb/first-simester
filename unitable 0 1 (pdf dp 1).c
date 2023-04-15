#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 9
#define COLS 7

void print_matrix(int arr[][COLS], int rows) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int com_rows(const void* a, const void* b) {
    const int* row_a = (const int*)a;
    const int* row_b = (const int*)b;

    for (int i = 0; i < COLS; i++) {
        if (row_a[i] < row_b[i]) {
            return -1;
        } else if (row_a[i] > row_b[i]) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int matrix[ROWS][COLS];
    int i, j;

    srand(time(NULL));

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 2;
        }
    }

    printf("Original matrix:\n");
    print_matrix(matrix, ROWS);

    // Sort the rows of the matrix
    qsort(matrix, ROWS, sizeof(matrix[0]), com_rows);

    // Remove duplicate rows
    int n_uni_rows = 0;
    for (i = 1; i < ROWS; i++) {
        int is_duplicate_row = 1;
        for (j = 0; j < COLS; j++) {
            if (matrix[i][j] != matrix[n_uni_rows][j]) {
                is_duplicate_row = 0;
                break;
            }
        }

        if (!is_duplicate_row) {
            n_uni_rows++;
            for (j = 0; j < COLS; j++) {
                matrix[n_uni_rows][j] = matrix[i][j];
            }
        }
    }

    n_uni_rows++;

    printf("Unique matrix:\n");
    print_matrix(matrix, n_uni_rows);

    return 0;
}
