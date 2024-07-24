#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
class Solution{
    public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights){
        unordered_map<int, string>order;
        for(int i = 0; i < names.size(); i++){
            order[heights[i]] = names[i];
        }
        sort(heights.begin(), heights.end(), greater<int>());
        vector<string> res;
        for(int i = 0; i < heights.size(); i++){
            res.push_back(order[heights[i]]);
        }
        return res;
    }
};