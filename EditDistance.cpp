#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution{
    public:
    vector<vector<int>> dp;
    string target;
    string curr;
    int minDistance(string word1, string word2){
        dp.resize(503, vector<int>(502, -1));
        curr = word1;
        target = word2;
        return f(0,0);
    }
    int f(int i, int j){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i == curr.size() && j == target.size()){
            return 0;
        }
        if(i >= curr.size()){
            return target.size() - j;
        }
        if(j >= target.size()){
            return curr.size() - i;
        }
        if(curr[i] == target[j]){
            return f(i+1, j + 1);
        }
        int a = f(i+1, j+1) + 1; // replace;
        int b = f(i+1, j) + 1 ;// delete;
        int c = f(i, j+1) + 1; // insert;
        return dp[i][j] = min(a, min(b,c));
    }
};