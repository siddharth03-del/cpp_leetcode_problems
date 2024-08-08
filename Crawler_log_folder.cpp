#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution{
    public:
    int minOperation(vector<string>& logs){
        int depth = 0;
        for(int i = 0; i < logs.size(); i++){
            if(logs[i] == "../"){
                if(depth != 0){
                    depth--;
                }
            }
            else if(logs[i] == "./"){
                continue;
            }
            else{
                depth++;
            }
        }
        return depth;
    }
};