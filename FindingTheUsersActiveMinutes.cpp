#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_map<int, int>>users;
        int max = 0;
        for(int i = 0; i < logs.size(); i++){
            users[logs[i][0]][logs[i][1]] = 1;
        }
        vector<int> answers(k, 0);
        for(const auto& it : users){
            int total = 0;
            for(const auto& min : it.second){
                total++;
            }
            answers[total-1]++;
        }
    }
};