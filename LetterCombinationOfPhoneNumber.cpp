#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution{
    public:
    string digit;
    vector<string> ans;
    unordered_map<int, vector<char>>map;
    vector<string> letterCombinations(string digits){
        digit = digits;
        map[2] = {'a','b','c'};
        map[3] = {'d','e','f'};
        map[4] = {'g','h','i'};
        map[5] = {'j','k','l'};
        map[6] = {'m','n','o'};
        map[7] = {'p','q','r','s'};
        map[8] = {'t','u','v'};
        map[9] = {'w','x','y','z'};
        f("",0);
        return ans;
    }
    void f(string curr, int index){
        if(index >= digit.size()){
            ans.push_back(curr);
            return;
        }
        int digi = int(digit[index]);
        string str = curr;
        for(int i = 0; i < map[digi].size(); i++){
            f(str+map[digi][i], index + 1);
        }
        return;
    }
};