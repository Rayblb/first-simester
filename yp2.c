#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDS_LENGT 10
#define WORD_LENGT 20

void printArray(char words[WORDS_LENGT][WORD_LENGT]) {
    printf("[ ");
    for(int i=0; i<WORDS_LENGT; i++) {
        printf("%s ", words[i]);
    }
    printf("]\n");
}



void combSort(char words[WORDS_LENGT][WORD_LENGT], int length) {
    int gap = length, i, j, swapped = 1, iterations=0;
    char temp[WORD_LENGT];
    char (*p1)[WORD_LENGT];
    char (*p2)[WORD_LENGT];
    while (gap != 1 || swapped == 1) {
        gap = gap * 10 / 13;
        if (gap < 1) {
            gap = 1;
        }
        swapped = 0;
        p1 = words;
        p2 = words + gap;

       for (i = 0; i < length-gap; i++) {
            if (strcmp(*p1, *p2) > 0) {
                strcpy(temp, *p1);
                strcpy(*p1, *p2);
                strcpy(*p2, temp);
                swapped = 1;
            }
            p1++;
            p2++;
            iterations++;
        }
        printf("Comb Sort, Gap=%d:\n", gap);
        printArray(words);
    }
    printf("Iterations: %d\n", iterations);
}

int main() {
    char words[WORDS_LENGT][WORD_LENGT];
    printf("Enter %d words (in lowercase): \n", WORDS_LENGT);
    for (int i = 0; i < WORDS_LENGT; i++) {
        scanf("%s", words[i]);
    }

    combSort(words, WORDS_LENGT);

    return 0;
}

