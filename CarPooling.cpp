#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    bool carPooling(vector<vector<int>>& trips, int capacity){
        vector<vector<int>>from(1003, vector<int>());
        vector<vector<int>>to(1003, vector<int>());
        for(int i = 0; i < trips.size(); i++){
            from[trips[i][1]].push_back(trips[i][0]);
            to[trips[i][2]].push_back(trips[i][0]);
        }
        int current = 0;
        for(int i = 0; i <= 1000; i++){
            for(int j = 0; j < to[i].size(); j++){
                current -= to[i][j];
            }
            for(int j = 0; j < from[i].size(); j++){
                if(current + from[i][j] > capacity){
                    return false;
                }
                else{
                    current += from[i][j];
                }
            }
        }
        return true;
    }
};