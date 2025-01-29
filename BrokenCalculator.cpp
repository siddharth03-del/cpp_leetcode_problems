#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    int brokenCalc(int startValue, int target){
        int ans = 0;
        return f(startValue, target);
    }
    int f(int startValue, int target){
        if(startValue == target){
            return 0;
        }
        if(startValue* 2 > target+1){
            return f(startValue-1, target) + 1;
        }
        else{
            return min(f(startValue*2, target), f(startValue-1, target)) + 1;
        }
    }
};