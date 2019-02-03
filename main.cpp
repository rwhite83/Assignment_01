#include <iostream>
#include "Matrix.cpp"

int main() {

    //matrix initialization with no parameter constructor
    //Matrix matrixZeroInput;

    //matrix initialization with one parameter constructor
    //populates entire matrix with the given value
    //Matrix matrixSingleInput(2);

    //matrix initialization with two parameters
    //Matrix matrixDoubleInput(4,4);

    //vector array to pass in
    vector<double> inputVectorArray{3, 4, 6, 7, 7, 4, 4, 9, 7};

    //matrix initialization a vector array as its parameter
    Matrix *matrixVectorArrayInput = new Matrix(inputVectorArray);

    //printing out the matrices for checking
    //matrixZeroInput.printMatrix();
    //matrixSingleInput.printMatrix();
    //matrixDoubleInput.printMatrix();
    matrixVectorArrayInput->printMatrix();

    // sets value at target position
    matrixVectorArrayInput->set_value(1, 1, 500);

    //extracts value at target position
    matrixVectorArrayInput->printMatrix();

    cout << matrixVectorArrayInput->get_value(1, 1) << "\n\n" << endl ;

    matrixVectorArrayInput->clear();

    matrixVectorArrayInput->printMatrix();

    return 0;
}