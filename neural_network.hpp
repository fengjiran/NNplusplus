//
// Created by GUO on 2018/11/28.
//

#ifndef NNPLUSPLUS_NEURAL_NETWORK_HPP
#define NNPLUSPLUS_NEURAL_NETWORK_HPP

#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <random>
#include <cmath>
#include <ctime>
#include "matrix.hpp"

class NeuralNet {
private:
    size_t m_in_nodes;
    size_t m_hidden_nodes;
    size_t m_out_nodes;
    size_t m_hidden_layers;
    double m_lr;  // learning rate

    std::vector<Matrix> m_weights;  // the weight matrices
    std::vector<Matrix> m_outputs;  // the intermediate outputs of all the
    // layers are required for training.
    // this is where they are stored.

    // Initializes the weights (parameters) between the different layers
    // Initial values are being drawn from a normal distribution centered
    // at 0, with standard deviation of
    // (number_of_inputs_to_nodes_in_next_layer)^(-0.5)
    Matrix initializeMatrix(size_t m, size_t n) const;

    // The activation function. Currently using Sigmoid function.
    double activationFunction(double x) const;

    // A utility function to get the current time in a string.
    // Used to name neural nets when saved.
    std::string getCurrTime() const;

};

#endif //NNPLUSPLUS_NEURAL_NETWORK_HPP
