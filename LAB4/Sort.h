class Sort {
    private:
        int* vector;
        int size;
    public:
        Sort(int size, int min, int max);
        Sort();
        Sort(int* vector, int size);
        Sort(int size, ...);
        Sort(char* string);
        void InsertSort(bool ascendent = false);
        void QuickSort(bool ascendent = false);
        void BubbleSort(bool ascendent = false);
        void Print();
        int GetElementsCount();
        int GetElementFromIndex(int index);
        ~Sort();
};