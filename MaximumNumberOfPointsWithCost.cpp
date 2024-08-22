#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
    public:
    vector<vector<int>> point;
    vector<vector<long long>> dp;
    long long maxPoints(vector<vector<int>>& points){
        int row = points.size();
        int col = points[0].size();
        dp.resize(row,vector<long long>(col,-1));
        point = points;
        long long greatest = 0;
        for(int i = 0; i < points[0].size(); i++){
            long long a = f(0, i);
            if(a > greatest){
                greatest = a;
            }
        }
        return greatest;
    }
    long long f(int i, int j){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i == point.size() - 1){
            return point[i][j];
        }
        int row;
        int col;
        long long greatest = 0;
        long long ans = point[i][j];
        for(int k = 0; k < point[0].size(); k++){
            long long val = f(i+1, k);
            if(val > greatest){
                greatest = val;
                row = i + 1;
                col = k;
            }
        }
        dp[i][j] = greatest - abs(j - col);
        return greatest - abs(j - col);
    }
};