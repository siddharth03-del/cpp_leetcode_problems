#include <iostream>
#include <string>
using namespace std;
class Solution{
    public:
    string mergeAlternatively(string word1, string word2){
        int i = 0;
        int j = 0;
        bool flag1 = true;
        string res = "";
        while(i < word1.size() && j < word2.size()){
            if(flag1){
                res = res + word1[i];
                i++;
                flag1 = false;
            }
            else{
                res = res + word2[j];
                j++;
                flag1 = true;
            }
        }
        if(i == word1.size()){
            while(j < word2.size()){
                res = res + word1[j];
                j++;
            }
        }
        else if(j == word2.size()){
            while(i < word1.size()){
                res = res + word2[i];
                i++;
            }
        }
        return res;
    }
};