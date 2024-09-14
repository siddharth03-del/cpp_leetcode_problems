#include <string>
#include <vector>
using namespace std;
class Solution{
    public:
    vector<string> ans;
    vector<string> generateParanthesis(int n){
        ans = {};
        f(n, n, "", n);
        return ans;
    }
    void f(int closed, int open, string str, int n){
        if(ans.size() == n*2){
            ans.push_back(str);
            return;
        }
        if(closed){
            f(closed-1, open, str+")", n);
        }
        if(open){
            f(closed, open -1, str+"(", n);
        }
        return;
    }
};