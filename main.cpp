#include <iostream>
#include "Matrix.cpp"

int main() {

    //matrix initialization with no parameter constructor
    ///Matrix matrixZeroInput;

    //matrix initialization with one parameter constructor
    //populates entire matrix with the given value
    //Matrix matrixSingleInput(2);

    //matrix initialization with two parameters
    //Matrix matrixDoubleInput1(4,4);
    //Matrix matrixDoubleInput2(4,4);

    //vector array to pass in
    vector<double> inputVectorArray{3, 4, 6, 7, 7, 4, 4, 9, 7};

    //matrix initialization a vector array as its parameter
    Matrix matrixVectorArrayInput1(inputVectorArray);
    Matrix matrixVectorArrayInput2(inputVectorArray);


    //printing out the matrices for checking
    //cout << matrixZeroInput << matrixSingleInput << matrixDoubleInput1 << matrixVectorArrayInput;

    // sets value at target position
    //matrixVectorArrayInput1.set_value(1, 1, 500);

    //cout << matrixVectorArrayInput;

    //cout << matrixVectorArrayInput.get_value(1, 1) << "\n\n" << endl ;

    //matrixVectorArrayInput1.clear();

    //cout << matrixVectorArrayInput;

/*
    int x = 5;

    if (matrixSingleInput == matrixVectorArrayInput1) {
        x = 888;
    }
    else {
        x = 999;
    }
*/

    cout << matrixVectorArrayInput1 << endl;
    ++matrixVectorArrayInput1;
    cout << matrixVectorArrayInput1 << endl;
    matrixVectorArrayInput1++;
    cout << matrixVectorArrayInput1 << endl;
    cout << matrixVectorArrayInput2 << endl;
    matrixVectorArrayInput2 = matrixVectorArrayInput1 + matrixVectorArrayInput2;
    cout << matrixVectorArrayInput2 << endl;


    return 0;
}