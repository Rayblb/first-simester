#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int max_sequence(char arr[], char ch) {
    int len = strlen(arr);
    int the_seq_len = 0;
    int seq_len = 0;
    int i;

    for (i = 0; i < len; i++) {
        if (arr[i] == ch) {
            seq_len++;
        } else {
            if (seq_len > the_seq_len) {
                the_seq_len = seq_len;
            }
            seq_len = 0;
        }
    }

    if (seq_len > the_seq_len) {
        the_seq_len = seq_len;
    }

    return the_seq_len;
}

int main() {
    char arr[MAX_LEN];
    char ch;
    int the_seq_len;

    printf("Enter a string: ");
    fgets(arr, MAX_LEN, stdin);

    printf("Enter a character to find the maximum sequence for: ");
    scanf("%c", &ch);

    the_seq_len = max_sequence(arr, ch);

    printf("Maximum sequence length for '%c': %d\n", ch, the_seq_len);

    return 0;
}