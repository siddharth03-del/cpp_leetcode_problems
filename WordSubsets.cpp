#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int>allchars;
        vector<string>ans;
        for(int i = 0; i < words2.size(); i++){
            unordered_map<char, int>temp;
            for(int j = 0; j < words2[i].size(); j++){
                temp[words2[i][j]]++;
            }
            for(const auto& it : temp){
                allchars[it.first] = max(allchars[it.first], it.second);
            }
        }
        for(int i = 0 ; i < words1.size(); i++){
            unordered_map<char, int> temp;
            for(int j = 0; j < words1[i].size(); j++){
                temp[words1[i][j]]++;
            }
            bool flag = true;
            for(const auto& it : allchars){
                if(temp.find(it.first) == temp.end()){
                    flag = false;
                    break;
                }
                else{
                    if(allchars[it.first] > temp[it.first]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};