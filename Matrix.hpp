//
// Created by rwhit on 1/29/2019.
//
#include <vector>

using namespace std;

#pragma once

class Matrix {

public:

    //member variables
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
    friend bool operator==(Matrix&, Matrix&);
    friend bool operator!=(Matrix&, Matrix&);
    Matrix& operator++();
    Matrix& operator++(int);
    Matrix& operator--();
    Matrix& operator--(int);
    friend void mySwap(Matrix&, Matrix);
    Matrix& operator=(Matrix&);
    friend Matrix& operator+(Matrix&, Matrix&);
    friend Matrix& operator-(Matrix&, Matrix&);
    Matrix& operator+=(Matrix&);
    Matrix& operator-=(Matrix&);
    friend Matrix& operator*(Matrix&, Matrix&);
    Matrix& operator*=(Matrix&);

};