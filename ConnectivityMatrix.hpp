//
// Created by rwhit on 2/3/2019.
//

#include <vector>

using namespace std;

#pragma once

class ConnectivityMatrix : public Matrix {

public:

    //constructors
    ConnectivityMatrix() : Matrix() {};
    ConnectivityMatrix(int single) : Matrix(single) {};
    ConnectivityMatrix(int twin1, int twin2) : Matrix (twin1, twin2) {} ;
    ConnectivityMatrix(vector<double> thisVectorArray) : Matrix (thisVectorArray) {};

};