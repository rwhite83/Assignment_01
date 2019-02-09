//
// Created by rwhit on 1/29/2019.
//

#include "matrix.hpp"
#include <math.h>
#include <iomanip>
#include <sstream>

using namespace std;
//using namespace matrix;

//constant expressino for default matrix size
constexpr int defaultMatrixSize = 1;

//default constructor
matrix::matrix() {

    //variable holding size of array
    int matrix_index = 1;

    // appropriately resizing one dimension of the 2D vector
    vect.resize(1);

    // incrementer for iterating through the thisVectorArray vector
    int v = 0;

    // loop for populating 2D vector
    for (int i = 0; i < matrix_index; i++) {
        vect[i].resize(matrix_index);
        for (int j = 0; j < matrix_index; j++) {
            vect[i][j] = 0;
            v++;
        }
    }
}

// one variable constructor
matrix::matrix(int n) {

    try {
        //guard against negative numbers and zero
        if (n <= 0) {
            throw "positive integers only";
        } else {

            //variable holding size of array
            int matrix_index = n;

            // appropriately resizing one dimension of the 2D vector
            vect.resize(matrix_index);

            // loop for populating 2D vector
            for (int i = 0; i < matrix_index; i++) {
                vect[i].resize(matrix_index);
                for (int j = 0; j < matrix_index; j++) {
                    vect[i][j] = 0.0;
                }
            }
        }
    }
    catch (const char *error_message) {
        cerr << error_message << endl;
        throw;
    }
}

//two variable constructor
matrix::matrix(int x, int y) {

    try {
        //guard against negative numbers and zero
        if (x <= 0 || y <= 0) {
            throw "positive integers only";
        } else {

            //variable holding size of array
            int matrix_index_x = x;
            int matrix_index_y = y;

            // appropriately resizing one dimension of the 2D vector
            vect.resize(x);

            // loop for populating 2D vector
            for (int i = 0; i < x; i++) {
                vect[i].resize(y);
                for (int j = 0; j < y; j++) {
                    vect[i][j] = 0.0;
                }
            }
        }
    }
    catch (const char *error_message) {
        cerr << error_message << endl;
        throw;
    }
}

//vector input constructor
matrix::matrix(vector<double> thisVectorArray) {

    try {
        //variable holding size of array
        int array_size = thisVectorArray.size();
        //variable holding square root of array
        int matrix_index = sqrt(array_size);

        //guard against non perfect square number of elements
        double perfectSquareCheck = sqrt((double) array_size);
        if (array_size != (matrix_index * matrix_index)) {
            throw "must be a perfect square";
        }

        // appropriately resizing one dimension of the 2D vector
        vect.resize(matrix_index);

        // incrementer for iterating through the thisVectorArray vector
        int v = 0;

        // loop for populating 2D vector
        for (int i = 0; i < matrix_index; i++) {
            vect[i].resize(matrix_index);
            for (int j = 0; j < matrix_index; j++) {
                vect[i][j] = thisVectorArray[v];
                v++;
            }
        }
    }
    catch (const char *error_message) {
        cerr << error_message << endl;
        throw;
    }
}

//sets value of a particular vector position
void matrix::set_value(int x, int y, double value) {
    if (x < 0 || y < 0) {
        cout << "matrix paramaters must be greater than or equal to zero" << endl;
    }
    if (x >= vect.size() || y >= vect[0].size()) {
        cout << "attempted location out of bounds of target matrix" << endl;
    }
    vect[x][y] = value;
}

//returns value of a particular vector position
double matrix::get_value(int x, int y) {
    if (x >= vect.size() || y >= vect[0].size()) {
        cout << "attempted location out of bounds of target matrix" << endl;
    }
    return vect[x][y];
}

//sets all matrix values to zero
void matrix::clear() {
    for (int i = 0; i < vect.size(); i++) {
        for (int j = 0; j < vect[i].size(); j++) {
            vect[i][j] = 0;
        }
    }
}

//overloaded destructor
matrix::~matrix() {
    cout << "matrix destroyed" << endl;
}

//overloaded insertion operator
ostream &operator<<(ostream &os, matrix &mtx) {
    for (int i = 0; i < mtx.vect.size(); i++) {
        for (int j = 0; j < mtx.vect[i].size(); j++) {
            os << fixed << setprecision(4) << mtx.vect[i][j] << " ";
        }
        os << "\n" << endl;
    }
    os << endl;
    return os;
}

//overloaded not equals operator
bool operator!=(matrix &LHSmtx, matrix &RHSmtx) {
    bool isNotEqual = false;
    for (int i = 0; i < LHSmtx.vect.size(); i++) {
        for (int j = 0; j < LHSmtx.vect[i].size(); j++) {
            if (abs((LHSmtx.vect[i][j] - RHSmtx.vect[i][j]) / RHSmtx.vect[i][j]) > 0.0001) {
                isNotEqual = true;
                return isNotEqual;
            }
        }
    }
}

