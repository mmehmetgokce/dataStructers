#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (!root) return createNode(data);
    if (data == 12) root->left = createNode(data);
    else if (data == 6) root->right = createNode(data);
    else if (data == 1) root->left->right = createNode(data);
    else if (data == 7) root->right->left = createNode(data);
    else if (data == 45) root->right->right = createNode(data);
    return root;
}

void preOrder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = nullptr;
    root = insertNode(root, 4);
    insertNode(root, 12);
    insertNode(root, 6);
    insertNode(root, 1);
    insertNode(root, 7);
    insertNode(root, 45);

    cout << "Pre-order Traversal: ";
    preOrder(root);
    cout << endl;

    cout << "In-order Traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postOrder(root);
    cout << endl;

    return 0;
}