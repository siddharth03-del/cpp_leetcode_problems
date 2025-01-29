#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    int candy(vector<int>& ratings){
        vector<int> candy(ratings.size(), 1);
        if(ratings.size() == 1){
            return 1;
        }
        if(ratings.size() == 2){
            int i = 0;
            if(ratings[i] > ratings[i+1]){
                candy[i] = candy[i+1] + 1;
            }
            i = ratings.size()-1;
            if(ratings[i] > ratings[i-1]){
                candy[i] = candy[i-1] + 1;
            }
            return candy[0] + candy[1];
        }
        int i = 0;
        if(ratings[i] > ratings[i+1]){
            candy[i] = candy[i+1] + 1;
        }
        for(int i = 1; i < ratings.size()-1; i++){
            if(ratings[i] > ratings[i-1] || ratings[i] > ratings[i+1]){
                if(candy[i] > candy[i-1]  && candy[i] > candy[i+1]){
                    continue;
                }
                if(ratings[i] > ratings[i-1]  &&  ratings[i] > ratings[i+1]){
                    candy[i] = max(candy[i-1], candy[i+1]) + 1;
                }
                else if(ratings[i] > ratings[i-1]){
                    candy[i] = candy[i-1] + 1;
                }
                else{
                    candy[i] = candy[i+1] + 1;
                }
            }
        }
        i = ratings.size()-1;
        if(ratings[i] > ratings[i-1]){
            candy[i] = candy[i-1] + 1;
        }
        for(int i = ratings.size()-2; i >= 1; i--){
            if(ratings[i] > ratings[i-1] || ratings[i] > ratings[i+1]){
                if(candy[i] > candy[i-1]  && candy[i] > candy[i+1]){
                    continue;
                }
                if(ratings[i] > ratings[i-1]  &&  ratings[i] > ratings[i+1]){
                    candy[i] = max(candy[i-1], candy[i+1]) + 1;
                }
                else if(ratings[i] > ratings[i-1]){
                    candy[i] = candy[i-1] + 1;
                }
                else{
                    candy[i] = candy[i+1] + 1;
                }
            }
        }
        int sum = 0;
        for(int i = 0; i < candy.size(); i++){
            sum += candy[i];
        }
        return sum;
    }
};