//
// Created by Ilan on 11/12/2022.
//


#include <valarray>
#include "Canberra.h"

//calculates Canberra Distance of two vectors
double Canberra::Distance(vector<float> vector1, vector<float> vector2) {
    int size = vector1.size();
    double result = 0;
    double diff = 0;
    for (int i = 0; i < size; i++) {
        diff = abs(vector1[i] - vector2[i]);
        result += diff / (abs(vector1[i]) + abs(vector2[i]));
        diff = 0;
    }
    return result;
}