#include <vector>
#include <algorithm>
using namespace std;
class Solution{
    public:
    int hIndex(vector<int>& citations){
        int max = 0;
        sort(citations.begin(), citations.end(), greater<int>());
        for(int i = 0; i < citations.size(); i++){
            if(citations[i] >= i + 1){
                if(i + 1 > max){
                    max = i + 1;
                }
            }
        }
        return max;
    }
};