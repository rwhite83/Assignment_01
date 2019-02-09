//
// Created by rwhit on 2/3/2019.
//

#include <vector>

using namespace std;

#pragma once

//calculates importance
matrix& find_importance(matrix &mtx);

//assigns randomness
matrix& assign_randomness(matrix &mtx);

//runs markov process
matrix& markov_process(matrix &mtx);

//does scaled rank division
matrix& scaled_rank(matrix &mtx);

//fully processes a matrix
matrix& conduct_ranking(vector<double> input_vector_array);