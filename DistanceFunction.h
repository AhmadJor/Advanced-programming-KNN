//
// Created by Ilan on 11/11/2022.
//

#ifndef ADVANCED_PROGRAMMING_HW1_DISTANCEFUNCTION_H
#define ADVANCED_PROGRAMMING_HW1_DISTANCEFUNCTION_H


#include <vector>

using namespace std;

//virtual distance function class, base class for distance function implementations
class DistanceFunction {
public:
    virtual double Distance(vector<float> vector1, vector<float> vector2) = 0;
};


#endif //ADVANCED_PROGRAMMING_HW1_DISTANCEFUNCTION_H
