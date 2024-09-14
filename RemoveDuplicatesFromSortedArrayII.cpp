#include <iostream>
#include <vector>
using namespace std;
class Solution{
    int removeDuplicates(vector<int>& nums){
        int i = 1;
        int j = 1;
        int prev = nums[0];
        int counter = 1;
        while( j < nums.size()){
            if(nums[j] == prev){
                if(counter >= 2){
                    j++;
                }
                else{
                    counter++;
                    if(i != j){
                        nums[i] = nums[j];
                    }
                    i++;
                    j++;
                }
            }
            else if(nums[j] != prev){
                prev = nums[j];
                counter = 1;
                if(i != j){
                    nums[i] = nums[j];
                    i++;
                    j++;
                }
                else{
                    i++;
                    j++;
                }
            }
        }
        return i + 1;
    }
};