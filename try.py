#include <iostream>
struct Node {
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};
class PriorityQueue {
public:
    PriorityQueue() : head(nullptr) {}
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

    void pop() {
        if (!head) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int top() {
        if (!head) {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }
        return head->data;
    }
    bool empty() {
        return !head;
    }

private:
    Node* head;
};

int main() {
    PriorityQueue pq;
    pq.push(4);
    pq.push(5);
    pq.push(6);
    pq.push(7);

    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
