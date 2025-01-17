#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* left;
    Node* right;

    Node(string val) : data(val), left(nullptr), right(nullptr) {}
};

bool areIdentical(Node* root1, Node* root2) {
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;

    return (root1->data == root2->data &&
        areIdentical(root1->left, root2->left) &&
        areIdentical(root1->right, root2->right));
}

bool isSubtree(Node* mainTree, Node* subTree) {
    if (subTree == nullptr)
        return true;
    if (mainTree == nullptr)
        return false;

    if (areIdentical(mainTree, subTree))
        return true;

    return isSubtree(mainTree->left, subTree) || isSubtree(mainTree->right, subTree);
}

int main() {
    Node* mainTree = new Node("Bucharest");
    mainTree->left = new Node("Pitesti");
    mainTree->right = new Node("Fagaras");
    mainTree->left->left = new Node("Rimnicu-Vilcea");
    mainTree->left->right = new Node("Sibiu");
    mainTree->right->left = new Node("Urziceni");
    mainTree->right->right = new Node("Vaslui");

    Node* subTree = new Node("Pitesti");
    subTree->left = new Node("Rimnicu-Vilcea");
    subTree->right = new Node("Sibiu");

    cout << "Checking subtree...\n\n";
    if (isSubtree(mainTree, subTree))
        cout << "This tree is a subtree of the main tree.\n";
    else
        cout << "This tree is not a subtree of the main tree.\n";

    return 0;
}