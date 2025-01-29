#include <iostream>
#include <stdexcept>

// Node structure
struct Node {
    int data;
    Node* next;
};

// Stack class
class Stack {
private:
    Node* topNode;

public:
    // Constructor
    Stack() : topNode(nullptr) {}

    // Destructor to clean up memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Push operation
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = topNode;
        topNode = newNode;
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack underflow");
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    // Top operation
    int top() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        return topNode->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return topNode == nullptr;
    }
};

// Main function to test the Stack
int main() {
    Stack stack;

    // Push elements
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Display the top element
    std::cout << "Top element: " << stack.top() << std::endl; // Should display 30

    // Pop an element
    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl; // Should display 20

    // Clean up and check stack state
    stack.pop();
    stack.pop();

    // Check if stack is empty
    if (stack.isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
    }

    return 0;
}
