#include <iostream>
using namespace std;
struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode() : val(0), left(nullptr), right(nullptr) {}
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int count;
    int pathSum(TreeNode* root, int targetSum) {
        count = 0;
        if(root->val == targetSum){
            count++;
        }
        f(root->left, targetSum, root->val);
        f(root->right, targetSum, root->val);
        return count;

    }
    void f(TreeNode* root, int target, int sum){
        if(root == nullptr){
            return;
        }
        if(sum + root->val == target){
            count++;
        }
        if(root->val == target){
            count++;
        }
        f(root->right, target, sum + root->val);
        f(root->left, target, sum + root->val);
        f(root->right, target, root->val);
        f(root->left, target, root->val);
        return;
    }
};