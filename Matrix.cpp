//
// Created by rwhit on 1/29/2019.
//

#include "Matrix.hpp"
#include <math.h>
#include <iomanip>

using namespace std;
//using namespace matrix;

constexpr int defaultMatrixSize = 1;

vector<vector<double>> vect;

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
void Matrix::set_value(int x, int y, double value){
    if (x < 0 || y < 0)  {
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

void Matrix::clear() {
    for (int i = 0; i < vect.size(); i++) {
        for (int j = 0; j < vect[i].size(); j++) {
            vect[i][j] = 0;
        }
    }
}

void Matrix::printMatrix() {
    for (int i = 0; i < vect.size(); i++) {
        for (int j = 0; j < vect[i].size(); j++) {
            cout << fixed << setprecision(1) << vect[i][j] << " ";
        }
        cout << "\n" << endl;
    }
    cout << endl;
}


