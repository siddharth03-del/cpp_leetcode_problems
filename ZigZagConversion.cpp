#include <string>
#include <vector>
using namespace std;
class Solution{
    public:
    string convert(string s, int numRows){
        if(numRows == 1){
            return s;
        }
        vector<vector<char>>rows;
        rows.resize(numRows, vector<char>());
        int insert = 0;
        bool up = true;
        bool down = false;
        for(int i = 0; i < string.size(); i++){
            rows[insert].push_back(s[i]);
            if(up){
                if(insert == numRows - 1){
                    up = false;
                    down = true;
                    insert--;
                }else{
                    insert++;
                }
            }else{
                if(insert == 0){
                    up = true;
                    down = false;
                    insert++;
                }else{
                    insert--;
                }
            }
        }
        string ans = "";
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < rows[i].size(); j++){
                ans += rows[i][j];
            }
        }
        return ans;
    }
};