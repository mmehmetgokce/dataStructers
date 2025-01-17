#include "ThreadedBST.h"

///-----------------------------------------------
/// Erases all nodes in the tree
/// 
void ThreadedBST::eraseTreeNodes(BSTNode* node) {
    BSTNode* curr = this->min(); // Start from the smallest node in the tree

    while (curr != NULL) { // Traverse all nodes
        BSTNode* n = this->next(curr); // Move to the next node
        delete curr; // Delete the current node
        curr = n; // Move to the next node
    }
} //end-eraseTreeNodes

///-----------------------------------------------
/// Adds a given key to the BST
///
void ThreadedBST::add(int key) {
    BSTNode* ptr = root; // Start from the root of the tree
    BSTNode* parent = NULL; // Parent node initially set to NULL

    while (ptr) { // Continue until the appropriate position in the tree is found
        BSTNode* newNode = new BSTNode(key); // Create a new node

        if (root == NULL) { // If the root is empty
            root = newNode; // Assign the new node as the root
            return; // End the operation
        }

        parent = ptr; // Set the current node as the parent

        if (key < ptr->key) { // If the key is smaller than the current node's key
            if (ptr->leftLinkType == CHILD) // If the left link points to a child node
                ptr = ptr->left; // Move left
            else
                break; // Exit the loop
        }
        else { // If the key is greater or equal
            if (ptr->rightLinkType == CHILD) // If the right link points to a child node
                ptr = ptr->right; // Move right
            else
                break; // Exit the loop
        }
    }

    if (root == NULL) { // If the root is still empty (this check is unnecessary because the above block already covers this case)
        BSTNode* newNode = new BSTNode(key); // Create a new node
        root = newNode; // Assign the new node as the root
    }
    else if (key < parent->key) { // If the key is smaller than the parent's key
        BSTNode* newNode = new BSTNode(key); // Create a new node

        newNode->left = parent->left; // Connect the new node's left link to the parent's left link
        newNode->right = parent; // Connect the new node's right link to the parent node
        parent->leftLinkType = CHILD; // Change the parent's left link type to child
        parent->left = newNode; // Connect the parent's left link to the new node
    }
    else { // If the key is larger
        BSTNode* newNode = new BSTNode(key); // Create a new node

        newNode->right = parent->right; // Connect the new node's right link to the parent's right link
        newNode->left = parent; // Connect the new node's left link to the parent node
        parent->rightLinkType = CHILD; // Change the parent's right link type to child
        parent->right = newNode; // Connect the parent's right link to the new node
    }
} // end-add

///-----------------------------------------------
/// Removes a given key from the BST (if it exists)
///
void ThreadedBST::remove(int key) {
    BSTNode* parent = nullptr; // Initial value for the parent node
    BSTNode* child = root; // Search starts from the root

    while (child != nullptr) { // Continue until the key is found
        if (key == child->key) // If the key is found
            break; // Exit the loop

        parent = child; // Set the current node as the parent

        if (key < child->key) { // If the searched key is smaller than the current node
            if (child->leftLinkType == CHILD) // If the left link points to a child node
                child = child->left; // Move left
            else
                break; // Exit the loop
        }
        else { // If the searched key is larger
            if (child->rightLinkType == CHILD) // If the right link points to a child node
                child = child->right; // Move right
            else
                break; // Exit the loop
        }
    }

    BSTNode* current = child; // Set the node to be deleted

    if (child->rightLinkType == CHILD && child->leftLinkType == CHILD) { // If the node has both left and right children
        parent = child; // Set the parent node
        current = child->left; // Move to the left subtree

        while (current->rightLinkType == CHILD) { // Find the largest node on the right
            parent = current;
            current = current->right;
        }

        child->key = current->key; // Swap the keys
    }

    BSTNode* max = nullptr; // Variable for the maximum node in the right subtree
    BSTNode* min = nullptr; // Variable for the minimum node in the left subtree

    if (parent->key >= current->key) { // If the parent's key is greater than or equal to the current node's key
        if (current->rightLinkType == THREAD && current->leftLinkType == THREAD) { // If the node has no left or right children
            parent->left = current->left; // Connect the parent's left link to the current node's left
            parent->leftLinkType = THREAD; // Mark the left link as a thread
        }
        else if (current->rightLinkType == THREAD) { // If the right link is a thread
            max = current->left; // Move left to find the largest node on the right

            while (max->rightLinkType == CHILD) { // Continue while there are children on the right
                max = max->right;
            }

            max->right = parent; // Connect the maximum node's right link to the parent node
            parent->left = current->left; // Connect the parent's left link to the current node's left
        }
        else { // If the left link is a thread
            min = current->right; // Move right to find the smallest node on the left

            while (min->leftLinkType == CHILD) { // Continue while there are children on the left
                min = min->left;
            }

            min->left = current->left; // Connect the minimum node's left link to the current node's left
            parent->left = current->right; // Connect the parent's left link to the current node's right
        }

        delete current; // Delete the current node
    }
    else { // If the parent's key is smaller than the current node's key
        if (current->rightLinkType == THREAD && current->leftLinkType == THREAD) { // If the node has no children
            parent->right = current->right; // Connect the parent's right link to the current node's right
            parent->rightLinkType = THREAD; // Mark the right link as a thread
        }
        else if (current->rightLinkType == THREAD) { // If the right link is a thread
            max = current->left; // Move left to find the largest node on the right

            while (max->rightLinkType == CHILD) { // Continue while there are children on the right
                max = max->right;
            }

            max->right = current->right; // Connect the maximum node's right link to the current node's right
            parent->right = current->left; // Connect the parent's right link to the current node's left
        }
        else { // If the left link is a thread
            min = current->right; // Move right to find the smallest node on the left

            while (min->leftLinkType == CHILD) { // Continue while there are children on the left
                min = min->left;
            }

            min->left = parent; // Connect the minimum node's left link to the parent node
            parent->right = current->right; // Connect the parent's right link to the current node's right
        }

        delete current; // Delete the current node
    }
} // end-remove

