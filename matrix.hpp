//
// Created by Richard on 2018/11/27.
//

//  A matrix object, which includes basic operations such as
//  matrix transpose and dot product.

#ifndef NNPLUSPLUS_MATRIX_HPP
#define NNPLUSPLUS_MATRIX_HPP

#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

#include "matrix_exceptions.hpp"

class Matrix {
private:
    size_t m_size_;  // typedef unsigned long long int size_t, (M)xN
    size_t n_size_;  // Mx(N)
    double *matrix_;  // A pointer to the array.
    double **row_ptrs_; // An array of row pointers.
    // used to avoid repeated arithmetics at each access to the matrix.
public:
    /**********************************************************
     * Constructors
     **********************************************************/

    // Basic ctor to initialize a matrix of size m by n.
    // All matrix positions will be initialized to 0.
    explicit Matrix(size_t m = 0, size_t n = 0);

    // copy ctor
    Matrix(const Matrix &rhs);

    // copy assignment operator
    Matrix &operator=(const Matrix &rhs);

    // move ctor
    Matrix(Matrix &&rhs);

    // move assignment operator
    Matrix &operator=(Matrix &&rhs);

    // dealloc matrix_ (ctor)
    ~Matrix();

    /**********************************************************
     * Operator Overloads
     **********************************************************/

    // a substitute to operator[] for a 2D array
    double &operator()(size_t row, size_t col);

    const double &operator()(size_t row, size_t col) const;

    // addition
    Matrix &operator+=(const Matrix &rhs);

    Matrix &operator+=(double scalar);

    // term by term addition operator for two matricies
    friend Matrix operator+(Matrix lhs, const Matrix &rhs);

    // term by term addition operator for matrix and scalar
    friend Matrix operator+(Matrix lhs, double scalar);

    // allowing for the scalar addition commutative property
    friend Matrix operator+(double scalar, Matrix rhs);


    // subtraction
    Matrix &operator-=(const Matrix &rhs);

    Matrix &operator-=(double scalar);

    friend Matrix operator-(Matrix lhs, const Matrix &rhs);

    friend Matrix operator-(Matrix lhs, double scalar);

    friend Matrix operator-(double scalar, Matrix rhs);


    // multiplication
    Matrix &operator*=(const Matrix &rhs);

    Matrix &operator*=(double scalar);

    friend Matrix operator*(Matrix lhs, const Matrix &rhs);

    friend Matrix operator*(Matrix lhs, double scalar);

    friend Matrix operator*(double scalar, Matrix rhs);


    // division
    Matrix &operator/=(const Matrix &rhs);

    Matrix &operator/=(double scalar);

    friend Matrix operator/(Matrix lhs, const Matrix &rhs);

    friend Matrix operator/(Matrix lhs, double scalar);

    friend Matrix operator/(double scalar, Matrix rhs);

    // unary minus operator for matrix term by term negative
    Matrix operator-() const;


    /**********************************************************
     * Other functions
     **********************************************************/

    // A simple matrix algebra dot product operation.
    // Return a 0 by 0 matrix if the dimensions do not match.
    // See operator*(Matrix &rhs) for term by term multiplication.
    Matrix dot(const Matrix &rhs) const;

    // Get number of rows (M)xN
    size_t getNumberOfRows() const;

    // Get number of columns Mx(N)
    size_t getNumberOfCols() const;

    // Transpose the matrix MxN -> NxM
    Matrix T() const;

    // Get the coordinates of the largest value in the matrix.
    // Will return the coordinates of the earliest larger val.
    std::pair<size_t, size_t> getMaxVal() const;

    // print the matrix to std::cout
    void printMtrx() const;

};

#endif //NNPLUSPLUS_MATRIX_HPP
