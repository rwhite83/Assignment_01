//
// Created by rwhit on 2/3/2019.
//

#include "ConnectivityCalculations.hpp"
#include <math.h>
#include <iomanip>
#include <sstream>

double P{0.85};
double Q{1 - P};

Matrix &findImportance(Matrix &mtx) {
    for (int i = 0; i < mtx.vect.size(); i++) {
        double columnSum = 0;
        double columnValuedCount = 0;
        for (int j = 0; j < mtx.vect[i].size(); j++) {
            columnSum += mtx.vect[j][i];
            if (mtx.vect[j][i] != 0) {
                columnValuedCount++;
            }
        }
        if (columnSum == 0) {
            for (int j = 0; j < mtx.vect[i].size(); j++) {
                mtx.vect[j][i] = (double) 1 / mtx.vect[i].size();
            }
        } else {
            for (int j = 0; j < mtx.vect[i].size(); j++) {
                if (mtx.vect[j][i] != 0) {
                    mtx.vect[j][i] = (double) 1 / columnValuedCount;
                }
            }
        }
    }
}

Matrix &assignRandomness(Matrix &mtx) {
    double S, R;
    for (int i = 0; i < mtx.vect.size(); i++) {
        for (int j = 0; j < mtx.vect[i].size(); j++) {
            S = mtx.vect[i][j] * P;
            R = ((double) 1 / mtx.vect[i].size()) * Q;
            double newValue = S + R;
            //cout << S << " " << R << " " << newValue << endl;
            mtx.vect[i][j] = newValue;
        }
    }
}

Matrix &markovProcess(Matrix &mtx) {
    vector<double> M, N{1, 1, 1, 1};
    while (M != N) {
        for (int i = 0; i < mtx.vect.size(); i++) {
            double rowSum = 0;
            for (int j = 0; j < mtx.vect[i].size(); j++) {
                rowSum += mtx.vect[i][j];
            }
            M.push_back(rowSum);
        }
        for (int k = 0; k < N.size(); k++) {
            double wubbs = M[k] * N[k];
            N[k] = wubbs;
            cout << N[k] << endl;
        }
    }
}
