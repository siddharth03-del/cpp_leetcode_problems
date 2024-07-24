#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution{
    public:
vector<int> frequencySort(vector<int>& nums){
    unordered_map<int, int> m;
    for(int i = 0; i < nums.size(); i++){
        if(m[nums[i]]){
            m[nums[i]]++;
        }
        else{
            m[nums[i]] = 1;
        }
    }
    vector<int> res;
    vector<vector<int>> frequency(102, vector<int>());
    for (auto it = m.begin(); it != m.end(); ++it) {
        int element = it->first;
        int freq = it->second;
        frequency[freq].push_back(element);
    }
    for(int i = 0; i < frequency.size(); i++){
        if(frequency[i].size() == 1){
            int count = i;
            while(count > 0){
                res.push_back(frequency[i][0]);
                count--;
            }
        }
        else if(frequency[i].size() > 1){
            sort(frequency[i].begin(), frequency[i].end(),greater<int>());
            for(int j = 0; j < frequency[i].size(); j++){
                int count = i;
                while(count > 0){
                    res.push_back(frequency[i][j]);
                    count--;
                }
            }
        }
    }
    return res;
}
};