#include <iostream>

// Node class for creating nodes of the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Queue class
class Queue {
private:
    Node* frontNode;
    Node* rearNode;

public:
    Queue() {
        frontNode = nullptr;
        rearNode = nullptr;
    }

    // Push an element to the queue
    void push(int val) {
        Node* newNode = new Node(val);
        if (rearNode == nullptr) {
            frontNode = newNode;
            rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
    }

    // Pop an element from the queue
    void pop() {
        if (frontNode == nullptr) {
            std::cout << "Queue is empty\n";
            return;
        }
        Node* temp = frontNode;
        frontNode = frontNode->next;
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }
        delete temp;
    }

    // Get the front element of the queue
    int front() {
        if (frontNode == nullptr) {
            std::cout << "Queue is empty\n";
            return -1; // or throw an exception
        }
        return frontNode->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return frontNode == nullptr;
    }
};

// Main function for demonstration
int main() {
    Queue queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);

    std::cout << "Front element: " << queue.front() << "\n"; // Output: 10

    queue.pop();
    std::cout << "Front element after pop: " << queue.front() << "\n"; // Output: 20

    return 0;
}
