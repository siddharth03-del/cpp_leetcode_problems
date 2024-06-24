#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int subarraysDivByK(vector<int>& nums, int k){
    unordered_map<int, int> count;
    int sum = 0;
    int r = 0;
    count[0] = 1;
    int total = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        r = sum % k;
        if(r < 0){
            r += k;
        }
        if(count[r] == 0){
            count[r] = 1;
        }
        else{
            total += count[r];
            count[r]++;
        }
    }
    return total;
}
int main(){
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;
    cout << subarraysDivByK(nums, k) << endl;
    return 0;
}