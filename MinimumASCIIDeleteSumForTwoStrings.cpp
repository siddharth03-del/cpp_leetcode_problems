#include <string>
#include <iostream>
using namespace std;
class Solution{
    public:
    string str1;
    string str2;
    int minimumDeleteSum(string s1, string s2){
        str1 = s1;
        str2 = s2;
        return f(0,0);
    }
    int f(int i, int j){
        if(i >= str1.length() && j >= str2.length()){
            return 0;
        }
        if(i >= str1.length()){
            return f(i , j+1) + int(str2[j]);
        }
        if(j >= str2.length()){
            return f(i + 1, j) + int(str1[i]);
        }
        if(str1[i] == str2[j] ){
            return f(i + 1, j + 1);
        }
        int a = f(i + 1, j) + int(str1[i]);
        int b = f(i, j + 1) + int(str2[j]);
        return min(a, b);
    }
};