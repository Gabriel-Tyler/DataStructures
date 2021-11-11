#pragma once

#include <iostream>

template<typename T> 
class Matrix2D
{
private:
    size_t nRows;
    size_t nCols;
    T* data;
public:
    Matrix2D(size_t rows, size_t cols);
    Matrix2D(const Matrix2D& m);
    Matrix2D(Matrix2D&& m);
    const Matrix2D& operator=(const Matrix2D& rhs);
    const Matrix2D& operator=(Matrix2D&& rhs);
    ~Matrix2D();

    void Fill(T fillValue = T());
    void FillIncrement(T start = T(), T inc = T());
    void Print() const;
    void PrintArray() const;

    T& at(size_t row, size_t col);
    const T& at(size_t row, size_t col) const;

    template<typename S>
    friend Matrix2D<S> operator+(const Matrix2D<S>& lhs, const Matrix2D<S>& rhs);
    template<typename S>
    friend Matrix2D<S> operator+(const S& lhs, const Matrix2D<S>& rhs);
    template<typename S>
    friend Matrix2D<S> operator+(const Matrix2D<S>& lhs, const S& rhs);

    Matrix2D& operator+=(const Matrix2D& rhs);
    Matrix2D& operator+=(const T& rhs);

    template<typename S>
    friend Matrix2D<S> operator*(const Matrix2D<S>& lhs, const Matrix2D<S>& rhs);

    // template<typename T>
    // friend Matrix2D<T> operator*(const T& lhs, const Matrix2D<T>& rhs);
    // template<typename T>
    // friend Matrix2D<T> operator*(const Matrix2D<T>& lhs, const T& rhs);

    Matrix2D& operator*=(const Matrix2D& rhs);
    Matrix2D& operator*=(const T& rhs);

    // friend Matrix2D<T> operator/(const Matrix2D<T>& lhs, const T& rhs);
    // Matrix2D& operator/=(const T& rhs);
};

template<typename T>
Matrix2D<T>::Matrix2D(size_t rows, size_t cols)
    : nRows(rows), nCols(cols)
{
    data = new T[rows*cols];
}
template<typename T>
Matrix2D<T>::Matrix2D(const Matrix2D<T>& m)
    : nRows(m.nRows), nCols(m.nCols)
{
    data = new T[nRows*nCols];
    for (size_t i = 0; i < nRows*nCols; ++i) 
    {
        data[i] = m.data[i];
    }
}
template<typename T>
Matrix2D<T>::Matrix2D(Matrix2D<T>&& m)
    : nRows(m.nRows), nCols(m.nCols), data(m.data)
{
    m.data = nullptr;
}
template<typename T>
const Matrix2D<T>& Matrix2D<T>::operator=(const Matrix2D<T>& rhs)
{
    nRows = rhs.nRows;
    nCols = rhs.nCols;
    data = new T[nRows*nCols];
    for (size_t i = 0; i < nRows*nCols; ++i) 
    {
        data[i] = rhs.data[i];
    }
}
template<typename T>
const Matrix2D<T>& Matrix2D<T>::operator=(Matrix2D<T>&& rhs)
{
    nRows = rhs.nRows;
    nCols = rhs.nCols;
    data = rhs.data;
    rhs.data = nullptr;
}
template<typename T>
Matrix2D<T>::~Matrix2D()
{
    delete[] data;
}

template<typename T>
void Matrix2D<T>::Fill(T fillValue)
{
    for (size_t i = 0; i < nRows*nCols; ++i)
    {
        data[i] = fillValue;
    }
}
template<typename T>
void Matrix2D<T>::Print() const
{
    for (size_t i = 0; i < nRows*nCols; ++i)
    {
        std::cout << data[i] << ((i+1) % nRows*nCols == 0 ? '\n' : ' ');
    }
}
template<typename T>
void Matrix2D<T>::PrintArray() const
{
    for (size_t i = 0; i < nRows*nCols; ++i)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << '\n';
}
template<typename T>
void Matrix2D<T>::FillIncrement(T start, T inc)
{
    for (size_t i = 0; i <  nRows*nCols; ++i)
    {
        data[i] = start;
        start = start + inc;
    }
}

template<typename T>
T& Matrix2D<T>::at(size_t row, size_t col)
{
    return data[col + row*nCols];
}
template<typename T>
const T& Matrix2D<T>::at(size_t row, size_t col) const
{
    return data[col + row*nCols];
}

template<typename T>
Matrix2D<T> operator+(const Matrix2D<T>& lhs, const Matrix2D<T>& rhs)
{
    Matrix2D<T> m = lhs;
    for (size_t i = 0; i < m.nRows*m.nCols; ++i)
    {
        m.data[i] += rhs.data[i];
    }
    return m;
}
template<typename T>
Matrix2D<T> operator+(const T& lhs, const Matrix2D<T>& rhs)
{
    Matrix2D<T> m = rhs;
    for (size_t i = 0; i < m.nRows*m.nCols; ++i)
    {
        m.data[i] += lhs;
    }
    return m;
}
template<typename T>
Matrix2D<T> operator+(const Matrix2D<T>& lhs, const T& rhs)
{
    Matrix2D<T> m = lhs;
    for (size_t i = 0; i < m.nRows*m.nCols; ++i)
    {
        m.data[i] += rhs;
    }
    return m;
}

template<typename T>
Matrix2D<T>& Matrix2D<T>::operator+=(const Matrix2D<T>& rhs)
{
    for (size_t i = 0; i < nRows*nCols; ++i)
    {
        data[i] += rhs.data[i];
    }
    return *this;
}
template<typename T>
Matrix2D<T>& Matrix2D<T>::operator+=(const T& rhs)
{
    for (size_t i = 0; i < nRows*nCols; ++i)
    {
        data[i] += rhs;
    }
    return *this;
}

template<typename T>
Matrix2D<T> operator*(const Matrix2D<T>& lhs, const Matrix2D<T>& rhs)
{
    Matrix2D<T> m(lhs.nRows, rhs.nCols);
    for (size_t i = 0; i < lhs.nRows; ++i)
    {
        for (size_t j = 0; j < rhs.nCols; ++j)
        {
            m.at(i, j) = T();
            for (size_t k = 0; k < lhs.nCols; ++k)
            {
                m.at(i, j) += lhs.at(i, k) * rhs.at(k, j);
            }
        }
    }
    return m;
}
/*
template<typename T>
Matrix2D<T> operator*(const T& lhs, const Matrix2D<T>& rhs)
{
    Matrix2D<T> m = rhs;
    for (size_t i = 0; i < M*nRows*nCols; ++i)
    {
        m.data[i] *= lhs;
    }
    return m;
}
template<typename T>
Matrix2D<T> operator*(const Matrix2D<T>& lhs, const T& rhs)
{
    Matrix2D<T> m = lhs;
    for (size_t i = 0; i < M*nRows*nCols; ++i)
    {
        m.data[i] *= rhs;
    }
    return m;
}
*/
template<typename T>
Matrix2D<T>& Matrix2D<T>::operator*=(const Matrix2D<T>& rhs)
{
    // check if M equals nRows*nCols
    // create a temp
}

template<typename T>
Matrix2D<T>& Matrix2D<T>::operator*=(const T& rhs)
{
    for (size_t i = 0; i < nRows*nCols; ++i)
    {
        data[i] *= rhs;
    }
    return *this;
}