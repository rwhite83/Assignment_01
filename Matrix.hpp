//
// Created by rwhit on 1/29/2019.
//
#include <vector>

using namespace std;

#pragma once

class Matrix {

public:

    vector<vector<double>> vect;

    //constructors
    Matrix();
    Matrix(int);
    Matrix(int, int);
    Matrix(vector<double> thisVectorArray);

    //member functions
    void printMatrix();
    void set_value(int, int, double);
    double get_value(int, int);
    void clear();

    //overloads
    ~Matrix();
    friend ostream& operator<<(ostream&, Matrix&);
    friend bool operator==(Matrix& RHSmtx, Matrix& LHSmtx);
    friend bool operator!=(Matrix& RHSmtx, Matrix& LHSmtx);
    Matrix& operator++();
    Matrix& operator++(int);
    Matrix& operator--();
    Matrix& operator--(int);
    friend void mySwap(Matrix& LHSmtx, Matrix RHSmtx);
    Matrix& operator=(Matrix&);
    friend Matrix& operator+(Matrix& LHSmtx, Matrix& RHSmtx);

};