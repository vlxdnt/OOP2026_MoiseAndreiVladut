class NumberList {
        int *numbers;
        int capacity;
        int count;
        void Resize();
    public:
        NumberList() {
            count = 0;
            capacity = 4;
            numbers = new int[capacity];
        }
        bool Add(int x);
        void Sort();
        void Print();
        ~NumberList() {
            delete[] numbers;
        }
};