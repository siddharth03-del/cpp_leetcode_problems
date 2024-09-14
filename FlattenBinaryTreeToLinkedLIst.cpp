#include <iostream>
#include <vector>
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
    vector<TreeNode*> nodes;
    void flatten(TreeNode* root){
        if(root == NULL){
            return;
        }
        nodes = {};
        preorder(root);
        TreeNode* curr = nodes[0];
        curr->left = NULL;
        for(int i = 1; i < nodes.size(); i++){
            curr->left = NULL;
            curr->right = nodes[i];
            curr = curr->right;
        }
    }
    void preorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        nodes.push_back(root);
        preorder(root->left);
        preorder(root->right);
        return;
    }
};