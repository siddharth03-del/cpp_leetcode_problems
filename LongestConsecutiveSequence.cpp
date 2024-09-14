#include <vector>
#include <queue>
using namespace std;
class Solution{
    public:
    int longestConsecutive(vector<int>& nums){
        priority_queue<int>q;
        for(int i = 0; i < nums.size(); i++){
            q.push(nums[i]);
        }
        int a = q.top();
        int count = 1;
        q.pop();
        while(!q.empty()){
            if(q.top() == a+1){
                count++;
                q.pop();
                a++;
            }else{
                count = 1;
                q.pop();
            }
        }
        return count;
    }
};