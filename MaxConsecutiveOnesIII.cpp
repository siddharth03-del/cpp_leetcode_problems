#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    int longestOnes(vector<int>& nums, int k){
        int left = 0;
        int right = 0;
        int length = 0;
        int zeros = 0;
        int maxlength = 0;
        while(right < nums.size()){
            if(nums[right] == 0){
                if(zeros < k){
                    zeros++;
                    right++;
                    length++;
                    if(maxlength < length){
                        maxlength = length;
                    }
                }
                else{
                    while(nums[left] != 0){
                        length--;
                        left++;
                    }
                    left++;
                    length--;
                    zeros--;
                    right++;
                }
            }
            else{
                length++;
                right++;
                if(maxlength < length){
                    maxlength = length;
                }
            }
        }
        return maxlength;
    }
};