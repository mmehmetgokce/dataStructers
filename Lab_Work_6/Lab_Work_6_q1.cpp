#include <iostream>
#include <queue>
using namespace std;

void display(queue<int> q);

int main() {
    queue<int> q;
    int choice, item;

    while (true) {
        cout << "What operation do you want to perform? Select Option number. Enter 0 to exit.\n";
        cout << "1. Enqueue()\n2. Dequeue()\n3. isEmpty()\n4. isFull()\n5. count()\n6. display()\n7. Clear Screen\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter an item to Enqueue in the Queue\n";
            cin >> item;
            q.push(item);
            break;
        case 2:
            if (!q.empty()) {
                cout << "Dequeued: " << q.front() << endl;
                q.pop();
            }
            else {
                cout << "Queue is empty\n";
            }
            break;
        case 3:
            cout << (q.empty() ? "Queue is empty\n" : "Queue is not empty\n");
            break;
        case 4:
            cout << "Queue is not full\n";
            break;
        case 5:
            cout << "Queue size: " << q.size() << endl;
            break;
        case 6:
            display(q);
            break;
        case 7:
            system("cls");
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid option. Please try again.\n";
        }
        cout << "\n";
    }
}

void display(queue<int> q) {
    if (q.empty()) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}