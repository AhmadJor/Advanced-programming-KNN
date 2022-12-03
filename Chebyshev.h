//
// Created by Ilan on 11/12/2022.
//

#ifndef ADVANCED_PROGRAMMING_HW1_CHEBYSHEV_H
#define ADVANCED_PROGRAMMING_HW1_CHEBYSHEV_H
using namespace std;
#include <vector>
#include "DistanceFunction.h"

//Chebyshev distance function class
class Chebyshev : public DistanceFunction {
public:
    virtual double Distance(vector<float> vector1, vector<float> vector2);
   
};


#endif //ADVANCED_PROGRAMMING_HW1_CHEBYSHEV_H
