#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int key) {
        if (!node) return new TreeNode(key);
        if (key < node->val) node->left = insert(node->left, key);
        else node->right = insert(node->right, key);
        return node;
    }

    TreeNode* deleteNode(TreeNode* node, int key) {
        if (!node) return node;
        if (key < node->val) node->left = deleteNode(node->left, key);
        else if (key > node->val) node->right = deleteNode(node->right, key);
        else {
            if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = minValueNode(node->right);
            node->val = temp->val;
            node->right = deleteNode(node->right, temp->val);
        }
        return node;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left) current = current->left;
        return current;
    }

    TreeNode* search(TreeNode* node, int key) {
        if (!node || node->val == key) return node;
        if (key < node->val) return search(node->left, key);
        return search(node->right, key);
    }

    void preorder(TreeNode* node) {
        if (node) {
            cout << node->val << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void inorder(TreeNode* node) {
        if (node) {
            inorder(node->left);
            cout << node->val << " ";
            inorder(node->right);
        }
    }

    void postorder(TreeNode* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->val << " ";
        }
    }

public:
    BinarySearchTree() : root(NULL) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    TreeNode* search(int key) {
        return search(root, key);
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }
};

// Example usage:
int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder traversal: ";
    bst.inorder();  // Output: 20 30 40 50 60 70 80

    cout << "Preorder traversal: ";
    bst.preorder();  // Output: 50 30 20 40 70 60 80

    cout << "Postorder traversal: ";
    bst.postorder();  // Output: 20 40 30 60 80 70 50

    cout << "Searching for 40: ";
    TreeNode* result = bst.search(40);
    if (result) cout << "Found " << result->val << endl;
    else cout << "Not Found" << endl;

    cout << "Deleting 20: ";
    bst.deleteNode(20);
    cout << "Inorder traversal after deletion: ";
    bst.inorder();  // Output: 30 40 50 60 70 80

    return 0;
}
