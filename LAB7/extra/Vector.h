#include <stdio.h>

template <class T>
class Vector {
    private:
        T* data;
        int count;
        int capacity;

        void resize() {
            capacity = capacity * 2;
            T* newData = new T[capacity];

            for (int i = 0; i < count; i++)
                newData[i] = data[i];

            delete[] data;
            data = newData;
        }

    public:
        Vector() {
            count = 0;
            capacity = 4;
            data = new T[capacity];
        }

        ~Vector() {
            delete[] data;
        }

        Vector(const Vector<T>& v) {
            capacity = v.capacity;
            count = v.count;
            data = new T[capacity];

            for (int i = 0; i < count; i++)
                data[i] = v.data[i];
        }

        Vector(Vector<T>&& v) {
            capacity = v.capacity;
            count = v.count;
            data = v.data;

            v.capacity = 0;
            v.count = 0;
            v.data = nullptr;
        }

        void insert(int index, T value) {
            if (index >= 0 && index <= count) {
                if (count == capacity) 
                    resize();
                
                for (int i = count; i > index; i--) 
                    data[i] = data[i - 1];
                
                data[index] = value;
                count++;
            }
        }
        void print() {
            for (int i = 0; i < count; i++)
                printf("%d ", data[i]);
            printf("\n");
        }
        void remove(int index) {
            if (index >= 0 && index < count) {
                for (int i = index; i < count - 1; i++) 
                    data[i] = data[i + 1];
                
                count--;
            }
        }
        void sort(int (*cmp)(T,T)) {
            for (int i = 0; i < count - 1; i++) 
                for (int j = i + 1; j < count; j++) 
                    if (cmp(data[i], data[j]) == 1) { 
                        T aux = data[i];
                        data[i] = data[j];
                        data[j] = aux;
                    }
        }

        void sort() {
            for (int i = 0; i < count - 1; i++) {
                for (int j = i + 1; j < count; j++) {
                    if (data[j] < data[i]) {
                        T aux = data[i];
                        data[i] = data[j];
                        data[j] = aux;
                    }
                }
            }
        }

        T& operator[](int index) {
            return data[index];
        }
};