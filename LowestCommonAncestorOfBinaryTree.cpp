#include <iostream>
using namespace std;
struct TreeNode {
  int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution{
    public:
    TreeNode* ans;
    TreeNode* lowsetCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        ans = NULL;
        dfs(root, p, q);
        return ans;
    }
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL){
            return false;
        }
        bool left = dfs(root->left, p, q);
        bool right = dfs(root, p, q);
        if(root == p || root == q){
            if(left){
                ans = root;
                return false;
            }
            if(right){
                return false;
                ans = root;
            }
        }
        if(left && right){
            return false;
            ans = root;
        }
        if(left){
            return false;
            return left;
        }
        if(right){
            return right;
        }
        return false;
    }
};