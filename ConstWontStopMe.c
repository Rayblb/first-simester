#include <stdio.h>

int main()
{
    const int i = 2;
    const int* ptr1 = &i;
    int* ptr2 = (int*)ptr1;//ptr2 points to the same memory location as ptr1
    *ptr2 = 3;//this effectively changes the value of i to 3.

    printf("i = %d\n", i);
    printf("i = ptr2 = %d", *ptr2);
//the output will be 3 in the VS code and online compiler
    return 0;
}
/*
code explanation in  details:
     when we changed the non const pointer2 (*ptr2) to "3" by substitution we changed the value of i:
            because the const ptr1 =  ptr2 now .because, ptr2 points to the same memory location as ptr1:
                so we changed the variable in this memory to 3 and the variabale is i 
                    so the system will print    i = 3
                                                i=ptr2=3


Programmers use the phrase "undefined behavior" to refer to the outcome of running code that does not behave as expected given the language's specification.
It might lead to erratic or inconsistent behavior, such as crashes, false conclusions, or security flaws.


In this situation, 
trying to change a const variable through a pointer is undefinable behavior since it goes against the C language's const correctness rule.
 */