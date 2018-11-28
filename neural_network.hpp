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

};

#endif //NNPLUSPLUS_NEURAL_NETWORK_HPP
