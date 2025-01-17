#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void displayQueue(queue<int> q);

int main() {
    int n, item;
    cout << "Please enter the number of elements: ";
    cin >> n;

    queue<int> q;
    vector<int> v;

    cout << "Please enter elements in queue:\n";
    for (int i = 0; i < n; i++) {
        cin >> item;
        q.push(item);
        v.push_back(item);
    }

    cout << "Original Queue\n";
    displayQueue(q);

    sort(v.begin(), v.end());

    queue<int> sortedQ;
    for (int val : v) {
        sortedQ.push(val);
    }

    cout << "Sorted Queue\n";
    displayQueue(sortedQ);

    return 0;
}

void displayQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}