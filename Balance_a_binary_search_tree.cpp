#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
vector<int> arr;
void sortedarr(TreeNode* root){
    TreeNode* right = root->right;
    TreeNode* left = root->left;
    if(left){
        sortedarr(left);
    }
    arr.push_back(root->val);
    if(right){
        sortedarr(right);
    }
    return;
}
TreeNode* fun(int i, int j){
    int mid = (i + j)/2;
    TreeNode* a = new TreeNode(arr[mid]);
    if(mid - 1 >= i){
        a->left = fun(i, mid-1);
    }
    if(j >= mid+1){
        a->right = fun(mid+1, j);
    }
    return a;
}
TreeNode* balanceBST(TreeNode* root){
    arr = {};
    sortedarr(root);
    TreeNode* ans = fun(0, arr.size() - 1);
    return ans;
}
};