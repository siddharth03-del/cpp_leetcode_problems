#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    int equalPairs(vector<vector<int>>& grids){
        int out = 0;
        int n = grids.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                bool ans = compare(grids, i, j, n);
                if(ans){
                    out++;
                }
            }
        }
        return out;
    }
    bool compare(vector<vector<int>>& grids, int row, int col, int n){
        for(int i = 0; i < n; i++){
            if(grids[row][i] != grids[i][col]){
                return false;
            }
        }
        return true;
    }
};