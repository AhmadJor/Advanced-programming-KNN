//
// Created by Ilan on 11/12/2022.
//

#ifndef ADVANCED_PROGRAMMING_HW1_CANBERRA_H
#define ADVANCED_PROGRAMMING_HW1_CANBERRA_H

#include <vector>
#include "DistanceFunction.h"

using namespace std;

//Canberra distance function class
class Canberra : public DistanceFunction {
public:
    virtual double Distance(vector<float> vector1, vector<float> vector2);
};


#endif //ADVANCED_PROGRAMMING_HW1_CANBERRA_H
