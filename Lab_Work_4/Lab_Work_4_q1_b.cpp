#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

void insert(DNode** head, int data) {
    DNode* newNode = new DNode();
    newNode->data = data;
    newNode->next = (*head);
    newNode->prev = nullptr;

    if ((*head) != nullptr) {
        (*head)->prev = newNode;
    }

    (*head) = newNode;
}

DNode* orderedUnionDoubly(DNode* A1, DNode* A2) {
    DNode* result = nullptr;
    DNode** lastPtrRef = &result;

    while (A1 != nullptr && A2 != nullptr) {
        if (A1->data < A2->data) {
            insert(lastPtrRef, A1->data);
            A1 = A1->next;
        }
        else if (A1->data > A2->data) {
            insert(lastPtrRef, A2->data);
            A2 = A2->next;
        }
        else {
            insert(lastPtrRef, A1->data);
            A1 = A1->next;
            A2 = A2->next;
        }
        lastPtrRef = &((*lastPtrRef)->next);
    }

    while (A1 != nullptr) {
        insert(lastPtrRef, A1->data);
        A1 = A1->next;
    }
    while (A2 != nullptr) {
        insert(lastPtrRef, A2->data);
        A2 = A2->next;
    }

    return result;
}

void printDoublyList(DNode* n) {
    while (n != nullptr) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main() {
    DNode* A1 = nullptr;
    DNode* A2 = nullptr;

    insert(&A1, 5);
    insert(&A1, 3);
    insert(&A1, 2);

    insert(&A2, 4);
    insert(&A2, 3);
    insert(&A2, 1);

    cout << "Union of two double linked lists: ";
    DNode* resultDoubly = orderedUnionDoubly(A1, A2);
    printDoublyList(resultDoubly);

    return 0;
}