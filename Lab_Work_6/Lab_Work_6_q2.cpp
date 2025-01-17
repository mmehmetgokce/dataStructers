#include <iostream>
#include <stack>
#include <queue>
#include <cctype>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main() {
    string str;
    cout << "Enter a text: ";
    std::getline(cin, str);

    if (isPalindrome(str)) {
        cout << "The text you entered is a palindrome!\n";
    }
    else {
        cout << "The text you entered is not a palindrome!\n";
    }
}

bool isPalindrome(string str) {
    queue<char> q;
    stack<char> s;

    for (char c : str) {
        if (isalnum(c)) {
            char lower = tolower(c);
            q.push(lower);
            s.push(lower);
        }
    }

    while (!q.empty()) {
        if (q.front() != s.top()) return false;
        q.pop();
        s.pop();
    }
    return true;
}