#include <iostream>
using namespace std;
class Solution{
    public:
    struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
    TreeNode *search(TreeNode* node, int val){
        if(node == nullptr){
            return nullptr;
        }
        if(node->val < val){
            return search(node->right, val);
        }
        else if(node->val > val){
            return search(node->left, val);
        }
        else{
            return node;
        }
    }
    TreeNode *searchBST(TreeNode* root, int val){
        return search(root, val);
    }
};