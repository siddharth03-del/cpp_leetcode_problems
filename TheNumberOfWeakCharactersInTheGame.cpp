#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
struct CustomComparator{
    bool operator()(vector<int> a, vector<int> b){
        return a[0] > b[0];
    }
};
class Solution{
    public:
    int numberOfWeakCharacters(vector<vector<int>>& properties){
        sort(properties.begin(), properties.end(), CustomComparator());
        int largest = properties[properties.size()-1][1];
        int prev = properties[properties.size()-1][0];
        int grouplarge = properties[properties.size()-1][1];
        int count = 0;
        for(int i = properties.size()-2; i >= 0; i--){
            if(properties[i][0] != prev){
                prev = properties[i][0];
                if(grouplarge > largest){
                    largest = grouplarge;
                }
                grouplarge = properties[i][1];
                if(properties[i][1] < largest){
                    count++;
                }
            }
            else{
                if(properties[i][1] < largest){
                    count++;
                }
                if(properties[i][1] > grouplarge){
                    grouplarge = properties[i][1];
                }
            }
        }
        return count;
    }
};