#include <iostream>
#include <deque>

using namespace std;

class Queue {
    deque<int> deq; // Using deque as the underlying container

public:
    // Push element to the back of the queue
    void push(int data) {
        deq.push_back(data);
    }

    // Remove element from the front of the queue
    void pop() {
        if (!deq.empty()) {
            deq.pop_front();
        } else {
            cout << "Queue is empty!" << endl;
        }
    }

    // Get the element at the front of the queue
    int front() {
        if (!deq.empty()) {
            return deq.front();
        } else {
           // throw runtime_error("Queue is empty! Cannot access the front element.");
        }
    }

    // Check if the queue is empty
    bool empty() {
        return deq.empty();
    }
};

int main() {
    Queue q;

    // Push elements into the queue
    for (int i = 1; i <= 5; i++) {
        q.push(i);
    }

    // Print and pop elements from the queue
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}

