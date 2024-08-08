#include <vector>
#include <string>
using namespace std;
class Solution{
    public:
    int countSeniors(vector<string>& details){
        int count = 0;
        for(int i = 0; i < details.size(); i++){
            string d = details[i];
            char a = d[11];
            char b = d[12];
            int c = int(a) - 48;
            int e = int(b) - 48;
            if(c >= 6){
                if(c == 6){
                    if(e != 0){
                        count++;
                    }
                }
                else{
                    count++;
                }
            }
        }
        return count;
    }
};