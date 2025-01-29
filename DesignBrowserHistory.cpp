#include <iostream>
using namespace std;
struct Node{
    public:
    string url;
    Node* prev;
    Node* next;
    Node(string url){
        this->url = url;
        prev = nullptr;
        next = nullptr;
    }
};
class BrowserHistory {
public:
    Node* currentpage = nullptr;
    BrowserHistory(string homepage) {
        Node * newpage = new Node(homepage);
        currentpage = newpage;
    }
    
    void visit(string url) {
        Node* newpage = new Node(url);
        currentpage->next = newpage;
        newpage->prev = currentpage;
        currentpage = newpage;
    }
    
    string back(int steps) {
        int x = 0;
        while ( x < steps && currentpage->prev != nullptr){
            currentpage = currentpage->prev;
            x++;
        }
        return currentpage->url;
    }
    
    string forward(int steps) {
        int x = 0;
        while (x < steps && currentpage->next != nullptr){
            currentpage = currentpage->next;
            x++;
        }
        return currentpage->url;
    }
};