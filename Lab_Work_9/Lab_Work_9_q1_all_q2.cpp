#include <iostream>
using namespace std;

struct TreeNode {
    int key;
    TreeNode* left, * right;

    TreeNode(int val) : key(val), left(nullptr), right(nullptr) {}
};

TreeNode* rightRotate(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

TreeNode* leftRotate(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

TreeNode* splay(TreeNode* root, int key) {
    if (root == nullptr || root->key == key)
        return root;

    if (key < root->key) {
        if (root->left == nullptr)
            return root;

        if (key < root->left->key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != nullptr)
                root->left = leftRotate(root->left);
        }

        return (root->left == nullptr) ? root : rightRotate(root);
    }
    else {
        if (root->right == nullptr)
            return root;

        if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        else if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != nullptr)
                root->right = rightRotate(root->right);
        }

        return (root->right == nullptr) ? root : leftRotate(root);
    }
}

TreeNode* bstSearch(TreeNode* root, int key) {
    return splay(root, key);
}

void preOrder(TreeNode* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

void postOrder(TreeNode* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}

TreeNode* subtree_max(TreeNode* subRoot) {
    while (subRoot && subRoot->right != nullptr)
        subRoot = subRoot->right;
    return subRoot;
}

TreeNode* subtree_min(TreeNode* subRoot) {
    while (subRoot && subRoot->left != nullptr)
        subRoot = subRoot->left;
    return subRoot;
}

int main() {
    TreeNode* root = new TreeNode(100);
    root->left = new TreeNode(50);
    root->right = new TreeNode(200);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(60);

    cout << "Original Tree (PreOrder): ";
    preOrder(root);
    cout << endl;

    cout << "Original Tree (InOrder): ";
    inOrder(root);
    cout << endl;

    cout << "Original Tree (PostOrder): ";
    postOrder(root);
    cout << endl;

    root = splay(root, 60);
    cout << "Tree After Splay (60 at Root, PreOrder): ";
    preOrder(root);
    cout << endl;

    cout << "Tree After Splay (60 at Root, InOrder): ";
    inOrder(root);
    cout << endl;

    cout << "Tree After Splay (60 at Root, PostOrder): ";
    postOrder(root);
    cout << endl;

    TreeNode* minNode = subtree_min(root);
    TreeNode* maxNode = subtree_max(root);

    cout << "Minimum Key: " << minNode->key << endl;
    cout << "Maximum Key: " << maxNode->key << endl;

    return 0;
}