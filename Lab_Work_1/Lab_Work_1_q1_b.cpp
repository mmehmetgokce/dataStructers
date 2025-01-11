#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main() {
    int m = 50;

    clock_t start = clock();

    vector<int> array1D(m);
    for (int i = 0; i < m; i++) {
        array1D[i] = i;
    }

    cout << "Elements in array: ";
    for (int i = 0; i < m; i++) {
        cout << array1D[i] << " ";
    }
    cout << endl;

    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

    cout << "Time: " << elapsed_time << " second" << endl;
    cout << "Complexity: O(n)" << endl;

    return 0;
}