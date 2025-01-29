#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution{
    public:
    string licenseKeyFormatting(string s, int k){
        int total = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '-') total++;
        }
        int groups = total / k;
        int first = total%k;
        string res = "";
        int j = k;
        bool flag = false;
        if(first == 0){
            flag = true;
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '-'){
                continue;
            }
            if(first){
                res += toupper(s[i]);
                first--;
            }
            else if(j && flag){
                res += toupper(s[i]);
                j--;
            }
            else{
                res += '-';
                j = k;
                flag = true;
                if(s[i] != '-'){
                    i--;
                }
            }
        }
        return res;
    }
};