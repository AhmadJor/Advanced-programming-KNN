//
// Created by Ahmad Jorban on 10/11/2022.
//

#ifndef UNTITLED8_EUCLIDEAN_H
#define UNTITLED8_EUCLIDEAN_H

#include <vector>
#include "DistanceFunction.h"

using namespace std;

//Euclidean distance function class
class Euclidean : public DistanceFunction {
public:
    virtual double Distance(vector<float> vector1, vector<float> vector2);
};


#endif //UNTITLED8_EUCLIDEAN_H
