#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
class Solution{
    public:
    unordered_map<string, bool> word;
    string str;
    vector<int> dp(305, -1);
    bool wordBreak(string s, vector<string>& wordDict){
        
        for(int i = 0 ; i < wordDict.size(); i++){
            word[wordDict[i]] = true;
        }
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            temp = temp + s[i];
            bool a;
            if(word[temp]){
                a = fun(i + 1);
            }
            if(a){
                return true;
            }
        }
        return false;
    }
    bool fun(int i){
        if( i >= str.size()){
            return true;
        }
        string temp = "";
        for(i; i < str.size(); i++){
            temp = temp + str[i];
            bool a;
            if(word[temp]){
                a = fun(i + 1);
            }
            if(a){
                return true;
            }
        }
        return false;
    }
};