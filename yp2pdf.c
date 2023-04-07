#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


char* getInput();
bool testInput(char* input);
int strToInt(char* input);

int main() {
    char* input = getInput();
    bool isValidInput = testInput(input);
    
    if (isValidInput) {
        int num = strToInt(input);
        printf("The input is valid and its integer value is %d\n", num);
    }
    else {
        printf("The input is not valid\n");
    }
    
    return 0;
}

char* getInput() {
    char* input = (char*) malloc(100 * sizeof(char));
    printf("Enter a string: ");
    scanf("%s", input);
    return input;
}

bool testInput(char* input) {
    char* endPtr;
    strtol(input, &endPtr, 10);
    return (*endPtr == '\0');
}

int strToInt(char* input) {
    return atoi(input);
}
