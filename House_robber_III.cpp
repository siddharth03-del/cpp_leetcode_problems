#include <iostream>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    unordered_map<TreeNode*, int> dp;
    int rob(TreeNode* root) {
        return f(root);
    }
    int f(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (dp.find(root) != dp.end()) {
            return dp[root];
        }
        TreeNode *left1 = root->left;
        TreeNode *right1 = root->right;
        TreeNode *a = NULL;
        TreeNode *b = NULL;
        TreeNode *c = NULL;
        TreeNode *d = NULL;
        if (left1) {
            a = left1->left;
            b = left1->right;
        }
        if (right1) {
            c = right1->left;
            d = right1->right;
        }
        int add = 0;
        if (a) {
            add += f(a);
        }
        if (b) {
            add += f(b);
        }
        if (c) {
            add += f(c);
        }
        if (d) {
            add += f(d);
        }
        int i = root->val + add;
        int j = f(left1) + f(right1);
        int ans = max(i, j);
        dp[root] = ans;
        return ans;
    }
};
