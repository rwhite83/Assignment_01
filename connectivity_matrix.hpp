//
// Created by rwhit on 2/3/2019.
//

#include <vector>

using namespace std;

#pragma once

class ConnectivityMatrix : public matrix {

public:

    //constructors
    ConnectivityMatrix() : matrix() {};
    ConnectivityMatrix(int single) : matrix(single) {};
    ConnectivityMatrix(int twin1, int twin2) : matrix (twin1, twin2) {} ;
    ConnectivityMatrix(vector<double> thisVectorArray) : matrix (thisVectorArray) {};

};