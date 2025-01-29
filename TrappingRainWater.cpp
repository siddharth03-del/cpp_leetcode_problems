#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    int trap(vector<int>& height){
        int left = 0;
        int right = height.size()-1;
        int leftmax = height[0];
        int rightmax = height[height.size()-1];
        int water = 0;
        while(left < right){
            if(leftmax < rightmax){
                left++;
                leftmax = max(leftmax, height[left]);
                water+= leftmax - height[left];
            }
            else{
                right--;
                rightmax = max(rightmax, height[right]);
                water+= rightmax - height[right];
            }
        }
        return water;
    }
};