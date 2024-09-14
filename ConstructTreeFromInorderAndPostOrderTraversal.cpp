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
    int k;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        if(postorder.empty() || inorder.empty()) return nullptr;
        k = postorder.size() -1 ;
        int val = postorder[k];
        k--;
        TreeNode* root = new TreeNode(val);
        int k = postorder.size() -1;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == val){
                root->right = buildTree(i+1, inorder.size()-1, inorder, postorder);
                root->left = buildTree(0, i-1,inorder, postorder);
            }
        }
        return root;
    }
    TreeNode* buildTree(int i, int j, vector<int>& inorder, vector<int>& postorder){
        if(i > j) return nullptr;
        int val = postorder[k];
        k--;
        TreeNode* root = new TreeNode(val);
        for(int iterator = i; iterator <= j; iterator++){
            if(inorder[iterator] == val){
                root->right = buildTree(iterator+1, j, inorder, postorder);
                root->left = buildTree(i, iterator-1, inorder, postorder);
            }
        }
        return root;
    }
};