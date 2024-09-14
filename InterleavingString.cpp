#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution{
    public:
    vector<vector<vector<int>>>dp;
    bool isInterleave(string s1, string s2, string s3){
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }
        dp.resize(203, vector<vector<int>>(104, vector<int>(104, -1)));
        return checker(0, 0, 0, s1, s2, s3);
    }
    bool checker(int i, int m , int n, string s1, string s2, string s3){
        if(dp[i][m][n] != -1){
            return dp[i][m][n];
        }
        if(i >= s3.size()){
            return true;
        }
        bool r1 = false;
        bool r2 = false;
        if(s3[i] == s1[m]){
            r1 = checker(i + 1, m + 1, n, s1, s2, s3);
        }
        if(s3[i] == s2[n]){
            r2 = checker(i + 1, m, n + 1, s1, s2, s3);
        }
        if(r1 || r2){
            return dp[i][m][n] = true;
        }
        else{
            return dp[i][m][n] = false;
        }
        return false;
    }
};
int main(){
    Solution s;
    cout << s.isInterleave("abbbbbbcabbacaacccababaabcccabcacbcaabbbacccaaaaaababbbacbb","ccaacabbacaccacababbbbabbcacccacccccaabaababacbbacabbbbabc","cacbabbacbbbabcbaacbbaccacaacaacccabababbbababcccbabcabbaccabcccacccaabbcbcaccccaaaaabaaaaababbbbacbbabacbbacabbbbabc")<<endl;
    return 0;
}