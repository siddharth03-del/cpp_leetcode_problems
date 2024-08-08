#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution{
    public:
    int maximumGain(string s, int x, int y){
        stack<char> a;
        a.push(s[0]);
        int maxGain = 0;
        if(x >= y){
            for(int i = 1; i < s.size(); i++){
                if(s[i] == 'b'){
                    if(!a.empty()){
                        if(a.top() == 'a'){
                            maxGain += x;
                            a.pop();
                        }
                        else{
                            a.push(s[i]);
                        }
                    }
                    else{
                        a.push(s[i]);
                    }
                }
                else{
                    a.push(s[i]);
                }
            }
        }
        else{
            for(int i =1; i < s.size(); i++){
                if(s[i] == 'a'){
                    if(!a.empty()){
                        if(a.top() == 'b'){
                            maxGain += y;
                            a.pop();
                            cout << "y gain" << endl;
                        }
                        else{
                            a.push(s[i]);
                        }
                    }
                    else{
                        a.push(s[i]);
                    }
                }
                else{
                    a.push(s[i]);
                }
            }
        }
        cout << a.size() << endl;
        stack<char> b;
        while(!a.empty()){
            if(a.top() == 'a'){
                if(!b.empty()){
                    if(b.top() == 'b'){
                        maxGain += x;
                        b.pop();
                        a.pop();
                        cout << "x gain" << endl;
                    }
                    else{
                        char x = a.top();
                        a.pop();
                        b.push(x);
                    }
                }
                else{
                    char x = a.top();
                    a.pop();
                    b.push(x);
                }
            }
            else if(a.top() == 'b'){
                if(!b.empty()){
                    if(b.top() == 'a'){
                        maxGain += y;
                        b.pop();
                        a.pop();
                    }
                    else{
                        char x = a.top();
                        a.pop();
                        b.push(x);
                    }
                }
                else{
                    char x = a.top();
                    a.pop();
                    b.push(x);
                }
            }
            else{
                char x = a.top();
                a.pop();
                b.push(x);
            }
        }
        return maxGain;
    }
};
int main(){
    Solution s;
    int r = s.maximumGain("abbmzgaabtaabsbabhaahabnaeabdbaababbbiabaavababtabwbababzbdabbaaabhbyabdvabbaabbquapaaaaqbbblbuaawlnbbaxaubbbbbpbabbbpaaaacbbaabaaaahbbcoyaauabanqaabpbbbgaawbhabbbbaobsaaababbafbababbbbaaaqbabsbsmabbxqylbbbba", 9421, 8003);
    cout << r << endl;
    return 0;
}