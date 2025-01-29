#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        deque<char> dq;
        string res = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ']'){
                while(st.top() != '['){
                    res = st.top() + res;
                }
                st.pop();
                string num = "";
                while(!st.empty() && isNum(st.top())){
                    num = st.top() + num;
                    st.pop();
                }
                int n = stoi(num);
                for(int j = 0; j < n-1; j++){
                    res += res;
                }
                for(int j = 0; j < res.size(); j++){
                    st.push(res[j]);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
    bool isAlpha(char s){
        char c = s - 'a';
        if(c >= 0 && c <= 25){
            return true;
        }
        else{
            return false;
        }
    }
    bool isNum(char s){
        char c = s - '0';
        if(c >= 0 && c <= 9){
            return true;
        }
        else{
            return false;
        }
    }
};