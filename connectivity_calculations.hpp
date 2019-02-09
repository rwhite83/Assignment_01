//
// Created by rwhit on 2/3/2019.
//

#include <vector>

using namespace std;

#pragma once

//calculates importance
matrix& findImportance(matrix&);

//assigns randomness
matrix& assignRandomness(matrix&);

//runs markov process
matrix& markovProcess(matrix&);

//does scaled rank division
matrix& scaledRank(matrix&);