#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int glo;
class Solution{
    public:
    int dp[100005][2][4];
    int fun(int n, int absent, int late){
        if(dp[n][absent][late] != -1){
            return dp[n][absent][late];
        }
        if(absent >= 2){
            return 0;
        }
        if(late >= 3){
            return 0;
        }
        if(n == glo){
            return 1;
        }
        int addpresent = fun(n +1, absent, 0) % 1000000007;
        int addabsent = fun(n+1, absent+1, 0)  % 1000000007;
        int addlate = fun(n+1, absent, late + 1) % 1000000007;
        return dp[n][absent][late] = (((addpresent + addabsent)  % 1000000007) + addlate)  % 1000000007;
    }
    int checkRecord(int n){
        memset(dp,-1,sizeof(dp));
        glo = n;
        return fun(0,0,0);
    }
};
int main(){
    Solution s;
    cout << s.checkRecord(94738) << endl;
    return 0;
}