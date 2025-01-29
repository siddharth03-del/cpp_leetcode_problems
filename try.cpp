#include <iostream>
using namespace std;
// Node structure
struct Node {
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

// PriorityQueue class
class PriorityQueue {
public:
    PriorityQueue() : head(nullptr) {}

    // Function to push data
    void push(int data) {
        Node* newNode = new Node(data);
        if (!head || head->data < data) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->data >= data) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Function to pop the highest value element
    void pop() {
        if (!head) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Function to get the highest value element
    int top() {
        if (!head) {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }
        return head->data;
    }

    // Function to check if the queue is empty
    bool empty() {
        return !head;
    }

private:
    Node* head;
};

// Example usage
int main() {
    PriorityQueue pq;
    pq.push(4);
    pq.push(5);
    pq.push(6);
    pq.push(7);
    while (!pq.empty()) {
        std::cout << "Element on top is " << pq.top() << endl;
        cout << "Remove element of top " << endl;
        pq.pop();
    }

    return 0;
}
