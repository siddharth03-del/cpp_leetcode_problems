#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution{
    public:
    int evalRPN(vector<string>& tokens){
        stack<int> integers;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+"){
                int b = integers.top();
                integers.pop();
                int a = integers.top();
                integers.pop();
                int c = a+b;
                integers.push(c);
            }
            else if(tokens[i] == "-"){
                int b = integers.top();
                integers.pop();
                int a = integers.top();
                integers.pop();
                int c = a-b;
                integers.push(c);
            }
            else if(tokens[i] == "*"){
                int b = integers.top();
                integers.pop();
                int a = integers.top();
                integers.pop();
                int c = a*b;
                integers.push(c);
            }
            else if(tokens[i] == "/"){
                int b = integers.top();
                integers.pop();
                int a = integers.top();
                integers.pop();
                int c = a/b;
                integers.push(c);
            }
            else{
                int a = stoi(tokens[i]);
                integers.push(a);
            }
        }
        return integers.top();
    }
};