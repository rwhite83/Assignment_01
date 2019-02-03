//
// Created by rwhit on 1/29/2019.
//

#include "Matrix.hpp"
#include <math.h>
#include <iomanip>
#include <sstream>

using namespace std;
//using namespace matrix;

//constant expressino for default matrix size
constexpr int defaultMatrixSize = 1;

//default constructor
Matrix::Matrix() {

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
Matrix::Matrix(int n) {

    //guard against negative numbers and zero
    if (n <= 0) {
        perror("positive integers only");
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

//two variable constructor
Matrix::Matrix(int x, int y) {

    //guard against negative numbers and zero
    if (x <= 0 || y <= 0) {
        perror("positive integers only");
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

//vector input constructor
Matrix::Matrix(vector<double>
               thisVectorArray) {

    //variable holding size of array
    int array_size = thisVectorArray.size();
    //variable holding square root of array
    int matrix_index = sqrt(array_size);

    //guard against non perfect square number of elements
    double perfectSquareCheck = sqrt((double) array_size);
    if (array_size != (matrix_index * matrix_index)) {
        perror("must be a perfect square");
        return;
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

//sets value of a particular vector position
void Matrix::set_value(int x, int y, double value) {
    if (x < 0 || y < 0) {
        cout << "matrix paramaters must be greater than or equal to zero" << endl;
    }
    if (x >= vect.size() || y >= vect[0].size()) {
        cout << "attempted location out of bounds of target matrix" << endl;
    }
    vect[x][y] = value;
}

//returns value of a particular vector position
double Matrix::get_value(int x, int y) {
    if (x >= vect.size() || y >= vect[0].size()) {
        cout << "attempted location out of bounds of target matrix" << endl;
    }
    return vect[x][y];
}

//sets all matrix values to zero
void Matrix::clear() {
    for (int i = 0; i < vect.size(); i++) {
        for (int j = 0; j < vect[i].size(); j++) {
            vect[i][j] = 0;
        }
    }
}

//overloaded destructor
Matrix::~Matrix() {
    cout << "matrix destroyed" << endl;
}

/*void Matrix::printMatrix() {
    for (int i = 0; i < vect.size(); i++) {
        for (int j = 0; j < vect[i].size(); j++) {
            cout << fixed << setprecision(1) << vect[i][j] << " ";
        }
        cout << "\n" << endl;
    }
    cout << endl;
}*/

//overloaded insertion operator
ostream &operator<<(ostream &os, Matrix &mtx) {
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
bool operator!=(Matrix& LHSmtx, Matrix& RHSmtx) {
    bool isNotEqual = false;
    for (int i = 0; i < LHSmtx.vect.size(); i++) {
        for (int j = 0; j < LHSmtx.vect[i].size(); j++) {
            if (abs((LHSmtx.vect[i][j] - RHSmtx.vect[i][j]) / RHSmtx.vect[i][j]) > 0.01) {
                isNotEqual = true;
                return isNotEqual;
            }
        }
    }
}

//overloaded is equal to operator
bool operator==(Matrix& LHSmtx, Matrix& RHSmtx) {
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
Matrix& Matrix::operator++() {
    for (int i = 0; i < this->vect.size(); i++) {
        for (int j = 0; j < this->vect[i].size(); j++) {
            ++this->vect[i][j];
        }
    }
    return *this;
}

//overloaded postfix incrementer operator
Matrix& Matrix::operator++(int) {
    Matrix tempMatrix(*this);
    for (int i = 0; i < this->vect.size(); i++) {
        for (int j = 0; j < this->vect[i].size(); j++) {
            this->vect[i][j]++;
        }
    }
    return tempMatrix;
}

//overloaded prefix decrementer operator
Matrix& Matrix::operator--() {
    for (int i = 0; i < this->vect.size(); i++) {
        for (int j = 0; j < this->vect[i].size(); j++) {
            --this->vect[i][j];
        }
    }
    return *this;
}

//overloaded postfix decrementer operator
Matrix& Matrix::operator--(int) {
    Matrix tempMatrix(*this);
    for (int i = 0; i < this->vect.size(); i++) {
        for (int j = 0; j < this->vect[i].size(); j++) {
            this->vect[i][j]--;
        }
    }
    return tempMatrix;
}

//helper swap function
void mySwap(Matrix &LHSmtx, Matrix RHSmtx) {
    using std::swap;
    swap(LHSmtx.vect, RHSmtx.vect);
}

//overloaded equals operator
Matrix& Matrix::operator=(Matrix &RHSmtx) {
    mySwap(*this, RHSmtx);
    return *this;
}

//overloaded addition operator
Matrix& operator+(Matrix &LHSmtx, Matrix &RHSmtx) {
    if (RHSmtx.vect.size() != LHSmtx.vect.size() || RHSmtx.vect[0].size() != LHSmtx.vect[0].size()) {
        cout << "cannot add, matrices not equivalent" << endl;
    } else {
        for (int i = 0; i < LHSmtx.vect.size(); i++) {
            for (int j = 0; j < LHSmtx.vect[i].size(); j++) {
                LHSmtx.vect[i][j] += RHSmtx.vect[i][j];
            }
        }
    }
    return LHSmtx;
}

//overloaded plus equals operator
Matrix& Matrix::operator+=(Matrix& RHSmtx) {
    if (RHSmtx.vect.size() != this->vect.size() || RHSmtx.vect[0].size() != this->vect[0].size()) {
        cout << "cannot add, matrices not equivalent" << endl;
    } else {
        *this = RHSmtx + *this;
    }
    return *this;
}

//overloaded minus operator
Matrix& operator-(Matrix &LHSmtx, Matrix &RHSmtx) {
    if (RHSmtx.vect.size() != LHSmtx.vect.size() || RHSmtx.vect[0].size() != LHSmtx.vect[0].size()) {
        cout << "cannot add, matrices not equivalent" << endl;
    } else {
        for (int i = 0; i < LHSmtx.vect.size(); i++) {
            for (int j = 0; j < LHSmtx.vect[i].size(); j++) {
                LHSmtx.vect[i][j] -= RHSmtx.vect[i][j];
            }
        }
    }
    return LHSmtx;
}

//overloaded minus equals operator
Matrix& Matrix::operator-=(Matrix& RHSmtx) {
    if (RHSmtx.vect.size() != this->vect.size() || RHSmtx.vect[0].size() != this->vect[0].size()) {
        cout << "cannot add, matrices not equivalent" << endl;
    } else {
        *this = *this - RHSmtx;
    }
    return *this;
}

//overloaded multiply operator
Matrix& operator*(Matrix &LHSmtx, Matrix &RHSmtx) {
    if (RHSmtx.vect.size() != LHSmtx.vect[0].size()) {
        cout << "cannot add, matrices not equivalent" << endl;
    } else {
        for (int i = 0; i < LHSmtx.vect.size(); i++) {
            for (int j = 0; j < LHSmtx.vect[i].size(); j++) {
                LHSmtx.vect[i][j] *= RHSmtx.vect[i][j];
            }
        }
    }
    return LHSmtx;
}

//overloaded times equal operator
Matrix& Matrix::operator*=(Matrix& RHSmtx) {
    if (RHSmtx.vect.size() != this->vect[0].size()) {
        cout << "cannot add, matrices not equivalent" << endl;
    } else {
        *this = (*this) * RHSmtx;
    }
    return *this;
}