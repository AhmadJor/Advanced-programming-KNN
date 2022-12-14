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
    if (!file) {
        cout << "No such file" << endl;
        exit(1);
    }

    int lineSize = -1;
    string line;
    while (getline(file, line)) {
        vector<string> splitted = split(line, ',');
        if (lineSize == -1)
            lineSize = splitted.size();
        else {
            if (splitted.size() != lineSize){
                cout << "Error reading file" << endl;
                exit(1);
            }
        }
        Object temp = convert(splitted);
        result.push_back(temp);
    }
    return result;
}

vector<float> getFloatVector(istream &inputStream) {
    vector<float> v1;
    string buffer;
    float data;
    //inputs line
    getline(inputStream, buffer);

    //splits line and inputs into vector
    vector<string> arr = split(buffer, ' ');
    for (int i = 0; i < arr.size(); ++i) {
        v1.push_back(atof(arr[i].c_str()));
    }
    return v1;
}

DistanceFunction *GetDistanceFunction(string distanceInput) {
    DistanceFunction *function;
    if (distanceInput.compare("AUC") == 0) {
        function = new Euclidean;
    } else if (distanceInput.compare("MAN") == 0) {
        function = new Manhatin;
    } else if (distanceInput.compare("CHB") == 0) {
        function = new Chebyshev;
    } else if (distanceInput.compare("CAN") == 0) {
        function = new Canberra;
    } else if (distanceInput.compare("MIN") == 0) {
        function = new Minkowski;
    } else {
        cout << "Distance Function does not exist" << endl;
        exit(0);
    }
    return function;
}

map<float, string>
CalculateDistances(DistanceFunction *distanceFunction, vector<Object> classified, vector<float> inputVector) {
    map<float, string> distances;
    for (int i = 0; i < classified.size(); ++i) {
        float distance = distanceFunction->Distance(classified[i].getData(), inputVector);
        distances.insert(pair<float, string>(distance, classified[i].getName()));
    }
    return distances;
}

map<string, int> CountKClosestObjects(int k, map<float, string> distances) {
    //count closest k names according to their names
    map<string, int> kth_elements;
    //run over k closest objects
    for (int i = 0; i < k; ++i) {
        //if first occurrence
        if (kth_elements.count(distances.begin()->second) == 0)
            kth_elements[distances.begin()->second] = 1;
        else
            kth_elements[distances.begin()->second]++;
        //erase the lowest distance
        distances.erase(distances.begin()->first);
    }
    return kth_elements;
}

//returns maximum occurred name in closestK (map<string, int> = <name, numOccurrences>)
string GetMaximumOccurrences(map<string, int> closestK) {
    pair<string, int> max = *closestK.begin();
    closestK.erase(closestK.begin()->first);
    for (int i = 0; i < closestK.size(); ++i) {
        if (max.second < closestK.begin()->second)
            max = *closestK.begin();
        closestK.erase(closestK.begin()->first);
    }
    return max.first;
}

int main(int argc, char **argv) {
    int k = atoi(argv[1]);
    if (k == 0) {
        cout << "Error in K input" << endl;
        return 0;
    }

    string file = argv[2];
    string distance = argv[3];
    vector<Object> classified = read(file);
    //check if read empty:
    if (classified.empty()) {
        cout << "File is either empty, or there was an error reading it." << endl;
        return 0;
    }

    DistanceFunction *distanceFunction = GetDistanceFunction(distance);
    while (true) {
        vector<float> inputVector = getFloatVector(cin);
        //check if vector of correct size
        if (inputVector.size() != classified[0].getData().size()) {
            cout << "Vector of incorrect size" << endl;
            continue;
        }

        map<float, string> distances = CalculateDistances(distanceFunction, classified, inputVector);
        map<string, int> closestK = CountKClosestObjects(k, distances);
        string name = GetMaximumOccurrences(closestK);

        cout << name << endl;
    }

    delete distanceFunction;
    return 0;
}