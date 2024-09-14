#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};
class MyLinkedList{
    public:
    int data;
    node* head;
    MyLinkedList(){
        head = NULL;
    }
    void display(){
        if(head == NULL){
            return;
        }
        node* curr = head;
        while(curr != NULL){
            cout << curr->data << endl;
            curr = curr->next;
        }
    }
    int get(int index){
    if(head == NULL){
        return -1;
    }
    int i = 0;
    node* temp = head;
    for(i; i < index; i++){
        if(temp->next == NULL){
            if(i == index){
                break;
            }
            else{
                return -1;
            }
        }
        temp = temp->next;
    }
    return temp->data;
    }

    void addAtHead(int val){
    if(head == NULL){
        head = new node(val);
    }
    else{
        node* n = new node(val);
        n->next = head;
        head = n;
    }
    }

    void addtAtTail(int val){
    if(head == NULL){
        head = new node(val);
    }
    else{
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new node(val);
    }
    }

    void addAtIndex(int index, int val){
    if(head == NULL && index!= 0){
        return;
    }
    if(index == 0){
        if(head == NULL){
            head = new node(val);
            return;
        }
        else{
            node* n = new node(val);
            n->next = head;
            head = n;
            return ;
        }
    }
    else{
        int i = 0;
        node* previous = head;
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
                node* n = new node(val);
                previous->next = n;
            }
            else{
                return;
            }
        }
        node* n = new node(val);
        n->next = previous->next;
        previous->next = n;
        return;
    }
    }
    void deleteAtIndex(int index){
    if(index == 0){
        node* tobedeleted = head;
        if(tobedeleted->next == NULL){
            delete tobedeleted;
            head = NULL;
            return;
        }
        else{
            node* new1 = tobedeleted->next;
            head = new1;
            delete tobedeleted;
            return;
        }
    }
    else{
        int i = 1;
        node* previous = head;
        for(i ; i <= index -1; i++){
            if(previous->next == NULL){
                return;
            }
            previous = previous->next;
        }
        if(previous->next == NULL){
            return;
        }
        node* tobedeleted = previous->next;
        if(tobedeleted->next == NULL){
            previous->next = NULL;
            delete tobedeleted;
            return;
        }
        else{
            node* next = tobedeleted->next;
            previous->next = next;
            tobedeleted->next = NULL;
            delete tobedeleted;
            return;
        }
    }
    }
};