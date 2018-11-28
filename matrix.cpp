//
// Created by GUO on 2018/11/28.
//

#include "matrix.hpp"

Matrix::Matrix(size_t m, size_t n)
        : m_size_(m), n_size_(n) {
    matrix_ = new double[m_size_ * n_size_]();  // initialized to 0
    row_ptrs_ = new double *[m_size_];

    for (size_t i = 0; i < m_size_; i++)
        row_ptrs_[i] = &matrix_[i * n_size_];

}

Matrix::Matrix(const Matrix &rhs)
        : m_size_(rhs.m_size_), n_size_(rhs.n_size_) {
    matrix_ = new double[m_size_ * n_size_]();
    row_ptrs_ = new double *[m_size_];

    for (size_t i = 0; i < m_size_ * n_size_; i++)
        matrix_[i] = rhs.matrix_[i];

    for (size_t i = 0; i < m_size_; i++)
        row_ptrs_[i] = &matrix_[i * n_size_];
}


Matrix &Matrix::operator=(const Matrix &rhs) {
    if (this != &rhs) {
        Matrix copy{rhs};
        std::swap(*this, copy);
    }
    return *this;
}

Matrix::Matrix(Matrix &&rhs)
        : m_size_(rhs.m_size_),
          n_size_(rhs.n_size_),
          matrix_(rhs.matrix_),
          row_ptrs_(rhs.row_ptrs_) {

    rhs.m_size_ = 0;
    rhs.n_size_ = 0;
    rhs.matrix_ = nullptr;
    rhs.row_ptrs_ = nullptr;

}

Matrix &Matrix::operator=(Matrix &&rhs) {
    std::swap(m_size_, rhs.m_size_);
    std::swap(n_size_, rhs.n_size_);
    std::swap(matrix_, rhs.matrix_);
    std::swap(row_ptrs_, rhs.row_ptrs_);

    return *this;
}

Matrix::~Matrix() {
    delete[] matrix_;
    delete[] row_ptrs_;
}

double &Matrix::operator()(size_t row, size_t col) {
    return row_ptrs_[row][col];
}

const double &Matrix::operator()(size_t row, size_t col) const {
    return row_ptrs_[row][col];
}

Matrix &Matrix::operator+=(const Matrix &rhs) {
    if (m_size_ == rhs.m_size_ && n_size_ == rhs.n_size_) {
        for (size_t i = 0; i < m_size_ * n_size_; i++)
            matrix_[i] += rhs.matrix_[i];
        return *this;
    } else {
        throw MatrixDimensionsMismatch();
    }
}

Matrix &Matrix::operator+=(double scalar) {
    for (size_t i = 0; i < m_size_ * n_size_; i++)
        matrix_[i] += scalar;
    return *this;
}

Matrix operator+(Matrix lhs, const Matrix &rhs) {
    if (lhs.m_size_ == rhs.m_size_ && lhs.n_size_ == rhs.n_size_)
        return lhs += rhs;
    else
        throw MatrixDimensionsMismatch();

}

Matrix operator+(Matrix lhs, double scalar) {
    return lhs += scalar;
}

Matrix operator+(double scalar, Matrix rhs) {
    return rhs += scalar;
}

Matrix &Matrix::operator-=(const Matrix &rhs) {
    if (m_size_ == rhs.m_size_ && n_size_ == rhs.n_size_) {
        for (size_t i = 0; i < m_size_ * n_size_; i++)
            matrix_[i] -= rhs.matrix_[i];
        return *this;
    } else
        throw MatrixDimensionsMismatch();
}

Matrix &Matrix::operator-=(double scalar) {
    for (size_t i = 0; i < m_size_ * n_size_; i++)
        matrix_[i] -= scalar;
    return *this;
}

Matrix operator-(Matrix lhs, const Matrix &rhs) {
    if (lhs.m_size_ == rhs.m_size_ && lhs.n_size_ == rhs.n_size_)
        return lhs -= rhs;
    else
        throw MatrixDimensionsMismatch();

}

Matrix operator-(Matrix lhs, double scalar) {
    return lhs -= scalar;
}

Matrix &Matrix::operator*=(const Matrix &rhs) {
    if (m_size_ == rhs.m_size_ && n_size_ == rhs.n_size_) {
        for (size_t i = 0; i < m_size_ * n_size_; i++)
            matrix_[i] *= rhs.matrix_[i];
        return *this;
    } else
        throw MatrixDimensionsMismatch();

}

Matrix &Matrix::operator*=(double scalar) {
    for (size_t i = 0; i < m_size_ * n_size_; i++)
        matrix_[i] *= scalar;
    return *this;
}

Matrix operator*(Matrix lhs, const Matrix &rhs) {
    if (lhs.m_size_ == rhs.m_size_ && lhs.n_size_ == rhs.n_size_)
        return lhs *= rhs;
    else
        throw MatrixDimensionsMismatch();

}

Matrix operator*(Matrix lhs, double scalar) {
    return lhs *= scalar;
}

Matrix operator*(double scalar, Matrix rhs) {
    return rhs *= scalar;
}

