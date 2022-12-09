//
// Created by Ahmad Jorban on 08/12/2022.
//

#ifndef MAIN_CPP_FLOWER_H
#define MAIN_CPP_FLOWER_H
#include <vector>
#include <string>
using namespace std;
class Flower {
private:
    string name;
    vector<float> measures;
public:
    Flower(string name, vector<float> measures):name(name),measures(measures){}
    const string &getName() const;
    const vector<float> &getMeasures() const;
};


#endif //MAIN_CPP_FLOWER_H
