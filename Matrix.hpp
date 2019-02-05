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
    friend ostream& operator<<(ostream&, const Matrix&);
    friend bool operator==(const Matrix&, const Matrix&);
    friend bool operator!=(const Matrix&, const Matrix&);
    Matrix& operator++();
    //Matrix Matrix::operator++(int) {
    Matrix operator++(int);
    Matrix& operator--();
    Matrix operator--(int);
    friend void mySwap(Matrix&, Matrix);
    Matrix& operator=(Matrix&);
    Matrix& operator+(const Matrix&);
    Matrix& operator-(const Matrix&);
    Matrix& operator+=(const Matrix&);
    Matrix& operator-=(const Matrix&);
    Matrix& operator*(const Matrix&);
    Matrix& operator*=(const Matrix&);

};