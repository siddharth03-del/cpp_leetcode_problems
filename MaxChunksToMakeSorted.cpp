#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int totalChunks = 0;
        vector<int> store;
        for(int i = 0; i < arr.size(); i++){
            store.push_back(arr[i]);
            sort(store.begin(), store.end());
            bool flag = false;
            for(int j = 0; j <= i; j++){
                if(store[j] != j){
                    flag = true;
                    break;
                }
            }
            if(flag){
                continue;
            }else{
                totalChunks++;
            }
        }
        return totalChunks;
    }
};