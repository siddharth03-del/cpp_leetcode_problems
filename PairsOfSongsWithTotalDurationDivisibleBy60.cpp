#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution{
    public:
    int numPairsDivisibleBy60(vector<int>& time){
        unordered_map<int,int> map;
        int ans = 0;
        for(int i = 0; i < time.size(); i++){
            int rem = time[i] % 60;
            if(rem == 0){
                ans += map[0];
            }
            else{
                int req = 60 - rem;
                ans += map[req];
            }
            map[rem]++;
        }
        return ans;
    }
};