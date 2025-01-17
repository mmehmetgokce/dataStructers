#include <iostream>
#include <string>
using namespace std;

struct Node {
    string city;
    int time;
    Node* left;
    Node* right;

    Node(string c, int t) : city(c), time(t), left(nullptr), right(nullptr) {}
};

class BSTforCity {
private:
    Node* root;

    Node* insert(Node* node, string city, int time) {
        if (node == nullptr)
            return new Node(city, time);

        if (time < node->time)
            node->left = insert(node->left, city, time);
        else
            node->right = insert(node->right, city, time);

        return node;
    }

    void inorderTraversal(Node* node) {
        if (node == nullptr) return;

        inorderTraversal(node->left);
        cout << node->city << " (" << node->time << ") -> ";
        inorderTraversal(node->right);
    }

public:
    BSTforCity() : root(nullptr) {}

    void insertCity(string city, int time) {
        root = insert(root, city, time);
    }

    void printDeliveryOrderForInput1() {
        cout << "Delivery order of cities for input 1: ";
        inorderTraversal(root);
        cout << "End\n\n";
    }

    void printDeliveryOrderForInput2() {
        cout << "Delivery order of cities for input 1: ";
        inorderTraversal(root);
        cout << "End\n";
    }
};

int main() {
    BSTforCity deliveryTreeForInput1;
    BSTforCity deliveryTreeForInput2;

    deliveryTreeForInput1.insertCity("Rimnicu-Vilcea", 2);
    deliveryTreeForInput1.insertCity("Pitesti", 3);
    deliveryTreeForInput1.insertCity("Sibiu", 4);
    deliveryTreeForInput1.insertCity("Bucharest", 5);
    deliveryTreeForInput1.insertCity("Urziceni", 6);
    deliveryTreeForInput1.insertCity("Fagaras", 7);
    deliveryTreeForInput1.insertCity("Vaslui", 8);

    deliveryTreeForInput2.insertCity("Bucharest", 5);
    deliveryTreeForInput2.insertCity("Fagaras", 7);
    deliveryTreeForInput2.insertCity("Vaslui", 8);
    deliveryTreeForInput2.insertCity("Neamt", 9);

    deliveryTreeForInput1.printDeliveryOrderForInput1();
    deliveryTreeForInput2.printDeliveryOrderForInput2();

    return 0;
}