#include <iostream>
using namespace std;

int sumRecursive(int m) {
    if (m == 1) return 1;
    return m + sumRecursive(m - 1);
}

int main() {
    int m;
    cout << "Enter the number: ";
    cin >> m;

    cout << "The sum of numbers from 1 to " << m << " is: " << sumRecursive(m) << endl;

    cout << "Time complexity: O(n)" << endl;
    return 0;
}