#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void trimTrailingSpaces(std::string &str) { 
        // Find the last non-space character 
        std::size_t end = str.find_last_not_of(' '); 
        if (end != std::string::npos) { 
        // Erase all trailing spaces
         str.erase(end + 1);
          } else {
        // String is all 
        str.clear(); 
        } }
    vector<string> printVertically(string s) {
        string temp = "";
        vector<string> words;
        int max = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                words.push_back(temp);
                if(temp.size() > max){
                    max = temp.size();
                }
            }else{
                temp += s[i];
            }
        }
        words.push_back(temp);
        if(temp.size() > max){
            max = temp.size();
        }
        cout << max << endl;
        vector<vector<string>>helper(words.size(), vector<string>(max, " "));
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].size(); j++){
                helper[i][j] = words[i][j];
            }
        }
        string t = "";
        vector<string> ans;
        for(int i = 0; i < max; i++){
            t = "";
            for(int j = 0; j < helper.size(); j++){
                t += helper[j][i];
            }
            trimTrailingSpaces(t);
            ans.push_back(t);
        }
        return ans;
    }
};