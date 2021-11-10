#pragma once

#include <iostream>

template<typename T, size_t ROWS, size_t COLS> 
class Matrix2D
{
private:
    T* data;
public:
    Matrix2D();
    ~Matrix2D();
    void Fill(T fillValue = T());
    void FillIncrement(T start = T(), T inc = T());
    void Print() const;
    void PrintArray() const;
};

template<typename T, size_t ROWS, size_t COLS>
Matrix2D<T, ROWS, COLS>::Matrix2D()
{
    data = new T[ROWS*COLS];
}
template<typename T, size_t ROWS, size_t COLS>
Matrix2D<T, ROWS, COLS>::~Matrix2D()
{
    delete[] data;
}
template<typename T, size_t ROWS, size_t COLS>
void Matrix2D<T, ROWS, COLS>::Fill(T fillValue)
{
    size_t size = ROWS * COLS;
    for (size_t i = 0; i < size; ++i)
    {
        data[i] = fillValue;
    }
}
template<typename T, size_t ROWS, size_t COLS>
void Matrix2D<T, ROWS, COLS>::Print() const
{ 
    size_t size = ROWS * COLS;
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << data[i] << ((i+1) % COLS == 0 ? '\n' : ' ');
    }
}
template<typename T, size_t ROWS, size_t COLS>
void Matrix2D<T, ROWS, COLS>::PrintArray() const
{
    size_t size = ROWS * COLS;
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << '\n';
}
template<typename T, size_t ROWS, size_t COLS>
void Matrix2D<T, ROWS, COLS>::FillIncrement(T start, T inc)
{
    size_t size = ROWS * COLS;
    for (size_t i = 0; i < size; ++i)
    {
        data[i] = start;
        start = start + inc;
    }
}