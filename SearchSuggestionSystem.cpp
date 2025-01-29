#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;
class Node{
    public:
    char val;
    map<char, Node*>children;
    bool isTerminate;
    Node(){
        isTerminate = false;
        val = NULL;
        children = {};
    }
    Node(char value){
        isTerminate = false;
        val = value;
        children = {};
    }
};
class Solution {
public:
    Node* root;
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new Node();
        for (int i = 0; i < products.size(); i++){
            addWord(products[i]);
        }

    }
    void addWord(string word){
        Node* curr = root;
        for(int i = 0; i < word.size(); i++){
            if(curr->children.find(word[i]) != curr->children.end()){
                curr = curr->children[word[i]];
            }else{
                Node* n = new Node(word[i]);
                curr->children[word[i]] = n;
                curr = n;
            }
        }
        curr->isTerminate = true;
    }
    void f(Node* curr, string search, int index, vector<int>& string){
        
    }

};