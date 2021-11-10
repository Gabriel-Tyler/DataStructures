#include "Matrix2D.h"

int main()
{
    Matrix2D<int, 5, 3> m;
    // m.Print();
    // m.Fill(22);
    m.FillIncrement(0, 20000);
    m.Print();
    // m.PrintArray();
}