#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> global;
unordered_map<string, bool> check;

void f(string s, string ans) {
    if (s.empty()) {
        ans = ans.substr(ans.find_first_not_of(" "), ans.find_last_not_of(" ") + 1); // Trim leading and trailing spaces
        global.push_back(ans);
        return;
    }

    unordered_map<string, int> freq;
    string r = "";
    string a = "";
    int i = 0;
    while (i < s.length()) {
        r += s[i];
        i++;
        if (check[r]) {
            if (freq.find(r) == freq.end()) {
                freq[r] = 1;
                int k = i;
                a = "";
                while (k < s.length()) {
                    a += s[k];
                    k++;
                }
                string g = ans;
                g += " " + r;
                r = "";
                i = 0;
                f(a, g);
            }
        }
    }
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    for (const string& word : wordDict) {
        check[word] = true;
    }
    f(s, "");
    return global;
}

int main() {
    string inputString = "catsanddog";
    vector<string> wordDictionary = {"cat", "cats", "and", "sand", "dog"};
    vector<string> validCombinations = wordBreak(inputString, wordDictionary);

    for (const string& combination : validCombinations) {
        cout << combination << endl;
    }

    return 0;
}
