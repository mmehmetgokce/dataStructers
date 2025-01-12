#include <iostream>
#include <vector>
using namespace std;

void displayVector(const vector<int>& vec);
void bubbleSort(vector<int>& vec);
void insertionSort(vector<int>& vec);

int main() {
    int size = 5;
    vector<int> vec;

    for (int i = 1; i <= size; ++i) {
        vec.push_back(i);
    }

    cout << "Size of vector is: " << vec.size() << endl;
    cout << "Vector elements: ";
    displayVector(vec);

    int value1 = 0;
    cout << "\nValue to be added: " << value1 << endl;
    vec.insert(vec.begin(), value1);
    cout << "Added to begin of the array" << endl;
    displayVector(vec);

    int value2 = 6;
    cout << "\nValue to be added: " << value2 << endl;
    vec.push_back(value2);
    cout << "Added to end of the array" << endl;
    displayVector(vec);

    vector<int> bubbleSortedVec = vec;
    bubbleSort(bubbleSortedVec);
    cout << "\nBubble Sorted Element List\n";
    displayVector(bubbleSortedVec);

    vector<int> insertionSortedVec = vec;
    insertionSort(insertionSortedVec);
    cout << "\nInsertion Sorted Element List\n";
    displayVector(insertionSortedVec);

    return 0;
}

void displayVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

void insertionSort(vector<int>& vec) {
    int n = vec.size();
    for (int i = 1; i < n; i++) {
        int key = vec[i];
        int j = i - 1;

        while (j >= 0 && vec[j] < key) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
    }
}