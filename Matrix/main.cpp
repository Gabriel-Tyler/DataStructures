#include "Matrix2D.h"

void PrintTest();
void AddTest();

int main()
{
    Matrix2D<int, 3, 2> m1; m1.FillIncrement(1, 1);
    // m1.Print();
    Matrix2D<int, 2, 3> m2; m2.Fill(1);
    // m2.Print();
    Matrix2D<int, 3, 3> m3 = m1 * m2;
    m3.Print();
}

void PrintTest()
{
    Matrix2D<int, 3, 2> m;
    m.Print();
    m.Fill(22);
    m.FillIncrement(0, 20000);
    m.Print();
    m.PrintArray();
}
void AddTest()
{
    Matrix2D<int, 3, 2> m1; m1.Fill(1);
    Matrix2D<int, 3, 2> m2; m2.Fill(2);
    m1.Print();
    m1 += -1;
    m1.Print();
    Matrix2D<int, 3, 2> m3 = m1 + m2;
    m3.Print();
}