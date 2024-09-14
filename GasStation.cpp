#include <vector>
using namespace std;
class Solution{
    public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        int total = 0;
        int start = 0;
        int tank = 0;
        for(int i = 0; i < gas.size(); i++){
            total += gas[i] - cost[i];
            if(gas[i] - cost[i] > 0){
                if(tank <= 0){
                    start = i;
                    tank = gas[i] - cost[i];
                }else{
                    tank += gas[i] - cost[i]
                }
            }
            else{
                if(tank > 0){
                    tank += gas[i] - cost[i];
                }
            }
        }
        if(total >= 0){
            return start;
        }else{
            return -1;
        }
    }
};