#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution{
    public:
    vector<string> getFolderNames(vector<string>& names){
        unordered_map<string , int>map;
        vector<string> ans;
        for(int i = 0 ; i < names.size() ; i++){
            string s = names[i];
            if(!map[s]){
                map[s] = 1;
                ans.push_back(s);
            }
            else{
                int count = map[s];
                string temp = s + "(" + to_string(map[s]) + ")";
                while(map[temp]){
                    map[s]++;
                    temp = s + "(" + to_string(map[s]) + ")";
                }
                map[temp] = 1;
                ans.push_back(temp);
            }
        }
        return ans;
    }
};