//
// Created by Ahmad Jorban on 08/12/2022.
//

#ifndef MAIN_CPP_FLOWER_H
#define MAIN_CPP_FLOWER_H
#include <vector>
#include <string>
using namespace std;
class Object {
private:
    string name;
    vector<float> data;
public:
    Object(string name, vector<float> measures): name(name), data(data){}
    const string &getName() const;
    const vector<float> &getData() const;
};


#endif //MAIN_CPP_FLOWER_H
