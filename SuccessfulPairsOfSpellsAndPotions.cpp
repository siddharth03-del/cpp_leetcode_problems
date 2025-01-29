#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans(spells.size(), 0);
        for(int i = 0; i < spells.size(); i++){
            int left = 0;
            int right = spells.size()-1;
            int lowerbound = potions.size();
            while(left <= right){
                int mid = (left + right) / 2;
                if(spells[i]*potions[mid] >= success){
                    lowerbound = mid;
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            ans[i] = potions.size() - lowerbound;
        }
        return ans;
    }
};