#include <iostream>
#include "Array.h"
using namespace std;

class CompareInts : public Compare {
public:
    int CompareElements(void* e1, void* e2) override {
        int a = *(int*)e1;
        int b = *(int*)e2;
        if (a > b) return 1;
        if (a == b) return 0;
        return -1;
    }
};

int CompareIntFunc(const int& a, const int& b) {
    return a - b;
}

int main() {
    try {
        Array<int> arr(5);

        arr += 10;
        arr += 3;
        arr += 7;

        cout << "Original array: ";
        for (int i = 0; i < arr.GetSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        
        CompareInts comp;
        arr.Sort(&comp);

        cout << "Sorted array (via Compare object): ";
        for (int i = 0; i < arr.GetSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";

        int pos = arr.Find(7, CompareIntFunc);
        cout << "Found 7 at position: " << pos << "\n";

        pos = arr.BinarySearch(10, &comp);
        cout << "Binary search for 10: " << pos << "\n";

        cout << "Array via iterator: ";
        for (auto it = arr.GetBeginIterator(); it != arr.GetEndIterator(); ++it) {
            cout << *(it.GetElement()) << " ";
        }
        cout << "\n";

    }
    catch (const std::exception& e) {
        cout << "Exception: " << e.what() << "\n";
    }

    return 0;
}
