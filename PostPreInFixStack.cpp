#include <stack>
#include <vector>
#include <string>
using namespace std;
int postfix(string s){
    stack<int> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(s[i] == '+'){
                int c = a + b;
                st.push(c);
            }
            else if(s[i] == '-'){
                int c = a - b;
                st.push(c);
            }
            else if(s[i] == '*'){
                int c = a*b;
                st.push(c);
            }
            else if(s[i] == '/'){
                int c = a/b;
                st.push(c);
            }
        }
        else{
            char c = s[i] - '0';
            st.push(int(c));
        }
    }
    return st.top();
}
int prefix(string s){
    stack<int> st;
    for(int i = s.size()-1; i >= 0; i--){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(s[i] == '+'){
                int c = a + b;
                st.push(c);
            }
            else if(s[i] == '-'){
                int c = a - b;
                st.push(c);
            }
            else if(s[i] == '*'){
                int c = a*b;
                st.push(c);
            }
            else if(s[i] == '/'){
                int c = a/b;
                st.push(c);
            }
        }
        else{
            char c = s[i] - '0';
            st.push(int(c));
        }
    }
    return st.top();
}
int infix(string s){
    stack<int> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            int a = st.top();
            if(s[i] == '+'){
                i++;
                int b = s[i] - '0';
                int c = a + b;
                st.push(c);
            }
            else if(s[i] == '-'){
                i++;
                int b = s[i] - '0';
                int c = a - b;
                st.push(c);
            }
            else if(s[i] == '*'){
                i++;
                int b = s[i] - '0';
                int c = a*b;
                st.push(c);
            }
            else if(s[i] == '/'){
                i++;
                int b = s[i] - '0';
                int c = a/b;
                st.push(c);
            }
        }
        else{
            int b = s[i] - '0';
            st.push(int(b));
        }
    }
    return st.top();
}