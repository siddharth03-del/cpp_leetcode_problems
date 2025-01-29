#include <string>
using namespace std;
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string s;
        if(str1.size() < str2.size()){
            s = str1;
        }
        else{
            s = str2;
        }
        string gcd = s;
        while(s.size() > 0){
            if(check(str1, str2, gcd)){
                return gcd;
            }
            else{
                gcd.pop_back();
            }
        }
    }
    bool check(string str1, string str2, string gcd){
        if(str1.size() % gcd.size() == 0 && str2.size() % gcd.size() == 0){
            return false;
        }
        string r1 = "";
        string r2 = "";
        int n1 = str1.size()/gcd.size();
        int n2 = str2.size()/gcd.size();
        for(int i = 0; i < n1; i++){
            r1 = r1 + gcd;
        }
        for(int i = 0; i < n2; i++){
            r2 = r2 + gcd;
        }
        if(r1 == str1 && r2 == str2){
            return true;
        }
        else{
            return false;
        }
    }
};