#pragma once

#include <iostream>

template<typename T, size_t ROWS, size_t COLS> 
class Matrix2D
{
private:
    T* data;
public:
    Matrix2D();
    Matrix2D(const Matrix2D& m);
    Matrix2D(Matrix2D&& m);
    const Matrix2D& operator=(const Matrix2D& rhs);
    const Matrix2D& operator=(Matrix2D&& rhs);
    ~Matrix2D();

    void Fill(T fillValue = T());
    void FillIncrement(T start = T(), T inc = T());
    void Print() const;
    void PrintArray() const;

    friend Matrix2D operator+(const Matrix2D& lhs, const Matrix2D& rhs);
    friend Matrix2D operator+(const T& lhs, const Matrix2D& rhs);
    friend Matrix2D operator+(const Matrix2D& lhs, const T& rhs);

    Matrix2D& operator+=(const Matrix2D& rhs);
    Matrix2D& operator+=(const T& rhs);
};

template<typename T, size_t ROWS, size_t COLS>
Matrix2D<T, ROWS, COLS>::Matrix2D()
{
    data = new T[ROWS*COLS];
}
template<typename T, size_t ROWS, size_t COLS>
Matrix2D<T, ROWS, COLS>::Matrix2D(const Matrix2D& m)
{
    data = new T[ROWS*COLS];
    for (size_t i = 0; i < ROWS*COLS; ++i) 
    {
        data[i] = m.data[i];
    }
}
template<typename T, size_t ROWS, size_t COLS>
Matrix2D<T, ROWS, COLS>::Matrix2D(Matrix2D&& m)
{
    data = m.data;
    m.data = nullptr;
}
template<typename T, size_t ROWS, size_t COLS>
const Matrix2D<T, ROWS, COLS>& Matrix2D<T, ROWS, COLS>::operator=(const Matrix2D& rhs)
{
    data = new T[ROWS*COLS];
    for (size_t i = 0; i < ROWS*COLS; ++i) 
    {
        data[i] = m.data[i];
    }
}
template<typename T, size_t ROWS, size_t COLS>
const Matrix2D<T, ROWS, COLS>& Matrix2D<T, ROWS, COLS>::operator=(Matrix2D&& rhs)
{
    data = m.data;
    m.data = nullptr;
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
template<typename T, size_t ROWS, size_t COLS>
Matrix2D<T, ROWS, COLS> operator+(const Matrix2D<T, ROWS, COLS>& lhs, const Matrix2D<T, ROWS, COLS>& rhs)
{
    Matrix2D m = lhs;
    for (size_t i = 0; i < ROWS*COLS; ++i)
    {
        m.data[i] += rhs.data[i];
    }
    return m;
}
template<typename T, size_t ROWS, size_t COLS>
Matrix2D<T, ROWS, COLS> operator+(const T& lhs, const Matrix2D<T, ROWS, COLS>& rhs)
{
    Matrix2D m = rhs;
    for (size_t i = 0; i < ROWS*COLS; ++i)
    {
        m.data[i] += lhs;
    }
    return m;
}
template<typename T, size_t ROWS, size_t COLS>
Matrix2D<T, ROWS, COLS> operator+(const Matrix2D<T, ROWS, COLS>& lhs, const T& rhs)
{
    Matrix2D m = lhs;
    for (size_t i = 0; i < ROWS*COLS; ++i)
    {
        m.data[i] += rhs;
    }
    return m;
}
template<typename T, size_t ROWS, size_t COLS>
Matrix2D<T, ROWS, COLS>& Matrix2D<T, ROWS, COLS>::operator+=(const Matrix2D<T, ROWS, COLS>& rhs)
{
    for (size_t i = 0; i < ROWS*COLS; ++i)
    {
        data[i] += rhs.data[i];
    }
    return *this;
}
template<typename T, size_t ROWS, size_t COLS>
Matrix2D<T, ROWS, COLS>& Matrix2D<T, ROWS, COLS>::operator+=(const T& rhs)
{
    for (size_t i = 0; i < ROWS*COLS; ++i)
    {
        data[i] += rhs;
    }
    return *this;
}