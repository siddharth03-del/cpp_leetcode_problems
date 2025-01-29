#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int numDifferentIntegers(string word) {
        string num = "";
        unordered_map<string, bool> map;
        for(int i = 0; i < word.size(); i++){
            char c = word[i] - '0'; 
            if(c >= 0 && c <= 9 ){
                num += word[i];
            }
            else{
                if(num != ""){
                    int j = 0; 
                    while(num[j] == '0' && j < num.size()-1){
                        num.erase(j, 1);
                    }
                    map[num] = true;
                    num = "";
                }
                else{
                    continue;
                }
            }
        }
        if(num != ""){
            int j = 0; 
            while(num[j] == '0' && j < num.size()-1){
                num.erase(j, 1);
            }
            map[num] = true;
            num = "";
        }
        int count = 0;
        for(const auto& it: map){
            if(it.second == true){
                count++;
            }
        }
        return count;
    }
};