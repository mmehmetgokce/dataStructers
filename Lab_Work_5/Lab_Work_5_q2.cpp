#include <iostream>
#include <stack>

using namespace std;

void sortStack(stack<int>& input);

int main() {
    std::stack<int> s;
    s.push(52);
    s.push(69);
    s.push(31);
    s.push(77);
    s.push(99);
    s.push(20);

    cout << "Original Stack: ";
    stack<int> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    sortStack(s);

    cout << "\nSorted Stack: ";
    temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    return 0;
}

void sortStack(stack<int>& input) {
    stack<int> tmpStack;

    while (!input.empty()) {
        int tmp = input.top();
        input.pop();

        while (!tmpStack.empty() && tmpStack.top() > tmp) {
            input.push(tmpStack.top());
            tmpStack.pop();
        }

        tmpStack.push(tmp);
    }

    while (!tmpStack.empty()) {
        input.push(tmpStack.top());
        tmpStack.pop();
    }
}