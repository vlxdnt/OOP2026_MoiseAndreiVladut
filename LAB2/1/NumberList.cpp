#include "NumberList.h"
#include <stdio.h>

void NumberList::Resize() {
    capacity *= 2;

    int* temp = new int[capacity];
    for (int i = 0; i < count; i++)
        temp[i] = numbers[i];

    delete[] numbers;
    numbers = temp;
}

bool NumberList::Add(int x) {
    if (count >= capacity)
        Resize();

    numbers[count++] = x;
    return true;
}

void NumberList::Sort() {
    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++)
            if (numbers[i] > numbers[j]) {
                int aux = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = aux;
            }
}

void NumberList::Print() {
    for (int i = 0; i < count; i++)
        printf("%d ", numbers[i]);
    printf("\n");
}