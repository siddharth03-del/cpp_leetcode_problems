#include <iostream>
#include <string>
#include <stack>
#include <ctype.h>
class Solution{
    public:
    string countOfAtoms(string formula){
        stack<char> st;
        stack<int> multipliers;
        unordered_map<char, int> res;
        for(int i = 0; i < formula.size(); i++){
            char s = formula[i];
            st.push(s);
        }
        int mul = 1;
        char previous;
        while(!st.empty()){
            char r = st.top();
            st.pop();
            if(r == '('){
                int remove = multipliers.top();
                multipliers.pop();
                mul = mul / remove;
                previous = r;
            }
            else if(r == ')'){
                char g = st.top();
                if(!isdigit(previous)){
                    multipliers.push(1);
                }
                previous = r;
            }
            else {
                if(isdigit(r)){
                    int m = r - '0';
                    mul = mul * m;
                    multipliers.push(m);
                    previous = r;
                }
                else if(isalpha(r)){
                    int count = mul;
                    int remove = multipliers.top();
                    multipliers.pop();
                    mul = mul/remove;
                    if(res[r]){
                        res[r] = res[r] + count;
                    }
                    else{
                        res[r] = count;
                    }
                    if(isalpha(st.top())){
                        multipliers.push(1);
                    }
                    previous = r;
                }
            }
        }
        for (const auto& kv : res) {
        std::cout << "Key: " << kv.first << ", Value: " << kv.second << std::endl;
    }
    return "siddharth";
    }
};
int main(){
    Solution s;
    s.countOfAtoms("K4(ON(SO3)2)2");
    return 0;
}