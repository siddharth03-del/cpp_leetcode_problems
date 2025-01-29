#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution{
    public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime){
        unordered_map<string, vector<int>>map;
        unordered_map<string, bool>ans;
        for(int i = 0; i < keyName.size(); i++){
            if(ans[keyName[i]]){
                continue;
            }
            string h = "";
            h += keyTime[i][0];
            h += keyTime[i][1];
            string m = "";
            m += keyTime[i][3];
            m += keyTime[i][4];
            int hours = stoi(h);
            int minutes = stoi(m);
            map[keyName[i]].push_back(hours * 60 + minutes);
            if(map[keyName[i]].size() > 2){
                int n = map[keyName[i]].size();
                int a = map[keyName[i]][n-3];
                int b = map[keyName[i]][n-2];
                int c = map[keyName[i]][n-1];
                if(b - a <= 60 && c - b <= 60){
                    ans[keyName[i]] = true;
                }
            }
        }
        vector<string>res;
        for(const auto& it : map){
            res.push_back(it.first);
        }
        sort(res.begin(), res.end());
        return res;
    }
};