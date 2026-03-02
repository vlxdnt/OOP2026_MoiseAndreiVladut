#include "Math.h"
#include <stdio.h>

int main() 
{
    printf("Sum of 2 ints: %d\n", Math::Add(1, 2));
    printf("Sum of 3 ints: %d\n", Math::Add(1, 2, 3));
    printf("Sum of 2 doubles: %d\n", Math::Add(1.5, 2.7));
    printf("Sum of 3 doubles: %d\n", Math::Add(1.5, 2.7, 5.5));
    printf("Multiplication of 2 ints: %d\n", Math::Mul(5, 2));
    printf("Multiplication of 3 ints: %d\n", Math::Add(5, 2, 10));
    printf("Multiplication of 2 doubles: %d\n", Math::Add(1.8, 6.7));
    printf("Multiplication of 3 doubles: %d\n", Math::Add(1.8, 6.7, 5.9));
    printf("Sum of n ints: %d\n", Math::Add(5, 1, 2, 3, 4, 5));
    char* result = Math::Add("Mere", "Pere");
    printf("Concatenation of 2 strings: %s\n", result);
    delete[] result;
    return 0;
}