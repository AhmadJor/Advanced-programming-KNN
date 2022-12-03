//
// Created by Ahmad Jorban on 10/11/2022.
//

#ifndef UNTITLED8_MANHATIN_H
#define UNTITLED8_MANHATIN_H

#include "DistanceFunction.h"
#include <vector>

using namespace std;

//Manhatin distance function class
class Manhatin : public DistanceFunction {
public:
    virtual double Distance(vector<float> vector1, vector<float> vector2);
};


#endif //UNTITLED8_MANHATIN_H
