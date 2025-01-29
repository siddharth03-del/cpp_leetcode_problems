#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    string arrangeWords(string text) {
        map<int , vector<string>>mp;
        string word = "";
        int size = 0;
        text[0] = tolower(text[0]);
        for(int i = 0; i < text.size();  i++){
            if(text[i] != ' '){
                word += text[i];
                size++;
            }
            else{
                mp[size].push_back(word);
                word = "";
                size = 0;
            }
        }
        mp[size].push_back(word);
        string res = "";
        for(const auto& it : mp){
            for(int i = 0; i < it.second.size(); i++){
                res += it.second[i];
                res += " ";
            }
        }
        int c = res[0];
        if( c >= 65 && c <= 95){
            
        }
        else{
            res[0] = toupper(res[0]);
        }
        res.erase(res.size()-1);
        return res;
    }
};