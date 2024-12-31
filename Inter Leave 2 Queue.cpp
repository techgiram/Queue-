#include <iostream>
#include <queue>

using namespace std;

void interLeave(queue<int>& org) {
    int n = org.size();
    if (n % 2 != 0) {
        cout << "The queue size must be even to interleave.\n";
        return;
    }

    queue<int> first;

    // Step 1: Push the first half of the elements into the `first` queue
    for (int i = 0; i < n / 2; i++) {
        first.push(org.front());
        org.pop();
    }

    // Step 2: Interleave the elements from `first` and `org`
    while (!first.empty()) {
        org.push(first.front());
        first.pop();

        org.push(org.front());
        org.pop();
    }
}

int main() {
    queue<int> org;

    // Populate the queue with integers from 1 to 10
    for (int i = 1; i <= 10; i++) {
        org.push(i);
    }

    // Interleave the queue
    interLeave(org);

    // Print the interleaved queue
    while (!org.empty()) {
        cout << org.front() << endl;
        org.pop();
    }

    return 0;
}

