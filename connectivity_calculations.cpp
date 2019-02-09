//
// Created by rwhit on 2/3/2019.
//

#include "connectivity_calculations.hpp"
#include <math.h>
#include <iomanip>
#include <sstream>

double P{0.85};
double Q{1 - P};

matrix &findImportance(matrix &mtx) {
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

matrix &assignRandomness(matrix &mtx) {
    double S, R;
    for (int i = 0; i < mtx.vect.size(); i++) {
        for (int j = 0; j < mtx.vect[i].size(); j++) {
            S = mtx.vect[i][j] * P;
            R = ((double) 1 / mtx.vect[i].size()) * Q;
            double newValue = S + R;
            mtx.vect[i][j] = newValue;
        }
    }
}

matrix &markovProcess(matrix &mtx) {
    matrix mtxRank(mtx.vect[0].size(), 1);
    for (int i = 0; i < mtx.vect[0].size(); i++) {
        mtxRank.vect[i][0] = (double) 1;
    }
    matrix mtxPrevRank;
    do {
        mtxPrevRank = mtxRank;
        mtxRank = mtx * mtxPrevRank;
    } while (mtxRank != mtxPrevRank);
    mtx = mtxRank;
    return mtx;
}

matrix &scaledRank(matrix &mtx) {
    double mtxSum = 0;
    for (int i = 0; i < mtx.vect.size(); i++) {
        for (int j = 0; j < mtx.vect[0].size(); j++) {
            mtxSum += mtx.vect[i][j];
        }
    }
    for (int i = 0; i < mtx.vect.size(); i++) {
        for (int j = 0; j < mtx.vect[0].size(); j++) {
            mtx.vect[i][j] /= mtxSum;
        }
    }
    return mtx;
}
