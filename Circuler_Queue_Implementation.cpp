#include <iostream>
using namespace std;

class Queue {
    int* arr;        // Array to store the queue elements
    int capacity;    // Maximum capacity of the queue
    int f, r;        // Front and rear pointers
    int currSize;    // Current size of the queue

public:
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        currSize = 0;
        f = r = -1;
    }

    void push(int data) {
        if (currSize == capacity) {
            cout << "Queue is full\n";
            return;
        }
        if (f == -1) f = 0; // Initialize front if it's the first element
        r = (r + 1) % capacity;
        arr[r] = data;
        currSize++;
    }

    void pop() {
        if (empty()) {
            cout << "Queue is empty\n";
            return;
        }
        f = (f + 1) % capacity;
        currSize--;
        if (currSize == 0) { // Reset pointers if the queue becomes empty
            f = r = -1;
        }
    }

    int front() {
        if (empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[f];
    }

    bool empty() {
        return currSize == 0; // Fixed comparison (== instead of =)
    }

    ~Queue() {
        delete[] arr; // Clean up dynamically allocated memory
    }
};

int main() {
    Queue q(4);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5); // This will print "Queue is full"

    cout << q.front() << endl; // Output: 1
    q.pop();
    cout << q.front() << endl; // Output: 2
    q.push(5);                 // Add 5 to the queue

    return 0;
}

