#include <iostream>
#include <fstream>
#include "matrix.cpp"
#include "connectivity_matrix.cpp"
#include "connectivity_calculations.cpp"

int main() {

    vector<double> inputVectorArray2{4,3,2,3,4};

    matrix matrix1(inputVectorArray2);

    vector<double> inputVectorArray{};
    try {
        ifstream in("connectivity.txt");
        if (!in) {
            throw "file not found";
        } else {
            int value;
            while (in >> value) {
                inputVectorArray.push_back(value);
            }
        }
    }
    catch (const char *error_message) {
        cerr << error_message << endl;
        throw;
    }

    matrix one(inputVectorArray);

    cout << "base matrix: " << endl << one << endl;

    findImportance(one);

    matrix two = one;

    cout << "find importance matrix: " << endl << two << endl;

    assignRandomness(two);

    matrix three = two;

    cout << "assign randomness matrix: " << endl << three << endl;

    markovProcess(three);

    matrix four = three;

    cout << endl << endl;

    cout << "markov process matrix: " << endl << four << endl;

    scaledRank(four);

    matrix five = four;

    cout << "scaled rank matrix: " << endl << five << endl;

    return 0;
}

