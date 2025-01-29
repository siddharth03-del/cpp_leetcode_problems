#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int longest = 0;
        vector<int> temp;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                temp.push_back(nums[i]);
            }
            else{
                int r = positive(temp);
                if(r > longest){
                    longest = r;
                }
                temp.clear();
            }
        }
        int r = positive(temp);
        if(r > longest){
            longest = r;
        }
        return longest;
    }
    int positive(vector<int>& nums){
        int negative = 0;
        int first = -1;
        int last = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                negative++;
                if(first == -1){
                    first = i;
                }
                last = i;
            }
        }
        if(negative % 2 != 0){
            int a = nums.size() - first - 1;
            int b = nums.size() - (nums.size() - last);
            if(a > b){
                return a;
            }
            else{
                return b;
            }
        }
        else{
            return nums.size();
        }
    }
};