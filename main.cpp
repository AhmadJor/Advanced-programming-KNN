#include <iostream>
#include <fstream>
#include <vector>
#include "DistanceFunction.h"
#include "Euclidean.h"
#include "Manhatin.h"
#include "Chebyshev.h"
#include "Canberra.h"
#include "Minkowski.h"

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
vector<float> convert(vector<string> arr){
    vector<float> v1;
    for (int i = 0; i < arr.size(); ++i) {
        v1.push_back(atof(arr[i].c_str()));
    }
    return v1;
}

vector<vector<float>> read(const string path){
    vector<vector<float>> result;
    fstream  file;
    file.open(path,ios:: in);
    if (!file) cout << "No such file";
    string line;
    while (getline(file,line)){
       vector<float> temp = convert(split(line,','));
        result.push_back(temp);
    }
    return result;
}

int main(int argc , char** argv){
int k = atoi(argv[1]);
string file = argv[2];
string distance = argv[3];
DistanceFunction* function;
    if (distance.compare("AUC")==0){
        function = new Euclidean;
    } else if (distance.compare("MAN")){
        function = new Manhatin;
    } else if (distance.compare("CHB")){
        function = new Chebyshev;
    } else if (distance.compare("CAN")){
        function = new Canberra;
    } else if (distance.compare("MIN")){
        function = new Minkowski;
    } else {
        cout << "Distance Function does not exist"<<endl;
        return 0;
    }
    vector<vector<float>> result = read("/datasets/" + file);


    return 0;
}