//overloaded is equal to operator
bool operator==(matrix &LHSmtx, matrix &RHSmtx) {
    bool isEqual = true;
    for (int i = 0; i < RHSmtx.vect.size(); i++) {
        for (int j = 0; j < LHSmtx.vect[i].size(); j++) {
            if (abs((LHSmtx.vect[i][j] - RHSmtx.vect[i][j]) / RHSmtx.vect[i][j]) > 0.01) {
                isEqual = false;
                return isEqual;
            }
        }
    }
    return isEqual;
}

//overloaded prefix incrementer operator
matrix &matrix::operator++() {
    for (int i = 0; i < this->vect.size(); i++) {
        for (int j = 0; j < this->vect[i].size(); j++) {
            ++this->vect[i][j];
        }
    }
    return *this;
}

//overloaded postfix incrementer operator
matrix matrix::operator++(int) {
    matrix tempMatrix(*this);
    for (int i = 0; i < this->vect.size(); i++) {
        for (int j = 0; j < this->vect[i].size(); j++) {
            this->vect[i][j]++;
        }
    }
    return tempMatrix;
}

//overloaded prefix decrementer operator
matrix &matrix::operator--() {
    for (int i = 0; i < this->vect.size(); i++) {
        for (int j = 0; j < this->vect[i].size(); j++) {
            --this->vect[i][j];
        }
    }
    return *this;
}

//overloaded postfix decrementer operator
matrix matrix::operator--(int) {
    matrix tempMatrix(*this);
    for (int i = 0; i < this->vect.size(); i++) {
        for (int j = 0; j < this->vect[i].size(); j++) {
            this->vect[i][j]--;
        }
    }
    return tempMatrix;
}

//helper swap function
void mySwap(matrix &LHSmtx, matrix RHSmtx) {
    using std::swap;
    swap(LHSmtx.vect, RHSmtx.vect);
}

//overloaded assignment operator
matrix &matrix::operator=(const matrix &RHSmtx) {
    mySwap(*this, RHSmtx);
    return *this;
}

//overloaded addition operator
matrix &matrix::operator+(const matrix &RHSmtx) {
    if (RHSmtx.vect.size() != this->vect.size() || RHSmtx.vect[0].size() != this->vect[0].size()) {
        cout << "cannot add, matrices not equivalent" << endl;
    } else {
        for (int i = 0; i < this->vect.size(); i++) {
            for (int j = 0; j < this->vect[i].size(); j++) {
                this->vect[i][j] += RHSmtx.vect[i][j];
            }
        }
    }
    return *this;
}

//overloaded plus equals operator
matrix &matrix::operator+=(const matrix &RHSmtx) {
    if (RHSmtx.vect.size() != this->vect.size() || RHSmtx.vect[0].size() != this->vect[0].size()) {
        cout << "cannot add, matrices not equivalent" << endl;
    } else {
        *this = *this + RHSmtx;
    }
    return *this;
}

//overloaded minus operator
matrix &matrix::operator-(const matrix &RHSmtx) {
    if (RHSmtx.vect.size() != this->vect.size() || RHSmtx.vect[0].size() != this->vect[0].size()) {
        cout << "cannot add, matrices not equivalent" << endl;
    } else {
        for (int i = 0; i < this->vect.size(); i++) {
            for (int j = 0; j < this->vect[i].size(); j++) {
                this->vect[i][j] -= RHSmtx.vect[i][j];
            }
        }
    }
    return *this;
}

//overloaded minus equals operator
matrix &matrix::operator-=(const matrix &RHSmtx) {
    if (RHSmtx.vect.size() != this->vect.size() || RHSmtx.vect[0].size() != this->vect[0].size()) {
        cout << "cannot add, matrices not equivalent" << endl;
    } else {
        *this = *this - RHSmtx;
    }
    return *this;
}


matrix &matrix::operator*=(const matrix &RHSmtx) {

    if (this->vect[0].size() != RHSmtx.vect.size()) {
        cout << "cannot multiply these matrices" << endl;
    } else {
        matrix mtx3(this->vect.size(), RHSmtx.vect[0].size());
        for (int i = 0; i < mtx3.vect.size(); i++) {
            for (int j = 0; j < mtx3.vect[0].size(); j++) {
                for (int k = 0; k < this->vect.size(); k++) {
                    mtx3.vect[i][j] += this->vect[i][k] * RHSmtx.vect[k][j];
                }
            }
        }
        *this = mtx3;
    }
    return *this;
}


//overloaded times equal operator
matrix operator*(matrix LHSmtx, const matrix &RHSmtx) {

    LHSmtx *= RHSmtx;
    return LHSmtx;
}
