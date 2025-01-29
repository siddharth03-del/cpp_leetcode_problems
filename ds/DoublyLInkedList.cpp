#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
class DoublyLinkedList{
    public:
    Node* head;
    DoublyLinkedList(){
        head = nullptr;
    }
    void display(){
        if(head == NULL){
            return;
        }
        Node* curr = head;
        while(curr != NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    void addAtHead(int val){
    if(head == NULL){
        head = new Node(val);
    }
    else{
        Node* n = new Node(val);
        head->prev = n;
        n->next = head;
        head = n;
    }
    }
    void addtAtTail(int val){
    if(head == NULL){
        head = new Node(val);
    }
    else{
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        Node* n = new Node(val);
        temp->next = n;
        n->prev = temp;
    }
    }
    void addAtIndex(int index, int val){
    if(head == NULL && index!= 0){
        return;
    }
    if(index == 0){
        if(head == NULL){
            head = new Node(val);
            return;
        }
        else{
            Node* n = new Node(val);
            head->prev = n;
            n->next = head;
            head = n;
            return ;
        }
    }
    else{
        int i = 0;
        Node* previous = head;
        bool flag = false;
        for(i; i <= index-2; i++){
            previous = previous->next;
            if(previous->next == NULL){
                break;
                flag = true;
            }
        }
        if(flag){
            if(i == index - 2){
                Node* n = new Node(val);
                previous->next = n;
                n->prev = previous;
            }
            else{
                return;
            }
        }
        Node* n = new Node(val);
        Node* temp = previous->next;
        n->next = previous->next;
        previous->next = n;
        temp->prev = n;
        n->prev = previous;
        return;
    }
    }
    void deleteAtIndex(int index){
    if(index == 0){
        Node* tobedeleted = head;
        if(tobedeleted->next == NULL){
            delete tobedeleted;
            head = NULL;
            return;
        }
        else{
            Node* new1 = tobedeleted->next;
            head = new1;
            delete tobedeleted;
            return;
        }
    }
    else{
        int i = 1;
        Node* previous = head;
        for(i ; i <= index -1; i++){
            if(previous->next == NULL){
                return;
            }
            previous = previous->next;
        }
        if(previous->next == NULL){
            return;
        }
        Node* tobedeleted = previous->next;
        if(tobedeleted->next == NULL){
            previous->next = NULL;
            tobedeleted->prev = nullptr;
            delete tobedeleted;
            return;
        }
        else{
            Node* next = tobedeleted->next;
            previous->next = next;
            next->prev = previous;
            tobedeleted->next = NULL;
            tobedeleted->prev = nullptr;
            delete tobedeleted;
            return;
        }
    }
    }
};
int main(){
    DoublyLinkedList dll;
    dll.addAtHead(1);
    dll.display();
    dll.addtAtTail(2);
    dll.display();
    dll.addtAtTail(3);
    dll.display();
    dll.addtAtTail(4);
    dll.display();
    dll.deleteAtIndex(2);
    dll.display();
    return 0;
}