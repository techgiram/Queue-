#include <iostream>
#include <queue>
#include <string>

using namespace std;

void firstNonRepeat(string str) {
    queue<char> Q;
    int freq[26] = {0};

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        Q.push(ch);
        freq[ch - 'a']++;

        // Remove all characters from the queue that have a frequency > 1
        while (!Q.empty() && freq[Q.front() - 'a'] > 1) {
            Q.pop();
        }

        // If queue is empty, print -1; otherwise, print the first non-repeating character
        if (Q.empty()) {
            cout << "-1\n";
        } else {
            cout << Q.front() << "\n";
        }
    }
}

int main() {
    string str = "aabccxb";

    firstNonRepeat(str);

    return 0;
}

