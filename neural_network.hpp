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

public:
    NeuralNet(size_t input_nodes = 1, size_t hidden_nodes = 1,
              size_t output_nodes = 1, size_t hidden_layers = 1,
              double lr = 0.1);

    // A ctor that loads a saved neural net.
    // Expecting a filename with file type *.nn
    // Initializes a new net wit the weights saved
    // in the file.
    explicit NeuralNet(const std::string &filename);

    // Feed forward the input Matrix and return the
    // net's prediction in a Matrix.
    Matrix queryNet(const Matrix &input_list);

    // A single feed forward and back propagation with weight updates.
    void trainingCycle(const Matrix &inputList, const Matrix &targetOutput);

    // A method to save the current state of the net.
    // Files are saved as *.nn.
    // If no file name is supplied, file will be saved
    // with the time and date the net was saved.
    void saveNetwork(const std::string &name = "") const;

    // Load an existing net into the current object.
    void loadNetwork(const std::string &name);


};

#endif //NNPLUSPLUS_NEURAL_NETWORK_HPP
