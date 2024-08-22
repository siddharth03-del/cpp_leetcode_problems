#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution{
    public:
    vector<string>str;
    vector<vector<vector<int>>> dp;
    int findMaxForm(vector<string>& strs, int m , int n){
        dp = std::vector<std::vector<std::vector<int>>>(102, std::vector<std::vector<int>>(102, std::vector<int>(603, -1)));
        str = strs;
        string s = strs[0];
        return f(m,n, 0);
    }
    int f(int m, int n, int index){
        if(dp[m][n][index] != -1){
            return dp[m][n][index];
        }
        if(index >= str.size()){
            return 0;
        }
        int a = 0;
        int b = 0;
        string s = str[index];
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                a++;
            }
            if(s[i] == '1'){
                b++;
            }
        }
        int f1 = 0;
        if(m >= a && n >= b){
            f1 = f(m - a, n - b, index + 1) + 1;
        }
        int f2 = f(m, n, index + 1);
        return dp[m][n][index] =  max(f1, f2);
    }
};
