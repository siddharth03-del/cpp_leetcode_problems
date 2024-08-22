#include <iostream>
using namespace std;
class Solution{
    public:
    int minSteps(int n){
        if(n == 1){
            return 1;
        }
        return f(n-1, 1,0);
    }
    int f(int target, int current, int clip){
        if(current == target){
            return 1;
        }
        if(current > target){
            return __INT_MAX__  ;
        }
        if(current == clip){
            return f(target, current + clip, clip) + 1;
        }
        int a = f(target, current, current) + 1;
        int b = f(target, current + clip, clip) + 1;
        return min(a,b);
    }
};