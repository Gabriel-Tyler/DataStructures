#pragma once

#include <iostream>

template<typename T, size_t M, size_t N> 
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

    T& at(size_t row, size_t col);
    const T& at(size_t row, size_t col) const;

    template<typename S, size_t I, size_t J>
    friend Matrix2D<S, I, J> operator+(const Matrix2D<S, I, J>& lhs, const Matrix2D<S, I, J>& rhs);
    template<typename S, size_t I, size_t J>
    friend Matrix2D<S, I, J> operator+(const S& lhs, const Matrix2D<S, I, J>& rhs);
    template<typename S, size_t I, size_t J>
    friend Matrix2D<S, I, J> operator+(const Matrix2D<S, I, J>& lhs, const S& rhs);

    Matrix2D& operator+=(const Matrix2D& rhs);
    Matrix2D& operator+=(const T& rhs);

    template<typename S, size_t I, size_t J, size_t K>
    friend Matrix2D<S, I, K> operator*(const Matrix2D<S, I, J>& lhs, const Matrix2D<S, J, K>& rhs);

    // template<typename T, size_t M, size_t N>
    // friend Matrix2D<T, M, N> operator*(const T& lhs, const Matrix2D<T, M, N>& rhs);
    // template<typename T, size_t M, size_t N>
    // friend Matrix2D<T, M, N> operator*(const Matrix2D<T, M, N>& lhs, const T& rhs);

    Matrix2D& operator*=(const Matrix2D& rhs);
    Matrix2D& operator*=(const T& rhs);

    // friend Matrix2D<T, M, N> operator/(const Matrix2D<T, M, N>& lhs, const T& rhs);
    // Matrix2D& operator/=(const T& rhs);
};

template<typename T, size_t M, size_t N>
Matrix2D<T, M, N>::Matrix2D()
{
    data = new T[M*N];
}
template<typename T, size_t M, size_t N>
Matrix2D<T, M, N>::Matrix2D(const Matrix2D& m)
{
    data = new T[M*N];
    for (size_t i = 0; i < M*N; ++i) 
    {
        data[i] = m.data[i];
    }
}
template<typename T, size_t M, size_t N>
Matrix2D<T, M, N>::Matrix2D(Matrix2D&& m)
{
    data = m.data;
    m.data = nullptr;
}
template<typename T, size_t M, size_t N>
const Matrix2D<T, M, N>& Matrix2D<T, M, N>::operator=(const Matrix2D& rhs)
{
    data = new T[M*N];
    for (size_t i = 0; i < M*N; ++i) 
    {
        data[i] = rhs.data[i];
    }
}
template<typename T, size_t M, size_t N>
const Matrix2D<T, M, N>& Matrix2D<T, M, N>::operator=(Matrix2D&& rhs)
{
    data = rhs.data;
    rhs.data = nullptr;
}
template<typename T, size_t M, size_t N>
Matrix2D<T, M, N>::~Matrix2D()
{
    delete[] data;
}

template<typename T, size_t M, size_t N>
void Matrix2D<T, M, N>::Fill(T fillValue)
{
    size_t size = M*N;
    for (size_t i = 0; i < size; ++i)
    {
        data[i] = fillValue;
    }
}
template<typename T, size_t M, size_t N>
void Matrix2D<T, M, N>::Print() const
{ 
    size_t size = M*N;
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << data[i] << ((i+1) % N == 0 ? '\n' : ' ');
    }
}
template<typename T, size_t M, size_t N>
void Matrix2D<T, M, N>::PrintArray() const
{
    size_t size = M*N;
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << '\n';
}
template<typename T, size_t M, size_t N>
void Matrix2D<T, M, N>::FillIncrement(T start, T inc)
{
    size_t size = M*N;
    for (size_t i = 0; i < size; ++i)
    {
        data[i] = start;
        start = start + inc;
    }
}

template<typename T, size_t M, size_t N>
T& Matrix2D<T, M, N>::at(size_t row, size_t col)
{
    return data[col + row*N];
}
template<typename T, size_t M, size_t N>
const T& Matrix2D<T, M, N>::at(size_t row, size_t col) const
{
    return data[col + row*N];
}

template<typename T, size_t M, size_t N>
Matrix2D<T, M, N> operator+(const Matrix2D<T, M, N>& lhs, const Matrix2D<T, M, N>& rhs)
{
    Matrix2D<T, M, N> m = lhs;
    for (size_t i = 0; i < M*N; ++i)
    {
        m.data[i] += rhs.data[i];
    }
    return m;
}
template<typename T, size_t M, size_t N>
Matrix2D<T, M, N> operator+(const T& lhs, const Matrix2D<T, M, N>& rhs)
{
    Matrix2D<T, M, N> m = rhs;
    for (size_t i = 0; i < M*N; ++i)
    {
        m.data[i] += lhs;
    }
    return m;
}
template<typename T, size_t M, size_t N>
Matrix2D<T, M, N> operator+(const Matrix2D<T, M, N>& lhs, const T& rhs)
{
    Matrix2D<T, M, N> m = lhs;
    for (size_t i = 0; i < M*N; ++i)
    {
        m.data[i] += rhs;
    }
    return m;
}

template<typename T, size_t M, size_t N>
Matrix2D<T, M, N>& Matrix2D<T, M, N>::operator+=(const Matrix2D<T, M, N>& rhs)
{
    for (size_t i = 0; i < M*N; ++i)
    {
        data[i] += rhs.data[i];
    }
    return *this;
}
template<typename T, size_t M, size_t N>
Matrix2D<T, M, N>& Matrix2D<T, M, N>::operator+=(const T& rhs)
{
    for (size_t i = 0; i < M*N; ++i)
    {
        data[i] += rhs;
    }
    return *this;
}

template<typename T, size_t M, size_t N, size_t K>
Matrix2D<T, M, K> operator*(const Matrix2D<T, M, N>& lhs, const Matrix2D<T, N, K>& rhs)
{
    Matrix2D<T, M, K> m;
    for (size_t i = 0; i < M; ++i)
    {
        for (size_t j = 0; j < K; ++j)
        {
            m.at(i, j) = T();
            for (size_t k = 0; k < N; ++k)
            {
                m.at(i, j) += lhs.at(i, k) * rhs.at(k, j);
            }
        }
    }
    return m;
}
/*
template<typename T, size_t M, size_t N>
Matrix2D<T, M, N> operator*(const T& lhs, const Matrix2D<T, M, N>& rhs)
{
    Matrix2D<T, M, N> m = rhs;
    for (size_t i = 0; i < M*N; ++i)
    {
        m.data[i] *= lhs;
    }
    return m;
}
template<typename T, size_t M, size_t N>
Matrix2D<T, M, N> operator*(const Matrix2D<T, M, N>& lhs, const T& rhs)
{
    Matrix2D<T, M, N> m = lhs;
    for (size_t i = 0; i < M*N; ++i)
    {
        m.data[i] *= rhs;
    }
    return m;
}
*/
template<typename T, size_t M, size_t N>
Matrix2D<T, M, N>& Matrix2D<T, M, N>::operator*=(const Matrix2D<T, M, N>& rhs)
{
    // check if M equals N
    // create a temp
}

template<typename T, size_t M, size_t N>
Matrix2D<T, M, N>& Matrix2D<T, M, N>::operator*=(const T& rhs)
{
    for (size_t i = 0; i < M*N; ++i)
    {
        data[i] *= rhs;
    }
    return *this;
}