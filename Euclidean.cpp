//
// Created by Ahmad Jorban on 10/11/2022.
//

#include "Euclidean.h"
#include <iostream>
#include <valarray>

//calculates Euclidean Distance of two vectors
double Euclidean::Distance(vector<float> vector1, vector<float> vector2) {
    int size = vector1.size();
    double sum = 0;
    double diff = 0;
    for (int i = 0; i < size; i++) {
        diff = vector1[i] - vector2[i];
        sum += (diff * diff);
        diff = 0;
    }
    return sqrt(sum);
}