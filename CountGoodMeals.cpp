#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, bool>powers;
        int p = 1;
        for(int i = 1; i <= 21; i++){
            p = p * 2;
            powers[p] = true;
        }
        int total = 0;
        unordered_map<int, int>store;
        store[deliciousness[0]] = 1;
        for(int i = 1; i < deliciousness.size(); i++){
            for(const auto& pair : powers){
                int req =  pair.first - deliciousness[i];
                if(store[req]){
                    total += store[req];
                    total = total % 1000000007;
                }
            }
            if(store[deliciousness[i]]){
                store[deliciousness[i]]++;
            }else{
                store[deliciousness[i]] = 1;
            }
        }
        return total;
    }
};