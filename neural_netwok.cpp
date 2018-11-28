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

    for (size_t i = 0; i < weight_size; i++) {
        size_t curr_layer = 0;
        size_t next_layer = 0;

        if (i == 0) {
            curr_layer = m_in_nodes;
            next_layer = m_hidden_nodes;
        } else if (i == weight_size - 1) {
            curr_layer = m_hidden_nodes;
            next_layer = m_out_nodes;
        } else {
            curr_layer = hidden_nodes;
            next_layer = hidden_nodes;
        }

        m_weights.push_back(initializeMatrix(next_layer, curr_layer));
    }

    for (size_t i = 0; i < output_size; i++) {
        size_t num_of_nodes = 0;

        if (i == 0)
            num_of_nodes = m_in_nodes;
        else if (i == output_size - 1)
            num_of_nodes = m_out_nodes;
        else
            num_of_nodes = m_hidden_nodes;

        m_outputs.push_back(Matrix(num_of_nodes, 1));
    }

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

std::string NeuralNet::getCurrTime() const {
    time_t t = time(0);
    struct tm *now = localtime(&t);
    std::string currTime = std::to_string(now->tm_year + 1900) + '-' + \
    std::to_string(now->tm_mon + 1) + '-' + \
    std::to_string(now->tm_mday);
    currTime += "--" + ((now->tm_hour < 10) ? "0" + std::to_string(now->tm_hour) : std::to_string(now->tm_hour));
    currTime += "-" + ((now->tm_min < 10) ? "0" + std::to_string(now->tm_min) : std::to_string(now->tm_min));
    currTime += "-" + ((now->tm_sec < 10) ? "0" + std::to_string(now->tm_sec) : std::to_string(now->tm_sec));

    return currTime;
}