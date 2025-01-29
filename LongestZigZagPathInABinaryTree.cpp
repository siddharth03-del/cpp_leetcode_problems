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
    int max = 0;
    int longestZigZag(TreeNode* root){
        zigzag(root, true);
        zigzag(root, false);
        return max-1;
    }
    int zigzag(TreeNode* root, bool direction){
        if(root == nullptr) return 0;
        int self;
        int extra;
        if(direction){
            self = zigzag(root->left, !direction);
            extra = zigzag(root->right, direction);
        }
        else{
            self = zigzag(root->right, !direction);
            extra = zigzag(root->left, direction);
        }
        if(self + 1 > max){
            max = self + 1;
        }
        if(extra + 1 > max){
            max = extra + 1;
        }
        return self + 1;
    }
};