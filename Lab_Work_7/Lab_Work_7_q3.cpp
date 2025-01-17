#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insertBST(Node* root, int value) {
    if (!root) return new Node(value);

    if (value < root->data)
        root->left = insertBST(root->left, value);
    else
        root->right = insertBST(root->right, value);

    return root;
}

void preOrderBST(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preOrderBST(root->left);
    preOrderBST(root->right);
}

void inOrderBST(Node* root) {
    if (!root) return;
    inOrderBST(root->left);
    cout << root->data << " ";
    inOrderBST(root->right);
}

void postOrderBST(Node* root) {
    if (!root) return;
    postOrderBST(root->left);
    postOrderBST(root->right);
    cout << root->data << " ";
}

Node* treeFromBFS(int bfs[], int size) {
    if (size == 0) return nullptr;

    Node* root = new Node(bfs[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (i < size) {
        Node* current = q.front();
        q.pop();

        if (i < size) {
            current->left = new Node(bfs[i++]);
            q.push(current->left);
        }

        if (i < size) {
            current->right = new Node(bfs[i++]);
            q.push(current->right);
        }
    }
    return root;
}

void printBFS(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

int main() {
    int allOrderInput[] = { 10, 5, 1, 7, 40, 50 };
    int allOrderSize = sizeof(allOrderInput) / sizeof(allOrderInput[0]);

    int bfsInput[] = { 7, 4, 12, 3, 6, 8, 1, 5, 10 };
    int bfsSize = sizeof(bfsInput) / sizeof(bfsInput[0]);

    cout << "Building Tree for Pre-order, In-order, Post-order Inputs..." << endl;
    Node* allOrderRoot = nullptr;
    for (int i = 0; i < allOrderSize; i++) {
        allOrderRoot = insertBST(allOrderRoot, allOrderInput[i]);
    }

    cout << "Pre-order Sequence (Tree Traversal): ";
    preOrderBST(allOrderRoot);
    cout << endl;

    cout << "In-order Sequence (Tree Traversal): ";
    inOrderBST(allOrderRoot);
    cout << endl;

    cout << "Post-order Sequence (Tree Traversal): ";
    postOrderBST(allOrderRoot);
    cout << endl;

    cout << "Building Tree for BFS Input..." << endl;
    Node* bfsRoot = treeFromBFS(bfsInput, bfsSize);

    cout << "BFS Sequence (Tree Traversal): ";
    printBFS(bfsRoot);
    cout << endl;

    return 0;
}