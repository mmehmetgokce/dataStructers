#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> arr(5);

    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }

    cout << "Size of vector is: " << arr.size() << endl;
    cout << "Vector elements: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> originalArr = arr;

    arr.insert(arr.begin(), 0);
    cout << "Size of updated vector is: " << arr.size() << endl;
    cout << "Updated vector elements: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Updated vector in reverse order: ";
    for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    arr.erase(arr.begin());

    cout << "Updated vector in reverse order after removing the first element: ";
    for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}