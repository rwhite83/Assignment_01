//
// Created by rwhit on 1/29/2019.
//
#include <vector>

using namespace std;

#pragma once

class matrix {

public:

    //member variables
    vector<vector<double>> vect;

    //constructors
    matrix();
    matrix(int);
    matrix(int, int);
    matrix(vector<double> thisVectorArray);

    //member functions
    void printMatrix();
    void set_value(int, int, double);
    double get_value(int, int);
    void clear();

    //overloads
    ~matrix();
    friend ostream& operator<<(ostream&, const matrix&);
    friend bool operator==(const matrix&, const matrix&);
    friend bool operator!=(const matrix&, const matrix&);
    matrix& operator++();
    matrix operator++(int);
    matrix& operator--();
    matrix operator--(int);
    friend void mySwap(matrix&, matrix);
    matrix& operator=(const matrix&);
    matrix& operator+(const matrix&);
    matrix& operator-(const matrix&);
    matrix& operator+=(const matrix&);
    matrix& operator-=(const matrix&);
    friend matrix operator*(matrix, const matrix&);
    matrix& operator*=(const matrix&);

};