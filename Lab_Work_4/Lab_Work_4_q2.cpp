#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool isPalindrome(Node* head) {
    stack<int> s;
    Node* temp = head;

    while (temp != nullptr) {
        s.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp != nullptr) {
        if (temp->data != s.top()) {
            return false;
        }
        s.pop();
        temp = temp->next;
    }

    return true;
}

int main() {
    Node* head = nullptr;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    printList(head);

    if (isPalindrome(head)) {
        cout << "The list is a palindrome." << endl;
    }
    else {
        cout << "The list is not a palindrome." << endl;
    }

    return 0;
}