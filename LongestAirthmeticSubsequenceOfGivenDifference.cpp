#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution{
    public:
    int longestSubsequence(vector<int>& arr, int difference){
        unordered_map<int, int> sequencelen;
        int greatest = 1;
        for(int i = 0; i < arr.size(); i++){
            int diff = arr[i] + difference;
            int count = 0;
            if(sequencelen[arr[i]]){
                count = sequencelen[arr[i]] + 1;
            }
            else{
                count = 1;
            }
            if(count > greatest){
                greatest = count;
            }
            sequencelen[diff] = count;
        }
        return greatest;
    }
};
