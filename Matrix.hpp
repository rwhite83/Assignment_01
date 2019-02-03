//
// Created by rwhit on 1/29/2019.
//
#include <vector>

using namespace std;

#pragma once

class Matrix {

public:

    Matrix();

    Matrix(int n);

    Matrix(int x, int y);

    Matrix(vector<double> thisVectorArray);

    void printMatrix();

    void set_value(int x, int y, double value);

    double get_value(int x, int y);

    void clear();

};