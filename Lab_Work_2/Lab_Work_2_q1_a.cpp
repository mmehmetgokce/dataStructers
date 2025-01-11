#include <iostream>
using namespace std;

int main() {
    int m;
    cout << "Enter a number: ";
    cin >> m;

    for (int i = m; i >= 0; i--) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Time complexity: O(n)" << endl;
    return 0;
}