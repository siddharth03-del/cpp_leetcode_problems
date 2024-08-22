#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    vector<int> dp;
    vector<int> num;
    vector<int> countseq;
    int findNumberOfLIS(vector<int>& nums){
        num = nums;
        for(int i = 0; i < nums.size(); i++){
            dp.push_back(1);
            countseq.push_back(1);
        }
        for(int i = 1; i < nums.size(); i++){
            f(i);
        }
        int count = 0;
        int max = 1;
        for(int i = 0; i < dp.size(); i++){
            if(dp[i] > max){
                max = dp[i];
                count = countseq[i];
            }
            else if(dp[i] == max){
                count += countseq[i];
            }
        }
        return count;
    }
    void f(int index){
        int greatest = 1;
        int count = 1;
        for(int i = index - 1; i >= 0 ; i--){
            if(num[index] > num[i]){
                if(dp[i] + 1 > greatest){
                    greatest = dp[i] + 1;
                    count = countseq[i];
                }
                else if(dp[i] + 1 == greatest){
                    count += countseq[i];
                }
            }
        }
        dp[index] = greatest;
        countseq[index] = count;
        return;
    }
};