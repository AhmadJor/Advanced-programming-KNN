#include <iostream>
#include <fstream>
#include <vector>
#include "DistanceFunction.h"
#include "Euclidean.h"
#include "Manhatin.h"
#include "Chebyshev.h"
#include "Canberra.h"
#include "Minkowski.h"
#include "Object.h"
#include <map>
#include <string>

using namespace std;

vector<string> split(string str, char delim) {
    vector<string> arr;
    string temp = "";
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != delim)
            temp += str[i];
        else {
            arr.push_back(temp);
            temp = "";
        }
    }
    arr.push_back(temp);
    return arr;
}

Object convert(vector<string> arr) {
    vector<float> v1;
    for (int i = 0; i < arr.size() - 1; ++i) {
        v1.push_back(atof(arr[i].c_str()));
    }
    Object object = Object(arr[arr.size() - 1], v1);
    return object;
}

vector<Object> read(const string path) {
    vector<Object> result;
    fstream file;
    file.open(path, ios::in);
    if (!file) cout << "No such file";
    string line;
    while (getline(file, line)) {
        vector<string> splitted = split(line, ',');
        Object temp = convert(splitted);
        result.push_back(temp);
    }
    return result;
}

vector<float> getFloatVector() {
    vector<float> v1;
    string buffer;
    float data;
    //inputs line
    getline(cin, buffer);

    //splits line and inputs into vector
    vector<string> arr = split(buffer, ' ');
    for (int i = 0; i < arr.size(); ++i) {
        v1.push_back(atof(arr[i].c_str()));
    }
    return v1;
}


int main(int argc, char **argv) {
    int k = atoi(argv[1]);
    string file = argv[2];
    string distance = argv[3];
    DistanceFunction *function;
    if (distance.compare("AUC") == 0) {
        function = new Euclidean;
    } else if (distance.compare("MAN")) {
        function = new Manhatin;
    } else if (distance.compare("CHB")) {
        function = new Chebyshev;
    } else if (distance.compare("CAN")) {
        function = new Canberra;
    } else if (distance.compare("MIN")) {
        function = new Minkowski;
    } else {
        cout << "Distance Function does not exist" << endl;
        return 0;
    }
    vector<Object> result_classified = read("datasets/iris/" + file);
    map<float, string> distances;
    map<string, int> kth_elements;
    vector<float> get = getFloatVector();
    for (int i = 0; i < result_classified.size(); ++i) {
        float distance = function->Distance(result_classified[i].getData(), get);
        distances.insert(pair<float, string>(distance, result_classified[i].getName()));
    }

    for (int i = 0; i < k; ++i) {
        if (distances.count(distances.begin()->first) == 0)
            kth_elements[distances.begin()->second] = 1;
        else
            kth_elements[distances.begin()->second] += 1;
        distances.erase(distances.begin()->first);

    }
    pair<string, int> max = *kth_elements.begin();
    for (int i = 0; i < kth_elements.size(); ++i) {
        if (max.second < kth_elements.begin()->second)
            max = *kth_elements.begin();
    }
    cout << max.first << endl;

    return 0;
}