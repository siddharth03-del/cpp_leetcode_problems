#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        f("", 0, s, 0);
        return ans;
    }
    void f(string temp, int index, string s, int dots){
        if(index >= s.size() && dots == 4){
            ans.push_back(temp);
            return;
        }
        if(index >= s.size()){
            return;
        }
        if(dots > 4){
            return;
        }
        string a = "";
        if(s[index] == '0'){
            a = "0";
            if(dots < 3){
                a += ".";
            }
            f(temp + a, index + 1, s, dots+1);
            return;
        }
        for(int i = index; i < s.size(); i++){
            a += s[i];
            if(isValid(a)){
                string n = a;
                if(dots < 3){
                    n += ".";
                }
                f(temp + n, i+1 , s, dots + 1);
            }
            else{
                break;
            }
        }
        return;
    }
    bool isValid(string s){
        int n = stoi(s);
        if(n >= 0 && n <= 255){
            return true;
        }
        else{
            return false;
        }
    }
};