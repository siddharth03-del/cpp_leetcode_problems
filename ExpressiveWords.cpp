#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution{
    public:
    int expressiveWords(string s, vector<string>& words){
        vector<char> order;
        vector<int> valorder;
        char c = s[0];
        int count = 1;
        int ans =0;
        for(int i = 1; i < s.size(); i++){
            if(s[i] != c){
                order.push_back(c);
                valorder.push_back(count);
                c = s[i];
                count = 1;
            }
            else{
                count++;
            }
        }
        order.push_back(c);
        valorder.push_back(count);
        for(int i = 0; i < words.size(); i++){
            string a = words[i];
            vector<char> temporder;
            vector<int> tempvalorder;
            char d = a[0];
            int cnt = 1;
            for(int j = 1; j < a.size(); j++){
                if(a[j] != d){
                    temporder.push_back(d);
                    tempvalorder.push_back(cnt);
                    d = a[j];
                    count = 1;
                }
                else{
                    count++;
                }
            }
            temporder.push_back(d);
            tempvalorder.push_back(cnt);
            int j = 0;
            int k = 0;
            bool flag = true;
            if(order.size() != temporder.size()){
                flag = false;
            }
            while(j < order.size() && k < temporder.size()){
                if(order[j] == temporder[k]){
                    if(valorder[j] < 3){
                        if(valorder[j] != tempvalorder[k]){
                            flag = false;
                            break;
                        }
                    }
                }
                else{
                    flag = false;
                    break;
                }
                j++;
                k++;
            }
            if(flag){
                ans++;
            }
        }
        return ans;
    }
};