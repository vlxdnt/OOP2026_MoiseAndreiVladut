#include "Canvas.h"

int main()
{
    Canvas canva(10, 10);
    canva.SetPoint(5, 5, 'o');
    canva.Print();
    canva.Clear();

    canva.DrawLine(1, 2, 6, 7, 'o');
    canva.Print();
    canva.Clear();

    canva.DrawRect(1, 2, 6, 7, 'o');
    canva.Print();
    canva.Clear();

    canva.FillRect(1, 2, 6, 7, 'o');
    canva.Print();
    canva.Clear();

    canva.DrawCircle(5, 5, 3, '0');
    canva.Print();
    canva.Clear();

    canva.FillCircle(5, 5, 3, '0');
    canva.Print();
    canva.Clear();
    return 0;
}