///-----------------------------------------------
/// Searches a given key in the ThreadedBST
/// Return a pointer to the node that holds the key
/// If the key is not found, return NULL
/// 
BSTNode* ThreadedBST::find(int key) {
    BSTNode* temp = root; // Search for the key starting from the root
    while (temp != NULL) { // Iterate until reaching the end of the tree
        if (key == temp->key) { // If the key is found
            return temp; // Return the node
        }
        if (key < temp->key) { // If the key is smaller than the current node
            temp = temp->left; // Move left
        }
        else { // If the key is larger
            temp = temp->right; // Move right
        }
    }
    return NULL; // Return NULL if the key is not found
} // end-find

///-----------------------------------------------
/// Returns the minimum key in the ThreadedBST
/// Return a pointer to the node that holds the key
/// If the key is not found, return NULL
/// 
BSTNode* ThreadedBST::min() {
    BSTNode* node = root; // Start from the root node
    if (node == nullptr) // If the tree is empty
        return nullptr; // Return NULL
    while (node->left != NULL) { // Traverse the left subtree
        node = node->left;
    }
    return node; // Return the smallest node
} // end-min

///-----------------------------------------------
/// Returns the maximum key in the ThreadedBST
/// Return a pointer to the node that holds the key
/// If the key is not found, return NULL
///
BSTNode* ThreadedBST::max() {
    BSTNode* node = root; // Start from the root node
    if (node == nullptr) // If the tree is empty
        return nullptr; // Return NULL
    while (node->right != NULL) { // Traverse the right subtree
        node = node->right;
    }
    return node; // Return the largest node
} // end-max

///-----------------------------------------------
/// Given a valid pointer to a node in ThreadedBST,
/// returns a pointer to the node that contains the inorder predecessor
/// If the inorder predecessor does not exist, returns NULL
///
BSTNode* ThreadedBST::previous(BSTNode* node) {
    if (node == NULL) { // If the node is NULL
        return NULL; // Return NULL
    }
    if (node->leftLinkType == THREAD) // If the left link is a thread
        return node->left; // Return the left node

    BSTNode* temp = node->left; // Move to the left subtree

    while (temp->rightLinkType == CHILD) { // Find the largest node on the right
        temp = temp->right;
    }

    return temp; // Return the found node
} // end-previous

///-----------------------------------------------
/// Given a valid pointer to a node in the ThreadedBST,
/// returns a pointer to the node that contains the inorder successor
/// If the inorder successor does not exist, returns NULL
/// 
BSTNode* ThreadedBST::next(BSTNode* node) {
    if (node == NULL) { // If the node is NULL
        return NULL; // Return NULL
    }
    if (node->rightLinkType == THREAD) { // If the right link is a thread
        return node->right; // Return the right node
    }
    else { // If the right link is a child
        node = node->right; // Move to the right subtree
        while (node->leftLinkType == CHILD) { // Find the smallest node on the left
            node = node->left;
        }
    }

    return node; // Return the found node
} // end-next