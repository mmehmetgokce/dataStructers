#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

int height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int key) {
    if (node == nullptr)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    if (height(node->left) - height(node->right) > 1) {
        if (key < node->left->key) {
            return rightRotate(node);
        }
        else {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (height(node->right) - height(node->left) > 1) {
        if (key > node->right->key) {
            return leftRotate(node);
        }
        else {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}

int getBalanceFactor(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

void showBalanceFactors(Node* root) {
    if (root != nullptr) {
        showBalanceFactors(root->left);
        cout << "Node: " << root->key << ", Balance Factor: " << getBalanceFactor(root) << endl;
        showBalanceFactors(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int choice, value;

    do {
        cout << "[1] Insert Element Into the Tree";
        cout << "\n[2] Show Balanced AVL Tree";
        cout << "\n[3] InOrder Traversal";
        cout << "\n[4] PreOrder Traversal";
        cout << "\n[5] PostOrder Traversal";
        cout << "\n[6] Show Balance Factors";
        cout << "\n[7] Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;
        case 2:
            cout << "Balanced AVL Tree (InOrder Traversal): ";
            inOrder(root);
            cout << endl;
            break;
        case 3:
            cout << "InOrder Traversal: ";
            inOrder(root);
            cout << endl;
            break;
        case 4:
            cout << "PreOrder Traversal: ";
            preOrder(root);
            cout << endl;
            break;
        case 5:
            cout << "PostOrder Traversal: ";
            postOrder(root);
            cout << endl;
            break;
        case 6:
            cout << "Balance Factors of Nodes:\n";
            showBalanceFactors(root);
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
        cout << "\n";
    } while (choice != 7);

    return 0;
}