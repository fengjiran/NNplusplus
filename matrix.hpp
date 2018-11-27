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
    Matrix(size_t m = 0, size_t n = 0);

    // copy ctor
    Matrix(const Matrix &rhs);

    // copy assignment operator
    Matrix &operator=(const Matrix &rhs);

};

#endif //NNPLUSPLUS_MATRIX_HPP
