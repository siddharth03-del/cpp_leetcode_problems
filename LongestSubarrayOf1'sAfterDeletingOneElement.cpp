#include <vector>
#include <iostream>
using namespace std;
class Solution{
    public:
    int longestSubarray(vector<int>& nums){
        int i = 0;
        int j = 0;
        int count = 0;
        int max = 0;
        while(j < nums.size()){
            if(nums[j] == 0){
                if(count == 1){
                    if(j - i - 1 > max){
                        max = j - i - 1;
                    }
                    while(nums[i] != 0){
                        i++;
                    }
                    i++;
                    j++;
                }
                else{
                    count++;
                    if(j - i > max){
                        max = j - i;
                    }
                    j++;
                }
            }
            else{
                if(j - i > max){
                    max = j - i;
                }
                j++;
            }
        }
        return max;
    }
};