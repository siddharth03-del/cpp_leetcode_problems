#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution{
    public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k){
        unordered_map<int, int>freq;
        int unique = 0;
        for(int i = 0; i < arr.size(); i++){
            if(freq[arr[i]]){
                freq[arr[i]]++;
            }
            else{
                freq[arr[i]] = 1;
                unique++;
            }
        }
        vector<int>v(100005, 0);
        for(const auto& it: freq){
            v[it.second]++;
        }
        for(int i = 0; i < v.size(); i++){
            if(v[i] != 0){
                if(v[i]*i > k){
                    int q = k/i;
                    unique -= k;
                    break;
                }
                else{
                    k -= v[i]*i;
                    unique -= v[i];
                }
            }
        }
        return unique;
    }
};