#include <iostream>
#include <string>
using namespace std;
class Solution{
    public:
    string str;
    int longestPallindromeSubseq(string s){
        str = s;
        return f(0, s.size() - 1);
    }
    int f(int i , int j){
        if(i == j){
            return 1;
        }
        if(j - i == 1){
            if(str[i] == str[j]){
                return 2;
            }
            else{
                return 1;
            }
        }
        int a = f(i + 1, j);
        int b = f(i + 1, j - 1);
        int c = f(i, j - 1);
        if(str[i] == str[j]){
            return 2 + max(a,b,c);
        }
        return max(a,b,c);
    }
};