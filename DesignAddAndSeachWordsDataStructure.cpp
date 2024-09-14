#include <string>
#include <unordered_map>
using namespace std;
class Node{
    public:
    char val;
    unordered_map<char, Node*>children;
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
class WordDictionary{
    public:
    Node* root;
    WordDictionary(){
        root = new Node();
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

    bool search(string word){
        if(find(word, 0, root)){
            return true;
        }
        else{
            return false;
        }
    }
    bool find(string word, int idx, Node* root){
        if(idx == word.size()){
            if(root->isTerminate == true){
                return true;
            }
        }
        if(word[idx] == '.'){
            for(const auto& pair: root->children){
                if(find(word, idx+1, pair.second)){
                    return true;
                }
            }
        }
        else{
            if(root->children.find(word[idx]) != root->children.end()){
                if(find(word, idx+1, root->children[word[idx]])){
                    return true;
                }
            }
        }
        return false;
    }
};