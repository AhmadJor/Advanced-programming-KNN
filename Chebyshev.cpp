//
// Created by Ilan on 11/12/2022.
//

#include <valarray>
#include "Chebyshev.h"

//calculates Chebyshev Distance of two vectors
double Chebyshev::Distance(vector<float> vector1, vector<float> vector2) {
    int size = vector1.size();
    vector<double> vector;
    for (int i = 0; i < size; i++)
        vector.push_back(abs(vector1[i] - vector2[i]));
    return *max_element(vector.begin(), vector.end());
}