//
// Created by Richard on 2018/11/27.
//

#ifndef NNPLUSPLUS_MATRIX_EXCEPTIONS_HPP
#define NNPLUSPLUS_MATRIX_EXCEPTIONS_HPP

#include <exception>

class MatrixDimensionsMismatch : public std::exception {
    const char *what() const noexcept override {
        return "Matrix dimension must agree.\n";
    }
};

class MatrixInnderDimensionsMismatch : public std::exception {
    const char *what() const noexcept override {
        return "Matrix inner dimensions must agree.\n";
    }
};

#endif //NNPLUSPLUS_MATRIX_EXCEPTIONS_HPP
