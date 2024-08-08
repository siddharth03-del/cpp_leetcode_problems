#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    int numTeams(vector<int>& rating){
        int n = rating.size();
        vector<int> left(n, 0);
        vector<int> right(n,0);
        for(int i = 0; i < n-1; i++){
            int count = 0;
            for(int j = i + 1; j < n; j++){
                if(rating[j] > rating[i]){
                    count++;
                }
            }
            right[i] = count;
        }
        for(int i = n-1; i > 0 ; i--){
            int count = 0;
            for(int j = i -1; j >= 0; j--){
                if(rating[j] > rating[i]){
                    count++;
                }
            }
            left[i] = count;
        }
        int i = 0;
        while(i != right.size() -2){
            int count = 0;
            if(right[i] == 0){
                i++;
            }
            else{
                
            }
        }
    }
};