#include <stdio.h>
#define MAX_DEGREE 20

int main() {
    int degree, i, j;
    int pascal[MAX_DEGREE + 1][MAX_DEGREE + 1];

    printf("Enter the degree of the Newton binomial: ");
    scanf("%d", &degree);

    for (i = 0; i <= degree; i++) {
        pascal[i][0] = 1;
    }

    for (i = 1; i <= degree; i++) {
        for (j = 1; j <= i; j++) {
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
    }

 
    for (i = 0; i <= degree; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d ", pascal[i][j]);
        }
        printf("\n");
    }

    return 0;
}

