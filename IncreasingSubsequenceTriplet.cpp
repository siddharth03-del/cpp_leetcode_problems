#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    bool increasingTriplet(vector<int>& nums){
        int i = -1;
        int j = -1;
        int k = -1;
        for(int iterator = 0; iterator < nums.size(); iterator++){
            if(i != -1){
                if(nums[iterator] > nums[i]){
                    if(j != -1){
                        if(nums[iterator] > nums[j]){
                            if(k != -1){
                                if(nums[iterator] > nums[k]){
                                    k = iterator;
                                }
                            }
                            else{
                                k = iterator;
                            }
                        }
                        else{
                            j = iterator;
                        }
                    }
                    else{
                        j = iterator;
                    }
                }
                else{
                    i = iterator;
                }
            }
            else{
                i = iterator;
            }
        }
        if(i != -1 && j != -1 && k != -1){
            return true;
        }
        else{
            return false;
        }
    }
};