#include <iostream>
#include <vector>
using namespace std;
int numberOfSubarrays(vector<int>&nums, int k){
    int i = 0;
    int j = 0;
    int cnt = 0;
    int totalcnt = 0;
    int odd = 0;
    while(j < nums.size()){
        if(nums[j] % 2 != 0){
            odd++;
            cnt = 0;
        }
        while(odd == k){
            if(nums[i] % 2 != 0){
                odd--;
            }
            cnt++;
            i++;
        }
        totalcnt += cnt;
        j++;
    }
    return totalcnt;
}
int main(){
    vector<int>nums = {2,2,2,1,2,2,1,2,2,2};
    int k = 2;
    cout << numberOfSubarrays(nums, k) << endl;
    return 0;
}