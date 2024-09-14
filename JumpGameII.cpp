#include <vector>
using namespace std;
class Solution{
    public:
    int jump(vector<int>& nums){
        int maxJump = nums[0];
        int step = 0;
        int lastJump = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(i == lastJump){
                step++;
                if(i + nums[i] > maxJump){
                    maxJump = i + nums[i];
                }
                lastJump = maxJump;
            }
            else{
                if(i + nums[i] > maxJump){
                    maxJump = i + nums[i];
                }
            }
        }
        return step;
    }
};