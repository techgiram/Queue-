#include <iostream>
#include <deque>

using namespace std;

class Stack {
    deque<int> deq; // Using deque as the underlying container

public:
    // Push element onto the stack
    void push(int data) {
        deq.push_back(data); // Use push_back to mimic stack behavior
    }

    // Pop the top element from the stack
    void pop() {
        if (!deq.empty()) {
            deq.pop_back();
        } else {
            cout << "Stack is empty! Cannot pop." << endl;
        }
    }

    // Get the top element of the stack
    int top() {
        if (!deq.empty()) {
            return deq.back();
        } else {
          //  throw runtime_error("Stack is empty! Cannot access the top element.");
        }
    }

    // Check if the stack is empty
    bool empty() {
        return deq.empty();
    }
};

int main() {
    Stack s;

    // Push elements onto the stack
    for (int i = 1; i <= 5; i++) {
        s.push(i);
    }

    // Print and pop elements from the stack
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}

