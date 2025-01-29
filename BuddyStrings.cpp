#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    bool buddyStrings(string s, string goal){
        if(s.size() < 2 || s.size() != goal.size()){
            return false;
        }
        bool first = true;
        bool comp = false;
        char gfst;
        char sfst;
        vector<int> ch(26, 0);
        for(int i = 0; i < s.size(); i++){
            ch[s[i] - 'a']++;
            if(s[i] != goal[i]){
                if(comp){
                    return false;
                }
                if(first){
                    gfst = goal[i];
                    sfst = s[i];
                    first = false;
                }
                else{
                    if(s[i] == gfst && goal[i] == sfst){
                        comp = true;
                        continue;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        if(first && !comp){
            return false;
        }
        else if(!first && !comp){
            for(int i = 0; i < ch.size(); i++){
                if(ch[i] > 1){
                    return true;
                }
            }
        }
        return false;
    }
};