#include <iostream>
using namespace std;

void printNumbers(int m) {
    if (m > 0) {
        printNumbers(m - 1);
        cout << m << " ";
    }
}

int main() {
    int m = 50;
    cout << "The natural numbers are: ";
    printNumbers(m);
    cout << endl;

    cout << "\nTime complexity: O(n)" << endl;
    return 0;
}