#include <iostream>
#include <string>
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
    string result;
    string forward;
    string backward;
    int count = 0;
    string getDirections(TreeNode* root, int startValue, int destValue){
        fun(root, startValue, destValue, false);
        result = forward + backward;
        return result;
    }
    string fun(TreeNode* node, int startv, int destv, bool onefind){
        if(node->val == startv){
            if(!onefind){
                TreeNode* right ;
        TreeNode* left;
        right = node->right;
        left = node->left;
        string rightstring = "null";
        string leftstring = "null";
        if(right){
            rightstring = fun(right, startv, destv, true);
        }
        if(left){
            leftstring = fun(left, startv, destv, true);
        }
        if(rightstring != "null"){
            cout << rightstring << endl;
            // rightstring = 'R' + rightstring;
            backward = 'R' + backward;
            cout << rightstring << endl;
            backward.erase(backward.size() - 1);
            // rightstring.erase(rightstring.size() - 1);
            cout << rightstring << endl;
            // rightstring[rightstring.size() - 1] = 'R';
            result = rightstring;
            return "null";
        }
        else if(leftstring != "null"){
            backward = 'L' + backward;
            backward.erase(backward.size() - 1);
            // leftstring = 'L' + leftstring;
            // leftstring.erase(leftstring.size() - 1);
            // leftstring[leftstring.size() - 1] = 'L';
            result = leftstring;
            return "null";
        }
        }
        else{
            cout << "return startvalue" << endl;
            return "s";
        }
            return "s";
        }
        if(node->val == destv){
            if(!onefind){
                TreeNode* right ;
        TreeNode* left;
        right = node->right;
        left = node->left;
        string rightstring = "null";
        string leftstring = "null";
        if(right){
            rightstring = fun(right, startv, destv, true);
        }
        if(left){
            cout << "leftcalled" << endl;
            leftstring = fun(left, startv, destv, true);
        }
        cout << leftstring << endl;
        if(rightstring != "null"){
            forward[forward.size() - 1] = 'U';
            // rightstring[rightstring.size() - 1] = 'U';
            // result = rightstring;
            return "null";
        }
        else if(leftstring != "null"){
            forward[forward.size() - 1] = 'U';
            // leftstring[leftstring.size() - 1] = 'U';
            // result = leftstring;
            return "null";
        }
        }
        else{
            return "d";
        }
            return "d";
        }
        TreeNode* right ;
        TreeNode* left;
        right = node->right;
        left = node->left;
        string rightstring = "null";
        string leftstring = "null";
        if(right){
            rightstring = fun(right, startv, destv, onefind);
        }
        if(left){
            leftstring = fun(left, startv, destv, onefind);
        }
        if(rightstring != "null" && leftstring != "null"){
            if(rightstring[rightstring.size() - 1] == 's' && leftstring[leftstring.size() - 1] == 'd'){
                forward[forward.size() - 1] = 'U';
                // rightstring[rightstring.size() - 1] = 'U';
                leftstring = 'L' + leftstring;
                backward = 'L' + backward;
                backward.erase(backward.size() - 1);
                // leftstring.erase(leftstring.size() - 1);
                // string ans = rightstring + leftstring;
                // result = ans;
                return "null";
            }
            else if(leftstring[leftstring.size() - 1] == 's' && rightstring[rightstring.size() - 1] == 'd')
                // rightstring = 'R' + rightstring;
                // rightstring.erase(rightstring.size() - 1);
                backward = 'R' + backward;
                backward.erase(backward.size() - 1);
                // rightstring[rightstring.size() - 1] = 'R';
                // leftstring[leftstring.size() - 1] = 'U' ;
                forward[forward.size() - 1] = 'U';
                // reverse(rightstring.begin(), rightstring.end());
                // string ans = leftstring + rightstring;
                // result = ans;
                return "null";
        }
        else if(rightstring != "null"){
            if(rightstring[rightstring.size() - 1] == 's'){
                forward = "U" + forward;
                return rightstring;
            }
            else if(rightstring[rightstring.size() - 1] == 'd'){
                backward = "R" + backward;
                return rightstring;
            }
        }
        else if(leftstring != "null"){
            if(leftstring[leftstring.size() - 1] == 's'){
                forward = "U" + forward;
                return leftstring;
            }
            else if(leftstring[leftstring.size() - 1] == 'd'){
                backward = "R" + backward;
                return leftstring;
            }
        }
        return "null";
    }
};