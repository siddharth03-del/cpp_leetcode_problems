#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    int count = 0;
    int countPairs(TreeNode* root, int distance){
        dfs(root, distance);
        return count;
    }
    vector<int> dfs(TreeNode* root, int distance){
        if(!(root->right) && !(root->left)){
            return {0};
        }
        bool rightcall = false;;
        bool leftcall = false;
        vector<int> right;
        vector<int> left;
        if(root->right){
            right = dfs(root->right, distance);
            rightcall = true;
        }
        if(root->left){
            left = dfs(root->left, distance);
            leftcall = true;
        }
        vector<int> res;
        if(rightcall){
            for(int i = 0; i < right.size(); i++){
            if(right[i] + 1 <= distance){
                    right[i]+=1;
                    res.push_back(right[i]);
            }
            else{
                right[i]+=1;
            }
        }
        }
        if(leftcall){
            for(int i = 0; i < left.size(); i++){
            if(left[i] + 1 <= distance){
                    left[i]+=1;
                    res.push_back(left[i]);
            }
            else{
                left[i]+=1;
            }
        }
        }
        if(rightcall && leftcall){
            for(int i = 0; i < right.size(); i++){
            for(int j = 0; j < left.size(); j++){
                if(right[i] != 0 && left[j]!=0){
                    if(right[i] + left[j] <= distance){
                        cout << root->val << endl;
                    count++;
                }
                }
            }
        }
        }
        return res;
    }
};