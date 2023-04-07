
#include <stdio.h>
#include <stdbool.h>

int main() {
    int x, y;
    bool isInShadedArea;
    
    printf("Enter the coordinates (x,y): ");
    scanf("%d %d", &x, &y);
    
    isInShadedArea = (y >= -2 * x && x <= 4 && y <= 3);
    
    if (isInShadedArea) {
        printf("The point (%d,%d) is in the shaded area\n", x, y);
    } else {
        printf("The point (%d,%d) is not in the shaded area\n", x, y);
    }
    
    return 0;
}
