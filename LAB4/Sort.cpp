#include "Sort.h"
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <stdio.h>
#include <cstdarg>

Sort::Sort(int size, int min, int max) {
    this->size = size;
    vector = new int[size];

    srand(time(0));
    for (int i = 0; i < size; i++) 
        vector[i] = rand() % (max - min + 1) + min;
}

Sort::Sort(std::initializer_list<int> List) {
    this->size = List.size();
    this->vector = new int[size];
    int i = 0;
    for (int element : List) {
        vector[i++] = element;
    }
}

Sort::Sort(int* vector, int size) {
    this->size = size;
    this->vector = new int[size];

    memcpy(this->vector, vector, size * sizeof(int));
}

Sort::Sort(int size, ...) {
    va_list args;
    va_start(args, size);
    this->size = size;
    this->vector = new int[size];
    for (int i = 0; i < size; i++) {
        this->vector[i] = va_arg(args, int);
    }
    va_end(args);
}

Sort::Sort(char* string, int size) {
    int numberCount = 0;
    int number = 0;
    int numbers[128];
    
    for (int i = 0; i < size; i++) {
        if (string[i] >= '0' && string[i] <= '9')
            number = number * 10 + (string[i] - '0');
        else {
            numbers[numberCount++] = number;
            printf("%d ", number);
            number = 0;
        }
    }
    
    vector = new int[numberCount];
    this->size = numberCount;
    for (int i = 0; i < this->size; i++)
        vector[i] = numbers[i];
}

Sort::~Sort() {
    delete[] vector;
}

void Sort::Print(){
    for (int i = 0; i < size; i++)
        printf("%d ", vector[i]);
    printf("\n");
}

int Sort::GetElementsCount() {
    return size;
}

int Sort::GetElementFromIndex(int index) {
    return vector[index];
}

void Sort::BubbleSort(bool ascendent) {
    bool sorted = true;
    do {
        sorted = true;
        for (int i = 0; i < size - 1; i++)
            if (ascendent) {
                if (vector[i] > vector[i + 1]) {
                    int aux = vector[i];
                    vector[i] = vector[i+1];
                    vector[i+1] = aux;
                    sorted = false;
                }
            }
            else {
                if (vector[i] < vector[i + 1]) {
                    int aux = vector[i];
                    vector[i] = vector[i+1];
                    vector[i+1] = aux;
                    sorted = false;
                }
            }
                
    }while(!sorted);
}

void Sort::InsertSort(bool ascendent) {
    for (int i = 1; i < size; i++) {
        int key = vector[i];
        int j = i - 1;
        if (ascendent) {
            while (j >= 0 && vector[j] > key) {
                vector[j + 1] = vector[j];
                j--;
            }
        }
        else {
            while (j >= 0 && vector[j] < key) {
                vector[j + 1] = vector[j];
                j--;
            }
        }
        vector[j + 1] = key;
    }
}

void Sort::QuickSort(bool ascendent) {
    if (size <= 1)
        return;

    int pivot = vector[size / 2];
    int i = 0, j = size - 1;

    while (i <= j) {
        if (ascendent) {
            while (vector[i] < pivot)
                i++;
            while (vector[j] > pivot)
                j--;
        }
        else {
            while (vector[i] > pivot)
                i++;
            while (vector[j] < pivot)
                j--;
        }

        if (i <= j) {
            int aux = vector[i];
            vector[i] = vector[j];
            vector[j] = aux;
            i++;
            j--;
        }
    }

    if (j >= 0) {
        Sort leftSubarray(vector, j + 1);
        leftSubarray.QuickSort(ascendent);
        memcpy(vector, leftSubarray.vector, (j + 1) * sizeof(int));
    }
    if (i < size) {
        Sort rightSubarray(vector + i, size - i);
        rightSubarray.QuickSort(ascendent);
        memcpy(vector + i, rightSubarray.vector, (size - i) * sizeof(int));
    }
}