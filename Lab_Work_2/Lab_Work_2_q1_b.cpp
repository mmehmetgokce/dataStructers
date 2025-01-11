#include <iostream>
using namespace std;

int main() {
    int m, sum = 0;
    cout << "Enter the number of consecutive positive integers (starting from 1): ";
    cin >> m;

    int i = 1;
    while (i <= m) {
        sum += i;
        i++;
    }
    cout << "The sum is: " << sum << endl;

    cout << "Time complexity: O(n)" << endl;
    return 0;
}