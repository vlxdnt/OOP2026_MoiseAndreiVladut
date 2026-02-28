#include "NumberList.h"

using namespace std;

int main()
{
    NumberList numere;
    numere.Add(5);
    numere.Add(7);
    numere.Add(8);
    numere.Add(9);
    numere.Add(10);
    numere.Add(3);
    numere.Print();
    numere.Sort();
    numere.Print();
    return 0;
}