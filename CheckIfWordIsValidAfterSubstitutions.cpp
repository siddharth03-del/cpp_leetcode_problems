#include <stack>
#include <iostream>
using namespace std;
class Solution{
    public:
    bool isValid(string s){
        stack<char>st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'c'){
                if(!st.empty() && st.top() == 'b'){
                    st.pop();
                    if(!st.empty() && st.top() == 'a'){
                        st.pop();
                    }
                    else{
                        st.push('b');
                    }
                }
            }
            else{
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};