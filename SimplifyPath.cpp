#include <iostream>
#include <deque>
#include <stack>
using namespace std;
class Solution{
    public:
    string simplifyPath(string path){
        deque<string>file;
        string temp = "";
        for(int i = 0; i < path.size(); i++){
            if(path[i] == '/'){
                if(temp == ".."){
                    if(!file.empty()){
                        file.pop_front();
                    }
                    temp = "";
                }else if(temp == "."){
                    temp = "";
                    continue;
                }else if(temp == ""){
                    continue;
                }
                else{
                    file.push_front(temp);
                    temp = "";
                }
            }
            else{
                temp = temp + path[i];
            }
        }
        if(!(path[path.size() - 1] == '/')){
            if(temp == ".."){
                if(!file.empty()){
                    file.pop_front();
                }
            }
            else if(temp == "."){
            }
            else if(temp == ""){
            }
            else{
                file.push_front(temp);
            }
        }
        string ans = "";
        while(!file.empty()){
            ans = ans + "/";
            ans = ans + file.back();
            file.pop_back();
        }
        if(ans == ""){
            ans = "/";
        }
        return ans;
    }
};