#include <stdio.h>
#define ROWS 4
#define COLS 4

void search_element(int arr[][COLS], int target) {
      int i, j;
    int found = 0;


    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (arr[i][j] == target) {
                printf("Element %d found at row %d, column %d\n", target, i, j);
                found = 1;
            }
        }
    }


    if (!found) {
        printf("Element %d not found in the array\n", target);
    }
}

int main() {
    int arr[ROWS][COLS] = {
        {15, 2, 3, 33},
        {4, 5, 64, 56},
        {74, 83, 92, 66},
        {22 , 33 , 44, 55}
    };
    int target;

    printf("Enter an element to search for: ");
    scanf("%d", &target);

    search_element(arr, target);

    return 0;
}
