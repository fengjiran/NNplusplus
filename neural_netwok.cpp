//
// Created by GUO on 2018/11/28.
//

#include <fstream>
#include "neural_network.hpp"

NeuralNet::NeuralNet(size_t input_nodes, size_t hidden_nodes,
                     size_t output_nodes, size_t hidden_layers, double lr)
        : m_in_nodes(input_nodes), m_hidden_nodes(hidden_nodes),
          m_out_nodes(output_nodes), m_hidden_layers(hidden_layers),
          m_lr(lr), m_weights(std::vector<Matrix>()),
          m_outputs(std::vector<Matrix>()) {

    size_t weight_size = m_hidden_layers + 1;
    m_weights.reserve(weight_size);

    size_t output_size = m_hidden_layers + 2;
    m_outputs.reserve(output_size);


}

Matrix NeuralNet::initializeMatrix(size_t rows, size_t cols) const {
    Matrix init(rows, cols);
    std::default_random_engine generator((std::random_device()()));
    std::normal_distribution<double> distribution(0.0, std::pow(rows, -0.5));

    for (size_t m = 0; m < rows; m++)
        for (size_t n = 0; n < cols; n++)
            init(m, n) = distribution(generator);

    return init;
}

double NeuralNet::activationFunction(double x) const {
    return 1 / (1 + std::exp(-x));
}