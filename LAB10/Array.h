#include <exception>
#include <iostream>
using namespace std;

class OutOfRange : public exception {
    virtual const char* what() const throw() {
        return "Index out of range.";
    }
};

class ExceedCapacity : public exception {
    virtual const char* what() const throw() {
        return "Index exceeds capacity!";
    }
};

////////////////////////////////////////////////

class Compare
{
    public:
        virtual int CompareElements(void* e1, void* e2) = 0;
};

/////////////////////////////////////////////////

template<class T>
class ArrayIterator
{
    private:
        int Current;
        int Size;
        T** ptr;

    public:
        ArrayIterator() : Current(0), ptr(nullptr) {}

        ArrayIterator(T** pointer, int size, int current) : ptr(pointer), Size(size), Current(current) {}

        ArrayIterator& operator ++ () {
            this->Current++;
            return *this;
        }

        ArrayIterator& operator -- () {
            this->Current--;
            return *this;
        }

        bool operator== (const ArrayIterator<T>& other) const {
            return this->Current == other.Current;
        }

        bool operator!=(const ArrayIterator<T>& other) const {
            return !(this->Current == other.Current);
        }
        
        T* GetElement() {
            return this->ptr[Current];
        }
};

////////////////////////////////////////////////////////////////

template<class T>
class Array
{
    private:
        T** List; // lista cu pointeri la obiecte de tipul T*
        int Capacity; // dimensiunea listei de pointeri
        int Size; // cate elemente sunt in lista

        OutOfRange errorRange;
        ExceedCapacity errorCap;

    public:
        Array() {
            this->Capacity = 0;
            this->Size = 0;
        }
        
        ~Array() {
            for (int i = 0; i < Size; i++) {
                delete List[i];
            }
            delete[] List;
        }

        Array(int capacity) {
            this->Capacity = capacity;
            this->Size = 0;
            this->List = new T * [capacity];
        }

        Array(const Array<T>& otherArray) {
            Capacity = otherArray.Capacity;
            Size = otherArray.Size;
            List = new T * [Capacity];
            for (int i = 0; i < Size; i++) {
                List[i] = new T(*otherArray.List[i]);
            }
        }

        T& operator[] (int index) {
            try {
                if (index > this->Size || index < 0) throw errorRange;  
                return *this->List[index];
            }
            catch (exception& e) {
                cout << "Error! " << e.what();
                return *this->List[0]; // returnez un element valid pentru a evita erori de compilare
            }
        }

        const Array<T>& operator+=(const T& newElem) {
            if (this->Size < this->Capacity) {
                this->List[this->Size] = new T(newElem);
                this->Size++;
                return *this;
            }
            throw errorCap;
        }

        const Array<T>& Insert(int index, const T& newElem) {
            try {
                if (index < 0 || index > Size) throw errorRange;
                this->List[this->Size] = &newElem;
                return *this;
            }
            catch (exception& e) {
                cout << "Error!" << e.what();
                return *this;
            }

        }

        const Array<T>& Insert(int index, const Array<T> otherArray) {
            try {
                if (index < 0 || index > this->Size) throw errorRange;
                if (otherArray->Size + this->Size > this->Capacity) throw errorCap;
                for (int i = index; i < index + otherArray->Size; i++) {
                    this->List[i + otherArray->Size] = this->List[i];
                    this->List[i] = otherArray->List[i - index];
                }
                return *this;

            }
            catch (exception& e) {
                cout << "Error! " << e.what();
                return *this;
            }

        }

        const Array<T>& Delete(int index) {
            try {
                if (index < 0 || index > Size) throw errorRange;
                for (int i = index; i < Size - 1; i++) {
                    this->List[i] = this->List[i + 1];
                }
                delete[] List[Size - 1];
                Size--;
                return *this;
            }
            catch (exception& e) {
                cout << e.what();
                return *this;
            }
        }

        bool operator=(const Array<T>& otherArray) {
            if (this == &otherArray) return true;
            for (int i = 0; i < Size; i++) {
                delete[] List[i];
            }
            delete[] List;

            Capacity = otherArray.Capacity;
            Size = otherArray.Size;
            List = new T * [Capacity];
            for (int i = 0; i < Size; i++) {
                List[i] = new T(*otherArray.List[i]);
            }
            return true;
        }

        void Sort() {
            for (int i = 0; i < Size - 1; i++) {
                for (int j = 0; j < Size - i - 1; j++) {
                    if (*List[j] > *List[j + 1]) {
                        T* temp = List[j];
                        List[j] = List[j + 1];
                        List[j + 1] = temp;
                    }
                }
            }
        }

        void Sort(int(*compare)(const T&, const T&)) {
            for (int i = 0; i < Size - 1; i++) {
                for (int j = 0; j < Size - i - 1; j++) {
                    if (compare(*List[j], *List[j + 1]) > 0) {
                        T* temp = List[j];
                        List[j] = List[j + 1];
                        List[j + 1] = temp;
                    }
                }
            }
        }

        void Sort(Compare* comparator) {
            for (int i = 0; i < Size - 1; i++) {
                for (int j = 0; j < Size - i - 1; j++) {
                    if (comparator->CompareElements((void*)List[j], (void*)List[j + 1]) > 0) {
                        T* temp = List[j];
                        List[j] = List[j + 1];
                        List[j + 1] = temp;
                    }
                }
            }

        }

        int BinarySearch(const T& elem) {
            int left = 0, right = Size - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (*List[mid] == elem) return mid;
                if (*List[mid] > elem) right = mid - 1;
                else left = mid + 1;
            }
            return -1;
        }

        int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
            int left = 0, right = Size - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                int cmp = compare(elem, *List[mid]);
                if (cmp == 0) return mid;
                if (cmp < 0) right = mid - 1;
                else left = mid + 1;
            }
            return -1;
        }

        int BinarySearch(const T& elem, Compare* comparator) {
            int left = 0, right = Size - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                int cmp = comparator->CompareElements((void*)&elem, (void*)List[mid]);
                if (cmp == 0) return mid;
                if (cmp < 0) right = mid - 1;
                else left = mid + 1;
            }
            return -1;
        }

        int Find(const T& elem) {
            for (int i = 0; i < Size; i++)
                if (*List[i] == elem) return i;
            return -1;
        }

        int Find(const T& elem, int(*compare)(const T&, const T&)) {
            for (int i = 0; i < Size; i++)
                if (compare(elem, *List[i]) == 0) return i;
            return -1;
        }

        int Find(const T& elem, Compare* comparator) {
            for (int i = 0; i < Size; i++)
                if (comparator->CompareElements((void*)&elem, (void*)List[i]) == 0)
                    return i;
            return -1;
        }

        int GetSize() {
            return this->Size;
        }

        int GetCapacity() {
            return this->Capacity;
        }

        ArrayIterator<T> GetBeginIterator() {
            return ArrayIterator<T>(List, Size, 0);
        }

        ArrayIterator<T> GetEndIterator() {
            return ArrayIterator<T>(List, Size, Size);
        }
};