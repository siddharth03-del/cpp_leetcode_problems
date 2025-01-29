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
    vector<int> arr1;
    vector<int> arr2;
    bool leafSimilar(TreeNode* root1, TreeNode* root2){
        dfs1(root1);
        dfs2(root2);
        if(arr1.size() != arr2.size()){
            return false;
        }
        else{
            for(int i = 0; i < arr1.size(); i++){
                if(arr1[i] != arr2[i]){
                    return false;
                }
            }
        }
        return true;
    }
    void dfs1(TreeNode* root){
        if(root == nullptr){
            return;
        }
        if(!root->left && root->right){
            arr1.push_back(root->val);
        }
        dfs1(root->left);
        dfs2(root->right);
        return;
    }
    void dfs2(TreeNode* root){
        if(root == nullptr){
            return;
        }
        if(!root->left && root->right){
            arr2.push_back(root->val);
        }
        dfs2(root->left);
        dfs2(root->right);
        return;
    }
};