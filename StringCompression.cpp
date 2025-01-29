#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution{
    public:
    int compress(vector<char>& chars){
        int curr = 1;
        char str = chars[0];
        vector<char> ans;
        for(int i = 1; i < chars.size(); i++){
            if(str != chars[i]){
                curr++;
            }
            else{
                string num = to_string(curr);
                ans.push_back(str);
                for(int i = 0; i < num.size(); i++){
                    ans.push_back(num[i]);
                }
                curr = 1;
                str = chars[i];
            }
        }
        string num = to_string(curr);
        ans.push_back(str);
        for(int i = 0; i < num.size(); i++){
            ans.push_back(num[i]);
        }
        for(int i = 0; i < ans.size(); i++){
            chars[i] = ans[i];
        }
        return ans.size();
    }
};