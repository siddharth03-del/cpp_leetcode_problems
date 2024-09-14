#include <string>
#include <unordered_map>
using namespace std;
class Solution{
    public:
    unordered_map<int, char> code;
    vector<int> dp(105, -1);
    int f(int index, const string &str) {
    if (index >= str.length()) {
        return 1;
    }
    if (dp[index] != -1) {
        return dp[index];
    }
    char a = str[index];
    string b;
    int f1 = 0, f2 = 0;
    if (index != str.length() - 1) {
        b = str.substr(index, 2);
    }
    if (code[a - '0']) {
        f1 = f(index + 1, str);
    }
    if (!b.empty() && code[stoi(b)]) {
        f2 = f(index + 2, str);
    }
    return dp[index] = f1 + f2;
}
int numDecodings(string s) {
    for (int i = 1; i < 27; i++) {
        code[i] = 'A' + i - 1;
    }
    return f(0, s);
}
};
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, char> code;
vector<int> dp(105, -1);

int f(int index, const string &str) {
    if (index >= str.length()) {
        return 1;
    }
    if (dp[index] != -1) {
        return dp[index];
    }
    char a = str[index];
    string b;
    int f1 = 0, f2 = 0;
    if (index != str.length() - 1) {
        b = str.substr(index, 2);
    }
    if (code[a - '0']) {
        f1 = f(index + 1, str);
    }
    if (!b.empty() && code[stoi(b)]) {
        f2 = f(index + 2, str);
    }
    return dp[index] = f1 + f2;
}

int numDecodings(string s) {
    for (int i = 1; i < 27; i++) {
        code[i] = 'A' + i - 1;
    }
    return f(0, s);
}

int main() {
    string s = "123";
    cout << numDecodings(s) << endl;
    return 0;
}
