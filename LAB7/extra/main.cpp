#include "Vector.h"

int compare_ints(int x, int y) {
    return (x > y) - (x < y);
}

int main() 
{
    Vector<int> v;

    v.insert(0, 10);
    v.insert(1, 5);
    v.insert(2, 20);

    Vector<int> w = v;  

    v.remove(0);
    v.sort(compare_ints);
    printf("%d\n", w[0]);

    v.print();
    return 0;
}

