#include <vector>
using namespace std;
class Solution{
    public:
    vector<vector<int>>question;
    vector<int>dp;
    long long mostPoints(vector<vector<int>>& questions){
        question = questions;
        dp.resize(100005, -1);
        return f(0);
    }
    long long f(int index){
        if(dp[index] != -1){
            return dp[index];
        }
        if(index >= question.size()){
            return 0;
        }
        int points = question[index][0];
        int skip = question[index][1];
        int a = f(index + skip + 1) + points;
        int b = f(index + 1);
        return dp[index] = max(a,b);
    }
};