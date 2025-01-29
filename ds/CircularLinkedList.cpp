#include <iostream>

// Node class for creating nodes of the circular linked list
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// CircularLinkedList class to manage the linked list
class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Add a node at the head of the list
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // Add a node at the tail of the list
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Add a node at a specific index of the list
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            if (temp->next == head) {
                std::cout << "Index out of bounds" << std::endl;
                return;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete a node at a specific index of the list
    void deleteAtIndex(int index) {
        if (head == nullptr) return;

        Node* temp = head;
        if (index == 0) {
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }
            while (temp->next != head) {
                temp = temp->next;
            }
            Node* toDelete = head;
            head = head->next;
            temp->next = head;
            delete toDelete;
            return;
        }

        for (int i = 0; i < index - 1; i++) {
            if (temp->next == head) {
                std::cout << "Index out of bounds" << std::endl;
                return;
            }
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Display the list
    void display() {
        if (head == nullptr) return;

        Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.addAtHead(10);
    cll.addAtTail(20);
    cll.addAtIndex(1, 15);
    cll.display();  // Output: 10 15 20

    cll.deleteAtIndex(1);
    cll.display();  // Output: 10 20

    return 0;
}