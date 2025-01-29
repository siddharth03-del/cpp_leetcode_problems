#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<vector<string>>> account;
        for(int i = 0; i < accounts.size(); i++){
            vector<string> details = accounts[i];
            string name = details[0];
            if(account.find(name) == account.end()){
                vector<string> temp;
                for(int j = 1; j < accounts.size(); j++){
                    temp.push_back(details[j]);
                }
                account[name].push_back(temp);
                continue;
            }
            for(int j = 1; j < details.size(); j++){
                string email = details[j];
                vector<vector<string>> a = account[name];
                for(int k = 0; k < a.size(); k++){
                    for(int l = 0; l < a[k].size(); l++){
                        if(a[k][l] == email){
                            for(int it = 1; it < details.size(); it++){
                                a[k].push_back(details[it]);
                            }
                        }
                    }
                }
                vector<string> temp;
                for(int it = 1; it < details.size(); it++){
                    temp.push_back(details[it]);
                }
                account[name].push_back(temp);
            }
        }
        vector<vector<string>> ans;
        for(const auto& it : account){
            for(int i = 0; i < it.second.size(); i++){
                sort(it.second[i].begin(), it.second[i].end());
                ((it.second)[i]).insert(it.second[i].begin(), it.first);
                ans.push_back(it.second[i]);
            }
        }
        return ans;
    }
};