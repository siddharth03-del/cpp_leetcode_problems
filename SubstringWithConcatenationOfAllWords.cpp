#include <unordered_map>
#include <vector>
using namespace std;
class Solution{
    public:
    vector<int> findSubstring(string s, vector<string>& words){
        unordered_map<string, int>count;
        vector<int>ans;
        int window = words[0].size()*words.size();
        int wLen = words[0].size();
        if(window > s.size()){
            return ans;
        }
        for(int i = 0; i < words.size(); i++){
            count[words[i]]++;
        }
        bool flag = true;
        for(int i= 0; i < window; i += wLen){
            string word = s.substr(i, wLen);
            if(count.find(word) != count.end()){
                if(count[word] != 0){
                    count[word]--;
                }
                else{
                    flag = false;
                }
            }
            else{
                flag = false;
            }
        }
        if(flag){
            ans.push_back(0);
        }
        int i = 0;
        for(int j = window+wLen; j < s.size(); j += wLen){
            string r = s.substr(i, wLen);
            string a = s.substr(j - wLen, wLen);
            if(count.find(r) != count.end()){
                count[r]++;
            }
            if(count.find(a) != count.end()){
                if(count[a] != 0){
                    count[a]--;
                    ans.push_back(i);
                }
            }
            i += wLen;
        }
        return ans;
    }
};