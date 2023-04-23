#include <stdio.h>//for input and output functions
#include <stdlib.h>//for memory allocation functions
#include <string.h>//for string manipulation functions
#include <ctype.h>//for character manipulation functions
#include <time.h>//for measuring the running time of the sorting algorithms.

#define WORDS_LENGT 10
#define WORD_LENGT 20



void printArr(char words[WORDS_LENGT][WORD_LENGT]) { // inserts brackets and spaces while repeating through a 2D character array.
    printf("[ ");
    for(int i=0; i<WORDS_LENGT; i++) {
        printf("%s ", words[i]);
    }
    printf("]\n");
}

void selectSort(char words[WORDS_LENGT][WORD_LENGT], int length) {
    int i, j, min_idx, iterations=0;
    char temp[WORD_LENGT];
    clock_t start, end;
    double cpu_time_used;

   
    start = clock(); // Start the timer

    
    for (i = 0; i < length-1; i++) {// One by one move boundary of unsorted subarray
        
        
        min_idx = i;// Find the minimum element in unsorted array
        for (j = i+1; j < length; j++) {
            if (strcmp(words[j], words[min_idx]) < 0) {
                min_idx = j;
            }
            iterations++;
        }
        
        strcpy(temp, words[min_idx]);        // Swap the found minimum element with the first element
        strcpy(words[min_idx], words[i]);
        strcpy(words[i], temp);
    }

    end = clock();// End the timer and calculate elapsed time
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Selection Sort:\n");    // Print the sorted array, number of iterations, and elapsed time<hometown,backpack,zebra,guitar,ocean,pencil,mosquito,paradise,crimson,seashell>
    printArr(words);
    printf("Iterations: %d\n", iterations);// 45
    printf("Time taken: %f seconds\n", cpu_time_used);//Time taken: 0.000000 seconds
}

void bubbleSort(char words[WORDS_LENGT][WORD_LENGT], int length) {
    int i, j, iterations=0;
    char temp[WORD_LENGT];
    clock_t start, end;
    double cpu_time_used;
    start = clock(); // Start the timer

    for (i = 0; i < length-1; i++) {// Iterate over the array
        
        for (j = 0; j < length-i-1; j++) {// Compare adjacent elements and swap if necessary
            if (strcmp(words[j], words[j+1]) > 0) {
                strcpy(temp, words[j]);
                strcpy(words[j], words[j+1]);
                strcpy(words[j+1], temp);
            }
            iterations++;
        }
        printf("Bubble Sort, Pass %d:\n", i+1);
        printArr(words);
         /* 
        Bubble Sort, Pass 1:
        [ backpack crimson guitar hometown mosquito ocean paradise pencil seashell zebra ]
        Bubble Sort, Pass 2:
        [ backpack crimson guitar hometown mosquito ocean paradise pencil seashell zebra ]
        Bubble Sort, Pass 3:
        [ backpack crimson guitar hometown mosquito ocean paradise pencil seashell zebra ]
        Bubble Sort, Pass 4:
        [ backpack crimson guitar hometown mosquito ocean paradise pencil seashell zebra ]
        Bubble Sort, Pass 5:
        [ backpack crimson guitar hometown mosquito ocean paradise pencil seashell zebra ]
        Bubble Sort, Pass 6:
        [ backpack crimson guitar hometown mosquito ocean paradise pencil seashell zebra ]
        Bubble Sort, Pass 7:
        [ backpack crimson guitar hometown mosquito ocean paradise pencil seashell zebra ]
        Bubble Sort, Pass 8:
        [ backpack crimson guitar hometown mosquito ocean paradise pencil seashell zebra ]
        Bubble Sort, Pass 9:
        [ backpack crimson guitar hometown mosquito ocean paradise pencil seashell zebra ]*/
            
            }
    end = clock(); // End the timer
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Iterations: %d\n", iterations);//45
    printf("Time taken: %f seconds\n", cpu_time_used);//Time taken: 0.025000 seconds
}

