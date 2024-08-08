#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
    public:
    string numberToWords(int num){
        if(num == 0){
            return "Zero";
        }
        int q;
        int r;
        vector<string> arr;
        while(num > 0){
            q = num/1000;
            r = num % 1000;
            arr.push_back(fun(r));
            num = q;
        }
        unordered_map<int, string> words;
        words[1] = "Thousand";
        words[2] = "Million";
        words[3] = "Billion";
        words[0] = "";
        // reverse(arr.begin(), arr.end());
        string ans;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] != ""){
                ans = arr[i] + " " + words[i] + " " +ans;
            }
        }
        ans = trim(ans);
        ans = removeExtraSpaces(ans);
        return ans;
    }
    string fun(int num){
        unordered_map<int, string> words;
        words[0] = "Zero";
        words[1] = "One";
        words[2] = "Two";
        words[3] = "Three";
        words[4] = "Four";
        words[5] = "Five";
        words[6] = "Six";
        words[7] = "Seven";
        words[8] = "Eight";
        words[9] = "Nine";
        words[10] = "Ten";
        words[11] = "Eleven";
        words[12] = "Twelve";
        words[13] = "Thirteen";
        words[14] = "Fourteen";
        words[15] = "Fifteen";
        words[16] = "Sixteen";
        words[17] = "Seventeen";
        words[18] = "Eighteen";
        words[19] = "Nineteen";
        words[20] = "Twenty";
        words[30] = "Thirty";
        words[40] = "Forty";
        words[50] = "Fifty";
        words[60] = "Sixty";
        words[70] = "Seventy";
        words[80] = "Eighty";
        words[90] = "Ninety";
        words[100] = "Hundred";
        int c = num % 10;
        num = num / 10;
        int b = num % 10;
        num = num / 10;
        int a = num;
        string ans = "";
        if(a != 0){
            string temp = words[a];
            ans = temp + " " +"Hundred";
        }
        if(b != 0){
            if(b == 1){
                ans = ans + " " +words[b*10 + c];
                return ans;
            }
            else{
                string temp = words[b*10];
                ans = ans + " " + temp;
            }
        }
        if(c != 0){
            ans = ans + " " +words[c];
        }
        return ans;
    }
    std::string trim(const std::string& str) {
    auto start = str.find_first_not_of(' ');
    auto end = str.find_last_not_of(' ');
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}
std::string removeExtraSpaces(const std::string& str) {
    std::string result;
    bool inSpaces = false;
    for (char ch : str) {
        if (std::isspace(ch)) {
            if (!inSpaces) {
                result += ' ';
                inSpaces = true;
            }
        } else {
            result += ch;
            inSpaces = false;
        }
    }
    return result;
}
};
int main(){
    Solution s;
    string r = s.numberToWords(1000010);
    cout << r << endl;
}