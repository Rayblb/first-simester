#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORDS_LENGT 10000
#define WORD_LENGT 20

void printArr(char words[WORDS_LENGT][WORD_LENGT]) {
    printf("[ ");
    for(int i=0; i<WORDS_LENGT; i++) {
        printf("%s ", words[i]);
    }
    printf("]\n");
}

void fillArr(char words[WORDS_LENGT][WORD_LENGT]) {
    srand(time(NULL)); // initialize the random seed

    for (int i = 0; i < WORDS_LENGT; i++) {
        for (int j = 0; j < WORD_LENGT-1; j++) {
            words[i][j] = 'a' + rand() % 26; // generate a random lowercase letter
        }
        words[i][WORD_LENGT-1] = '\0'; // add null terminator at the end of each word
    }
}

void selectSort(char words[WORDS_LENGT][WORD_LENGT], int length) {
    int i, j, min_idx, iterations=0;
    char temp[WORD_LENGT];
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Start the timer

    for (i = 0; i < length-1; i++) {
        min_idx = i;
        for (j = i+1; j < length; j++) {
            if (strcmp(words[j], words[min_idx]) < 0) {
                min_idx = j;
            }
            iterations++;
        }

        strcpy(temp, words[min_idx]);
        strcpy(words[min_idx], words[i]);
        strcpy(words[i], temp);
    }

    end = clock(); // End the timer and calculate elapsed time
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Selection Sort:\n");
    // printArr(words);
    printf("Iterations: %d\n", iterations);
    printf("Time taken: %f seconds\n", cpu_time_used);
}

void bubbleSort(char words[WORDS_LENGT][WORD_LENGT], int length) {
    int i, j, iterations=0;
    char temp[WORD_LENGT];
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Start the timer

    for (i = 0; i < length-1; i++) {
        for (j = 0; j < length-i-1; j++) {
            if (strcmp(words[j], words[j+1]) > 0) {
                strcpy(temp, words[j]);
                strcpy(words[j], words[j+1]);
                strcpy(words[j+1], temp);
            }
            iterations++;
        }
    }

    end = clock(); // End the timer and calculate elapsed time
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Bubble Sort:\n");
    // printArr(words);
    printf("Iterations: %d\n", iterations);
    printf("Time taken: %f seconds\n", cpu_time_used);
}

void combSort(char words[WORDS_LENGT][WORD_LENGT], int length) {
    int gap = length;
    int i, j, iterations = 0;
    char temp[WORD_LENGT];
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Start the timer

    do {
        gap = (gap * 10) / 13;
        if (gap < 1) {
            gap = 1;
        }

        for (i = 0; i < length - gap; i++) {
            j = i + gap;

            if (strcmp(words[i], words[j]) > 0) {
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
            iterations++;
        }
    } while (gap > 1);

    end = clock(); // End the timer and calculate elapsed time
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Comb Sort:\n");
    // printArr(words);
    printf("Iterations: %d\n", iterations);
    printf("Time taken: %f seconds\n", cpu_time_used);
}

int main() {
    char words[WORDS_LENGT][WORD_LENGT];

    fillArr(words);

    selectSort(words, WORDS_LENGT);
    bubbleSort(words, WORDS_LENGT);
    combSort(words, WORDS_LENGT);

    return 0;
}

/*No, 
the algorithms weren't run simultaneously. 
The clock() function found in the time.h library is used to independently measure the amount of time each algorithm consumes.
Each algorithm uses the clock() method to start and stop its own timer, and it calculates the amount of time that has passed individually. 
As a result, the amount of time one algorithm takes has no bearing on the amount of time it takes for the others.*/