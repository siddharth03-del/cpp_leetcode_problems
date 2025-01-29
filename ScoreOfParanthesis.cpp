#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution{
    public:
    int scoreOfParantheses(string s){
        int ans = 0;
        int current = 0.5;
        stack<int> st;
        st.push(0.5);
        for(int i = 0; i < s.size();i++){
            if(s[i] == '('){
                if(st.top() != 0.5){
                    while(st.size() != 1){
                        int temp = st.top();
                        st.pop();
                        temp += st.top();
                        st.push(temp);
                    }
                st.push(0.5);
                }
            }else{
                int temp = st.top();
                st.pop();
                temp *= 2;
                st.push(temp);
            }
        }
        while(st.size() != 1){
            int temp = st.top();
            st.pop();
            temp += st.top();
            st.pop();
            st.push(temp);
        }
        return st.top();
    }
};