#include <string>
#include <vector>
using namespace std;
class Solution{
    public:
    vector<vector<int>> dp;
    int longestCommonSubsequence(string text1, string text2){
        dp.resize(1005, vector<int>(1005, -1));
        return f(text1, text2, 0, 0);
    }
    int f(string str1, string str2, int i, int j){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i >= str1.size()){
            return 0;
        }
        if(j >= str2.size()){
            return 0;
        }
        if(str1[i] == str2[j]){
            return 1 + f(str1, str2, i + 1, j + 1);
        }
        int a = f(str1, str2, i + 1, j);
        int b = f(str1, str2, i, j+1);
        return dp[i][j] = max(a, b);
    }
};