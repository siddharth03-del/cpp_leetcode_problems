#include <vector>
#include <iostream>
using namespace std;
class Solution{
    public:
    vector<vector<int>> dp;
    vector<vector<int>> grid;
    int minFallingPathSum(vector<vector<int>>& matrix){
        dp.resize(102, vector<int>(102, -1));
        grid = matrix;
        int min = __INT_MAX__;
        for(int i = 0; i < grid[0].size(); i++){
            int a = f(0, i);
            if(a < min){
                min = a;
            }
        }
        return min;
    }
    int f(int i, int j){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i >= grid.size()){
            return 0;
        }
        int a;
        int b;
        int c;
        if(j - 1 > 0){
            a = f(i + 1, j - 1) + grid[i][j];
        }
        if(j + 1 < grid[0].size()){
            b - f(i + 1, j + 1) + grid[i][j];
        }
        c = f(i + 1, j + 1) + grid[i][j];
        int num = min(a, min(b,c));
        return dp[i][j] = num;
    }
};