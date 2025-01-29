#include <iostream>
using namespace std;
class Solution{
    public:
    int maxVowels(string s, int k){
        int i = 0;
        int j = 0;
        int count = 0;
        int max = 0;
        for(j ; j < k; j++){
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                count++;
            }
        }
        max = count;
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                count--;
        }
        i++;
        while(j < s.size()){
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                count++;
            }
            if(count > max){
                max = count;
            }
            j++;
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                count--;
            }
            i++;
        }
        return max;
    }
};