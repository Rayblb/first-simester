#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void a(int depth);
void b();
void c();


int main() {
    setlocale(LC_ALL, "Eng");

    int depth;
    printf("Enter recursion depth: ");
    scanf("%d", &depth);

    printf("main() CALL   ->\n");
    a(depth);
    printf("tmain() RETURN <-\n");

    return 0;
}

void a(int depth) {
    if (depth == 0) {
        printf("\t\t   a() RETURN <-\n");
        return;
    }

    printf("\t\t   a() CALL   ->\n");
    b(depth - 1);
    printf("\t\t   a() RETURN <-\n");
}

void b(int depth) {
    if (depth == 0) {
        printf("\t\t\t\t   b() RETURN <-\n");
        return;
    }

    printf("\t\t\t\t   b() CALL   ->\n");
    c(depth - 1);
    printf("\t\t\t\t   b() RETURN <-\n");
}

void c(int depth) {
    if (depth == 0) {
        printf("\t\t\t\t\t\t   c() RETURN <-\n");
        return;
    }

    printf("\t\t\t\t\t\t   c() CALL   ->\n");
    c(depth - 1);
    printf("\t\t\t\t\t\t   c() RETURN <-\n");
}
