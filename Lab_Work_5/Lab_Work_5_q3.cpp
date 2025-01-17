#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isPalindrome(const string& str);

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    cout << endl;

    if (isPalindrome(str)) {
        cout << str << " is a palindrome." << endl;
    }
    else {
        cout << str << " is not a palindrome." << endl;
    }

    return 0;
}

bool isPalindrome(const string& str) {
    stack<char> s;
    int len = str.length();

    for (int i = 0; i < len / 2; i++) {
        s.push(str[i]);
    }

    int start = (len % 2 == 0) ? len / 2 : (len / 2 + 1);

    for (int i = start; i < len; i++) {
        if (s.top() != str[i]) {
            return false;
        }
        s.pop();
    }

    return true;
}