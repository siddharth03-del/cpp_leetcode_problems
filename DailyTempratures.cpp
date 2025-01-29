#include <stack>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<vector<int>>s;
        vector<int>ans(temperatures.size());
        for(int i = temperatures.size()-1; i >= 0; i--){
            if(s.empty()){
                s.push({i, temperatures[i]});
                continue;
            }
            else{
                while(!s.empty() && s.top()[1] <= temperatures[i]){
                    s.pop();
                }
                if(s.empty()){
                    s.push({i, temperatures[i]});
                }
                else{
                    ans[i] = s.top()[0] - i;
                    s.push({i, temperatures[i]});
                }
            }
        }
        return ans;
    }
};
