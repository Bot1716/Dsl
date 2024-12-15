#include <iostream>
using namespace std;

// Node class to represent each item in the queue
template <typename T>
class Node {
public:
    T data;          // Data item in the queue
    int priority;    // Priority of the data item
    Node* next;      // Pointer to the next node in the list
    Node* prev;      // Pointer to the previous node in the list

    Node(T d, int p) : data(d), priority(p), next(nullptr), prev(nullptr) {}
};

// PriorityQueue class that implements the priority queue using an inorder list
template <typename T>
class PriorityQueue {
private:
    Node<T>* head;  // Head of the doubly linked list

public:
    // Constructor to initialize an empty queue
    PriorityQueue() : head(nullptr) {}

    // Destructor to clean up memory
    ~PriorityQueue() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert an item into the priority queue
    void insert(T data, int priority) {
        Node<T>* newNode = new Node<T>(data, priority);

        // If the list is empty, insert the node as the head
        if (!head) {
            head = newNode;
            return;
        }

        // If new node has the highest priority (should be inserted at the head)
        if (newNode->priority > head->priority) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        // Traverse the list to find the correct position based on priority
        Node<T>* current = head;
        while (current->next && current->next->priority >= priority) {
            current = current->next;
        }

        // Insert the new node after the current node
        newNode->next = current->next;
        if (current->next) {
            current->next->prev = newNode;
        }
        newNode->prev = current;
        current->next = newNode;
    }

    // Remove and return the highest priority item
    T pop() {
        if (!head) {
            cout << "Queue is empty!" << endl;
            return T();  // Return default value for the data type
        }

        Node<T>* temp = head;
        T data = head->data;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        delete temp;
        return data;
    }

    // Display all items in the priority queue
    void display() {
        if (!head) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node<T>* current = head;
        while (current) {
            cout << "Data: " << current->data << ", Priority: " << current->priority << endl;
            current = current->next;
        }
    }
};

// Main function to test the PriorityQueue
int main() {
    PriorityQueue<string> pq;

    pq.insert("Item1", 1);
    pq.insert("Item2", 3);
    pq.insert("Item3", 2);
    pq.insert("Item4", 4);

    cout << "Priority Queue after insertions:" << endl;
    pq.display();

    cout << "\nPop highest priority item: " << pq.pop() << endl;

    cout << "\nPriority Queue after popping one item:" << endl;
    pq.display();

    return 0;
}
