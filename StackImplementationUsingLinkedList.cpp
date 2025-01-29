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

// Stack class
class Stack {
private:
    Node* topNode;

public:
    Stack() {
        topNode = nullptr;
    }

    // Push an element onto the stack
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
    }

    // Pop an element from the stack
    void pop() {
        if (topNode == nullptr) {
            std::cout << "Stack is empty\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    // Get the top element of the stack
    int top() {
        if (topNode == nullptr) {
            std::cout << "Stack is empty\n";
            return -1; // or throw an exception
        }
        return topNode->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return topNode == nullptr;
    }
};

// Main function for demonstration
int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.top() << "\n"; // Output: 30

    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << "\n"; // Output: 20

    return 0;
}
