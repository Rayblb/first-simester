#include <stdio.h>

int main() {
    char word[20];
    int vowels = 0, consonants = 0;
    char *p;

    printf("Enter a word (only lowercase Latin letters without space): ");
    scanf("%s", word);

    p = word;

    while (*p != '\0') {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u') {
            vowels++;
        } else {
            consonants++;
        }
        p++;
    }

    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    return 0;
}
