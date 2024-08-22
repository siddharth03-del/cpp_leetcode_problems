#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
class Solution{
    public:
    int dp[100][100];
    string str;
    string r;
    string longestPalindrome(string s){
        cout << "hello" << endl;
        memset(dp, -1, sizeof(dp));
        r = "";
        str = s;
        int n = s.size();
        fun(0, n-1);
        return r;
    }
    bool fun(int i , int j){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i == j){
            dp[i][j] = 1;
            return true;
        }
        if(j - i == 1){
            if(str[i] == str[j]){
                dp[i][j] = 1;
                if(r.size() < 2){
                    r = str[i] + str[j];
                }
                return true;
            }
            else{
                dp[i][j] = 0;
                return false;
            }
        }  
        bool a = fun(i+1, j);
        bool b = fun(i + 1, j - 1);
        bool c = fun(i, j-1);
        if(str[i] == str[j]){
            if(b){
                string k = str.substr(i, j-i+1);
                if(k.size() > r.size()){
                    r = k;
                }
                dp[i][j] = 1;
                return true;
            }
            else{
                dp[i][j] = 0;
                return false;
            }
        }
        dp[i][j] = 0;
        return false;
    }
};
int main(){
    Solution s;
    cout << s.longestPalindrome("abccba") << endl;
    return 0;
}