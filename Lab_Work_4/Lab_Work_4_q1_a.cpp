#include <iostream>
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

Node* orderedUnionSingly(Node* L1, Node* L2) {
    Node* result = nullptr;
    Node** lastPtrRef = &result;

    while (L1 != nullptr && L2 != nullptr) {
        if (L1->data < L2->data) {
            insert(lastPtrRef, L1->data);
            L1 = L1->next;
        }
        else if (L1->data > L2->data) {
            insert(lastPtrRef, L2->data);
            L2 = L2->next;
        }
        else {
            insert(lastPtrRef, L1->data);
            L1 = L1->next;
            L2 = L2->next;
        }
        lastPtrRef = &((*lastPtrRef)->next);
    }

    while (L1 != nullptr) {
        insert(lastPtrRef, L1->data);
        L1 = L1->next;
    }
    while (L2 != nullptr) {
        insert(lastPtrRef, L2->data);
        L2 = L2->next;
    }

    return result;
}

void printList(Node* n) {
    while (n != nullptr) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main() {
    Node* L1 = nullptr;
    Node* L2 = nullptr;

    insert(&L1, 5);
    insert(&L1, 3);
    insert(&L1, 2);

    insert(&L2, 4);
    insert(&L2, 3);
    insert(&L2, 1);

    cout << "Union of two single linked lists: ";
    Node* resultSingly = orderedUnionSingly(L1, L2);
    printList(resultSingly);

    return 0;
}