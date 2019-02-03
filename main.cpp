#include <iostream>
#include <fstream>
#include "Matrix.cpp"
#include "ConnectivityMatrix.cpp"
#include "ConnectivityCalculations.cpp"

int main() {

    vector<double> inputVectorArray;

    ifstream in("connectivity.txt");

    if (!in) {
        cout << "file not found" << endl;
    }
    else {
        int value;
        while (in >> value) {
            inputVectorArray.push_back(value);
        }
    }

    Matrix two(inputVectorArray);

    //cout << two;

    findImportance(two);

    cout << two;

    assignRandomness(two);

    cout << two;

    markovProcess(two);

    cout << two;

    return 0;
}















/*    //matrix initialization with no parameter constructor
    ///Matrix matrixZeroInput;

    //matrix initialization with one parameter constructor
    //populates entire matrix with the given value
    Matrix matrixSingleInput(3);

    //matrix initialization with two parameters
    //Matrix matrixDoubleInput1(4,4);
    //Matrix matrixDoubleInput2(4,4);

    //vector array to pass in


    //matrix initialization a vector array as its parameter
    Matrix matrixVectorArrayInput1(inputVectorArray);
    Matrix matrixVectorArrayInput2(inputVectorArray);

    cout << matrixVectorArrayInput1;

    //printing out the matrices for checking
    //cout << matrixZeroInput << matrixSingleInput << matrixDoubleInput1 << matrixVectorArrayInput;

    // sets value at target position
    //matrixVectorArrayInput1.set_value(1, 1, 500);

    //cout << matrixVectorArrayInput;

    //cout << matrixVectorArrayInput.get_value(1, 1) << "\n\n" << endl ;

    //matrixVectorArrayInput1.clear();

    //cout << matrixVectorArrayInput;

*//*
    int x = 5;

    if (matrixSingleInput == matrixVectorArrayInput1) {
        x = 888;
    }
    else {
        x = 999;
    }
*//*

    //cout << matrixVectorArrayInput1 << endl;
    //++matrixVectorArrayInput1;
    //cout << matrixVectorArrayInput1 << endl;
    //matrixVectorArrayInput1++;
   // cout << matrixVectorArrayInput1 << endl;
    //cout << matrixVectorArrayInput2 << endl;
    //cout << matrixSingleInput;
    matrixVectorArrayInput1 *= matrixVectorArrayInput1;
    cout << matrixVectorArrayInput1;
    matrixVectorArrayInput1 *= matrixVectorArrayInput1;
    cout << matrixVectorArrayInput1;
    matrixVectorArrayInput1 -= matrixVectorArrayInput1;
    cout << matrixVectorArrayInput1;
    //cout << matrixSingleInput;
    //cout << matrixVectorArrayInput2 << endl;*/