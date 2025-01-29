#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
    struct CustomSort{
        bool operator()(vector<int>& a, vector<int>& b){
            if(a[1] == b[1]){
                return a[0] > b[0];
            }
            else{
                return a[1] < b[1];
            }
        }
    };
    class Solution {
    public:
        int findLongestChain(vector<vector<int>>& pairs) {
            sort(pairs.begin(), pairs.end(), CustomSort());
            int count = 1;
            vector<int> last = pairs[0];
            for(int i = 1; i < pairs.size(); i++){
                if(pairs[i][0] > last[1]){
                    count++;
                    last = pairs[i];
                }
            }
            return count;
        }
    };