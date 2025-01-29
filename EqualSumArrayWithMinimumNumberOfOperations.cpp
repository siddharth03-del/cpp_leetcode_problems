#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < nums1.size(); i++){
            sum1 += nums1[i];
        }
        for(int i = 0; i < nums2.size(); i++){
            sum2 += nums2[i];
        }
        if(sum1 == sum2){
            return 0;
        }
        int min1 = nums1.size();
        int max2 = nums1.size()*6;
        int min2 = nums2.size();
        int max2 = nums2.size()*6;
        if(min1 > )
    }
    int decrement(){

    }
    int increment(){

    }
};