//
// Created by GUO on 2018/11/28.
//

#include "matrix.hpp"

Matrix::Matrix(size_t m, size_t n) : m_size_(m), n_size_(n) {
    matrix_ = new double[m_size_ * n_size_]();  // initialized to 0
    row_ptrs_ = new double *[m_size_];

    for (size_t i = 0; i < m_size_; i++)
        row_ptrs_[i] = &matrix_[i * n_size_];

}