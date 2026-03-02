#include "Math.h"
#include <cstdarg>

int Math::Add(int x, int y) {
    return x + y;
}

int Math::Add(int x, int y, int z) {
    return x + y + z;
}

int Math::Add(double x, double y) {
    return x + y;
}

int Math::Add(double x, double y, double z) {
    return x + y + z;
}

int Math::Mul(int x,int y) {
    return x * y;
}

int Math::Mul(int x, int y, int z) {
    return x * y * z;
}

int Math::Mul(double x, double y) {
    return x * y;
}

int Math::Mul(double x, double y, double z) {
    return x * y * z;
}

int Math::Add(int count, ...) {
    int sum = 0;

    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++)
        sum += va_arg(args, int);

    va_end(args);

    return sum;
}

char* Math::Add(const char* str1, const char* str2) {
    if (str1 == nullptr || str2 == nullptr)
        return nullptr;

    int firstLength = 0;
    while (str1[firstLength] != '\0')
        firstLength++;

    int secondLength = 0;
    while (str2[secondLength] != '\0')
        secondLength++;

    int totalLength = firstLength + secondLength + 1;
    char* finalString = new char[totalLength];

    for (int i = 0; i < firstLength; i++)
        finalString[i] = str1[i];

    for (int i = 0; i < secondLength; i++)
        finalString[firstLength++] = str2[i];

    finalString[totalLength - 1] = '\0';

    return finalString;
}