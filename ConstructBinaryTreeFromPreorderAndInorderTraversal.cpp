#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution{
    public:
    int k = 1;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        if(preorder.empty() || inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        int val = root->val;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == val){
                root->left = buildTree(0, i - 1, preorder, inorder);
                root->right = buildTree(i + 1, inorder.size() - 1, preorder, inorder);
            }
        }
        return root;
    }
    TreeNode* buildTree(int i, int j, vector<int>& preorder, vector<int>& inorder){
        if(i > j){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[k]);
        k++;
        int val = root->val;
        for(int iterator = i; iterator<=j; iterator++){
            if(inorder[iterator] == val){
                root->left = buildTree(i, iterator - 1, preorder, inorder);
                root->right = buildTree(iterator+1, j, preorder, inorder);
            }
        }
        return root;
    }
};