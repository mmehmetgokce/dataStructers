#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
    int m = 100;
    int n = sqrt(m);

    clock_t start = clock();

    vector<vector<int>> array2D(n, vector<int>(n));
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            array2D[i][j] = count++;
        }
    }

    cout << "Elements in array: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << array2D[i][j] << " ";
        }
        cout << endl;
    }

    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

    cout << "Time: " << elapsed_time << " second" << endl;
    cout << "Complexity: O(n^2)" << endl;

    return 0;
}