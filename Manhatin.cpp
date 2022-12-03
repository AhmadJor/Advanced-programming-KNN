//
// Created by Ahmad Jorban on 10/11/2022.
//
#include <vector>
#include <valarray>
#include "Manhatin.h"

//calculates Manhatin Distance of two vectors
double Manhatin::Distance(vector<float> vector1, vector<float> vector2) {
    int size = vector1.size();
    double diff = 0;
    double sum = 0;
    for (int i = 0; i < size; i++) {
        diff = vector1[i] - vector2[i];
        sum += abs(diff);
        diff = 0;
    }
    return sum;
}