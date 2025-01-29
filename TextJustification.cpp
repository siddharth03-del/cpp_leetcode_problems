#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int till = 0;
        vector<string> word;
        vector<string> ans;
        for(int i = 0; i < words.size(); i++){
            string w = words[i];
            if(till + w.size() + 1 <= maxWidth){
                word.push_back(w);
                till += w.size();
                till += 1;
            }
            else{
                string s = f(word, false, maxWidth);
                word.clear();
                ans.push_back(s);
                word.push_back(words[i]);
                till = words[i].size();
            }
        }
        string s = f(word, true, maxWidth);
        word.clear();
        ans.push_back(s);
        return ans;
    }
    string f(vector<string>& words, bool end, int maxWidth){
        if(end){
            int full = 0;
            for(int i = 0; i < words.size(); i++){
                string w = words[i];
                full += w.size();
            }
            int space = maxWidth - full;
            if(words.size() == 1){
                string s = words[0];
                for(int i = 0; i < space; i++){
                    s += " ";
                }
                return s;
            }
            string s = "";
            for(int i = 0; i < words.size()-1; i++){
                s += words[i];
                s += " ";
                space--;
            }
            s += words[words.size()-1];
            s += string(space, ' ');
            return s;
        }
        else{
            int full = 0;
            for(int i = 0; i < words.size(); i++){
                string w = words[i];
                full += w.size();
            }
            int space = maxWidth - full;
            if(words.size() == 1){
                string s = words[0];
                for(int i = 0; i < space; i++){
                    s += " ";
                }
                return s;
            }
            string s = "";
            int q = space/(words.size()-1);
            int r = space%(words.size()-1);
            for(int i = 0; i < words.size()-1; i++){
                s += words[i];
                if(r != 0){
                    s += string(q+1, ' ');
                    r--;
                }
                else{
                    s += string(q, ' ');
                }
            }
            s += words[words.size()-1];
            return s;
        }
    }
};