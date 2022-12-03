//
// Created by Ilan on 11/12/2022.
//

#ifndef ADVANCED_PROGRAMMING_HW1_MINKOWSKI_H
#define ADVANCED_PROGRAMMING_HW1_MINKOWSKI_H


#include "DistanceFunction.h"
#include <vector>

using namespace std;

//Minkowski distance function class
class Minkowski : public DistanceFunction {
public:
    virtual double Distance(vector<float> vector1, vector<float> vector2);
};


#endif //ADVANCED_PROGRAMMING_HW1_MINKOWSKI_H
