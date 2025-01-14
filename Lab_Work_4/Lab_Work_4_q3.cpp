#include <iostream>
#include <vector>
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

bool binarySearch(Node* head, int target) {
    vector<int> arr;
    Node* temp = head;

    while (temp != nullptr) {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return true;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return false;
}

int main() {
    Node* head = nullptr;

    insert(&head, 7);
    insert(&head, 5);
    insert(&head, 3);
    insert(&head, 1);

    printList(head);

    int target = 5;
    cout << "Target number: " << target << endl;

    if (binarySearch(head, target)) {
        cout << "Number found." << endl;
    }
    else {
        cout << "Number not found." << endl;
    }

    return 0;
}