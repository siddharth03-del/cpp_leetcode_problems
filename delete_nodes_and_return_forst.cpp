#include <iostream>
#include <vector>
#include <unordered_map>
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
    vector<TreeNode*> result;
    unordered_map<int, bool> check;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete){
        for(int i = 0; i < to_delete.size(); i++){
            check[to_delete[i]] = true;
        }
        return result;
    }
    TreeNode* fun(TreeNode* root, bool fatherdead){
        if(check[root->val]){
            TreeNode* right;
            TreeNode* left;
            right = root->right;
            left = root->left;
            if(right){
                fun(right, true);
            }
            if(left){
                fun(left, true);
            }
            root->right = nullptr;
            root->left = nullptr;
            return nullptr;
        }
        if(fatherdead){
            result.push_back(root);
            TreeNode* right;
            TreeNode* left;
            right = root->right;
            left = root->left;
            if(right){
                root->right = fun(right, false);
            }
            if(left){
                root->left = fun(left, false);
            }
            return root;
        }
        TreeNode* right;
            TreeNode* left;
            right = root->right;
            left = root->left;
            if(right){
                root->right = fun(right, false);
            }
            if(left){
                root->left = fun(left, false);
            }
            return root;
    }
};