#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
    int m = 125;
    int n = cbrt(m);

    clock_t start = clock();

    vector<vector<vector<int>>> array3D(n, vector<vector<int>>(n, vector<int>(n)));
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                array3D[i][j][k] = count++;
            }
        }
    }

    cout << "Elements in array: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cout << array3D[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

    cout << "Time: " << elapsed_time << " second" << endl;
    cout << "Complexity: O(n^3)" << endl;

    return 0;
}