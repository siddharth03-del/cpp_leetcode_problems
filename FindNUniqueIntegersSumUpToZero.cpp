#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    vector<int> sumZero(int n){
        if(n %2 != 0){
            n = n - 1;
            int a = n / 2;
            vector<int> v;
            for(int i = a; i > 0; i--){
                v.push_back(i);
                v.push_back(-i);
            }
            v.push_back(0);
            return v;
        }
        else{
            int a = n / 2;
            vector<int> v;
            for(int i = a; i > 0; i--){
                v.push_back(i);
                v.push_back(-i);
            }
            return v;
        }
    }
};