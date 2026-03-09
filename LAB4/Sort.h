#include <initializer_list>

class Sort {
    private:
        int* vector;
        int size;
    public:
        Sort(int size, int min, int max);
        Sort(int* vector, int size);
        Sort(std::initializer_list<int> List);
        Sort(int size, ...);
        Sort(char* string, int size);
        void InsertSort(bool ascendent = false);
        void QuickSort(bool ascendent = false);
        void BubbleSort(bool ascendent = false);
        void Print();
        int GetElementsCount();
        int GetElementFromIndex(int index);
        ~Sort();
};