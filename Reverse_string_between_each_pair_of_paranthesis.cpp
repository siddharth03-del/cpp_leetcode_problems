#include <string>
#include <stack>
using namespace std;
class Solution{
    public:
    stack<char> str;
    string reverseParantheses(string s){
        for(int i = s.size() -1 ; i >= 0; i--){
            if(s[i] == '('){
                reverse();
            }
            else{
                str.push(s[i]);
            }
        }
        string ans = "";
        while(!str.empty()){
            ans = str.top() + ans;
        }
        return ans;
    }
    void reverse(){
        string temp = "";
        while(str.top() != ')'){
            char x = str.top();
            str.pop();
            temp = temp + x;
        }
        str.pop();
        for(int i = 0; i < temp.size(); i++){
            str.push(temp[i]);
        }
    }
};