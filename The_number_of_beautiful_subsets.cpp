#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
vector<int> global;
int K;
bool flag = true;
int f(vector<int>& input, int index){
    int i = index + 1;
    vector<int> out;
    int max = 0;
    for(i; i < global.size(); i++){
        for(int j = 0; j < input.size(); j++){
            int n = abs(global[i] - input[j]);
            if(n == K){
                flag = false;
                break;
            }
        }
        if(flag){
            out = input;
            out.push_back(global[i]);
            flag = true;
            max = max +  1 + f(out , i);
        }
        flag = true;
    }
    return max;
}
int beautifulSubsets(vector<int>& nums, int k){
    global = nums;
    K = k;
    int max = 0;
    for(int i = 0; i < nums.size(); i++){
        vector<int> input;
        input.push_back(nums[i]);
        max = max + f(input, i) + 1;
    }
    return max;
}
