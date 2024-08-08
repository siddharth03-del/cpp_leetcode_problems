#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution{
    public:
    int minimumPushesz(string word){
        unordered_map<char, int> freq;
        for(int i = 0; i < word.size(); i++){
            if(freq[word[i]]){
                freq[word[i]]++;
            }
            else{
                freq[word[i]] = 1;
            }
        }
        vector<int> freqsort;
        for(const auto& pair: freq){
            freqsort.push_back(pair.second);
        }
        sort(freqsort.begin(), freqsort.end());
        int pushassign = 1;
        int ans = 0;
        int counter = 8;
        for(int i = 0; i < freqsort.size(); i++){
            if(counter == 0){
                pushassign++;
                counter = 7;
                ans += pushassign*freq[i];
            }
            else{
                ans += pushassign*freq[i];
                counter--;
            }
        }
        return ans;
    }
};