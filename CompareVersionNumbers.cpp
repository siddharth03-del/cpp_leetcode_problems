#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
    public:
    int compareVersion(string version1 , string version2){
        vector<int> v1;
        vector<int> v2;
        int i = 0;
        string temp = "";
        while(i < version1.size()){
            cout << version1[i] << endl;
            if(version1[i] != '.'){
                temp += version1[i];
                i++;
            }
            else{
                cout << temp << endl;
                v1.push_back(stoi(temp));
                temp = "";
                i++;
            }
        }
        v1.push_back(stoi(temp));
        i = 0;
        temp = "";
        while(i < version2.size()){
            if(version2[i] != '.'){
                temp += version2[i];
                i++;
            }
            else{
                v2.push_back(stoi(temp));
                temp = "";
                i++;
            }
        }
        v2.push_back(stoi(temp));
        int newentry;
        if(v1.size() > v2.size()){
            newentry = v1.size() - v2.size();
            for(int j = 0; j < newentry; j++){
                v2.push_back(0);
            }
        }
        else if(v2.size() > v1.size()){
            newentry = v2.size() - v1.size();
            for(int j = 0; j < newentry; j++){
                v1.push_back(0);
            }
        }
        for(int i = 0; i < v1.size(); i++){
            if(v1[i] > v2[i]){
                return 1;
            }
            else if(v1[i] < v2[i]){
                return -1;
            }
        }
        return 0;
    }
};