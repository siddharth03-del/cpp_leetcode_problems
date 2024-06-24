#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int minKBitFlips(vector<int>& nums, int k){
    queue<int> flipped;
    int res = 0;
    for(int i=0; i < nums.size(); i++ ){
        int s = flipped.size();
        bool flip;
        if(s % 2 == 0){
            flip = false;
        }
        else{
            flip = true;
        }
        if(nums[i] == 0){
            if(flip){
                if(flipped.front() == i){
                    flipped.pop();
                }
            }
            else{
                if((i + k - 1) > nums.size() - 1){
                    return -1;
                }
                res++;
                flipped.push((i + k - 1));
                if(flipped.front() == i){
                    flipped.pop();
                }
            }
        }
        else{
            if(flip){
                if((i + k - 1) > nums.size() - 1){
                    return -1;
                }
                res++;
                flipped.push((i + k - 1));
                if(flipped.front() == i){
                    flipped.pop();
                }
            }
            else{
                if(flipped.front() == i){
                    flipped.pop();
                }
            }
        }
    }
    return res;
}
int main(){
    vector<int> inp ={1,1,0};
    int k = 2;
    cout << minKBitFlips(inp, k) << endl;
}