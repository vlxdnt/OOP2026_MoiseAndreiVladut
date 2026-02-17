#include "header.h"

// corectat parametrii sa arate ca in header
// corectat calculul valorilor de return
int Sum(int a, int b) { return a + b; }
int Dif(int a, int b) { return a - b; }
int Mul(int a, int b) { return a * b; }
int Div(int a, int b) { return a / b; }

int main(int argc, char* argv[])
{
    char input[] = "---H***E+++L+++L///O---P+++O/+-**O---"; // scos sizeul de 7
    func Operatori[] = {Mul, Sum, Dif, Div}; // scos valorile inutile
    int S = 0; // sters V ca nu facea nimic si initializat suma cu 0
    Content x = {0, 0}; // corectare initializare struct
    int idx; // facut index din double in int

    for (int i = 0; i < strlen(input); i++)
    {
        switch (input[i] - 42)
        {
            case INMULTIRE: // pus indexii corecti din Operatori[] si adaugat break la fiecare case
                idx = 0;
                x.p1 = 3;
                x.p2 = 3;
                break;
            case SUMA:
                idx = 1;
                x.p1 = 7;
                x.p2 = 5;
                break;
            case DIFERENTA:
                idx = 2;
                x.p1 = 10;
                x.p2 = 1;
                break;
            case IMPARTIRE:
                idx = 3;
                x.p1 = 8;
                x.p2 = 4;
                break;
        }
        
        S = S + Operatori[idx](x.p1, x.p2);
    }

    //S=337
    printf("S = %d\n", S);

    return 0;
}