void combSort(char words[WORDS_LENGT][WORD_LENGT], int length) {
    int gp = length, i, j, swapped = 1, iterations=0;
    char temp[WORD_LENGT];
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    
    while (gp != 1 || swapped == 1) {// Continue sorting while the gp is not 1 or elements have been swapped
        gp = gp * 10 / 13;// Calculate the next gp using the comb formula
        if (gp < 1) {
            gp = 1;
        }
        swapped = 0;

        for (i = 0; i < length-gp; i++) {        // Compare elements with the calculated gp
            j = i+gp;
            if (strcmp(words[i], words[j]) > 0) {

                strcpy(temp, words[i]);// Swap the elements
                strcpy(words[i], words[j]);// Swap the elements
                strcpy(words[j], temp);// Swap the elements
                swapped = 1;
            }
            iterations++;
        }
        printf("Comb Sort, Gap=%d:\n", gp);// Print the array after each gp iteration
        printArr(words);
         /*Comb Sort, Gap=7:
        [ backpack crimson guitar hometown mosquito ocean paradise pencil seashell zebra ]
        Comb Sort, Gap=5:
        [ backpack crimson guitar hometown mosquito ocean paradise pencil seashell zebra ]
        Comb Sort, Gap=3:
        [ backpack crimson guitar hometown mosquito ocean paradise pencil seashell zebra ]
        Comb Sort, Gap=2:
        [ backpack crimson guitar hometown mosquito ocean paradise pencil seashell zebra ]
        Comb Sort, Gap=1:
        [ backpack crimson guitar hometown mosquito ocean paradise pencil seashell zebra ]*/
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Iterations: %d\n", iterations);//32
    printf("Time taken: %f seconds\n", cpu_time_used);//0.012000 seconds
}

int main() {
    char words[WORDS_LENGT][WORD_LENGT]; // declare an array of strings to hold input words
    printf("Enter %d words (in lowercase): \n", WORDS_LENGT);
    for (int i = 0; i < WORDS_LENGT; i++) {
        scanf("%s", words[i]); // read in the words from the user
    }

    int choice;
    printf("Which algorithm do you want to use?\n");
    printf("1. Selection Sort\n");
    printf("2. Bubble Sort\n");
    printf("3. Comb Sort\n");
    printf("4. All three\n");
    scanf("%d", &choice); // get the user's choice of algorithm

    switch (choice) {
        case 1:
            selectSort(words, WORDS_LENGT); // perform select sort
            /*Iterations: 45
            Time taken: 0.000000 seconds*/
            break;
        case 2:
            bubbleSort(words,WORD_LENGT); // perform bubble sort
            /*Iterations: 190
            Time taken: 0.052000 seconds*/
            break;
        case 3:
            combSort(words,WORD_LENGT); // perform comb sort
            /*Iterations: 129
            Time taken: 0.004000 seconds*/
            break;
        case 4:
            printf("Selection Sort:\n");
            selectSort(words, WORDS_LENGT); // perform selection sort and print results (Iterations: 45 ,Time taken: 0.000000 seconds)
            printf("Bubble Sort:\n");
            bubbleSort(words, WORDS_LENGT); // perform bubble sort and print results(Iterations: 45 , Time taken: 0.000000 seconds)
            printf("Comb Sort:\n");
            combSort(words, WORDS_LENGT); // perform comb sort and print results(Iterations: 32, Time taken: 0.000000 seconds)
            
            break;
    }
    /*An optimization algorithm's iteration count is influenced by the input data and learning rate. */

    printf("Delaying for 3 seconds...\n"); // delay for 3 seconds
    clock_t delay_start = clock();
    while ((double)(clock() - delay_start) / CLOCKS_PER_SEC < 3) {} // busy wait for 3 seconds
    printf("Delay finished!\n");
    
    return 0;
}
//In conclusion, we cannot declare with assurance that a specific algorithm would work for any dictionary or which algorithm sorted the same dictionary in the fewest iterations.
//Algorithms with varying temporal complexities need varied amounts of time to execute, which is a measure of how long it takes an algorithm to solve a problem.