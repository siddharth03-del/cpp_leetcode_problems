#include <iostream>
#include<unordered_map>
#include <vector>
using namespace std;
class Solution{
    public:
    bool closeString(string word1, string word2){
        if(word1.size() != word2.size()){
            return false;
        }
        unordered_map<char, int> str1;
        unordered_map<char, int> str2;
        for(int i = 0; i < word1.size(); i++){
            str1[word1[i]]++;
            str2[word2[i]]++;
        }
        vector<int> freq1(100005, 0);
        vector<int> freq2(100005, 0);
        for(const auto& pair : str1){
            freq1[pair.second]++;
        }
        for(const auto& pair : str2){
            freq2[pair.second]++;
        }
        for(int i = 0; i < freq1.size(); i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
};