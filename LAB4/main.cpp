#include "Sort.h"
#include <stdio.h>

int main()
{
    Sort array(5, 0, 50);
    array.Print();
    array.BubbleSort(true);
    array.Print();

    Sort array1;
    array1.Print();
    array1.InsertSort(true);
    array1.Print();

    char* string = "10,40,100,5,70";
    Sort array2(string);
    array2.Print();
    array2.InsertSort();
    array2.Print();

    Sort array3(10, 1, 5, 6, 7, 2, 43, 12, 34, 56, 3);
    array3.Print();
    array3.QuickSort();
    array3.Print();

    int* vector = new int[5]{ 9, 4, 2, 8, 1 };
    Sort array4(vector, 5);
    array4.Print();
    array4.QuickSort(true);
    array4.Print();
    delete[] vector;

    printf("Element from index 3: %d\n", array3.GetElementFromIndex(3));
    printf("Elements count: %d\n", array3.GetElementsCount());
    return 0;
}