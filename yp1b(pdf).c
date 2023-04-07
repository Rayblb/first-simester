#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int x, y;
    bool isInShadedArea;
    float circle_x = 5.0, circle_y = 5.0, radius = 5.0;


    printf("Enter the coordinates (x,y): ");
    scanf("%d %d", &x, &y);


    if ( x <= circle_x) {
        float distance = sqrt(pow(x - circle_x, 2) + pow(y - circle_y, 2));
        if (distance <= radius) {
            isInShadedArea = false;
        } else {
            isInShadedArea = true;
        }
    } else {
        isInShadedArea = false;
    }

    if (isInShadedArea) {
        printf("The point (%d,%d) is in the shaded area\n", x, y);
    } else {
        printf("The point (%d,%d) is not in the shaded area\n", x, y);
    }

    return 0;
}
