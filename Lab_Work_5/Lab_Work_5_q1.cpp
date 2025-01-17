#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    stack<int> s;
    vector<int> elements = { 21, 22, 24, 25 };

    cout << "Check stack initial state: empty" << endl;

    cout << "\nAdd elements to stack: ";
    for (int elem : elements) {
        s.push(elem);
        cout << elem << " - ";
    }
    cout << "\b\b " << endl;

    cout << "\nShow stack element (print first in to last in):" << endl;
    for (int elem : elements) {
        cout << elem << " ";
    }
    cout << endl;

    cout << "\nShow stack element (print last in to first in):" << endl;
    stack<int> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    s.pop();
    s.pop();

    cout << "\nDelete last two elements from stack then show stack elements (print last in to first in):" << endl;
    temp = s;
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    return 0;
}