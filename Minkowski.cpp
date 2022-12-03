//
// Created by Ilan on 11/12/2022.
//

#include <valarray>
#include "Minkowski.h"

//calculates Minkowski Distance of two vectors
double Minkowski::Distance(vector<float> vector1, vector<float> vector2) {
    int size = vector1.size();
    double sigma = 0;
    double diff = 0;
    int p = 2;
    for (int i = 0; i < size; i++) {
        diff = abs(vector1[i] - vector2[i]);
        sigma += pow(diff, p);
        diff = 0;
    }
    return pow(sigma, 1.0 / p);
}