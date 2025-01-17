#include <iostream>
#include <set>
using namespace std;

void displayMenu() {
    cout << "--- Set Menu ---\n";
    cout << "1. Clear Screen\n";
    cout << "2. Insert\n";
    cout << "3. Erase\n";
    cout << "4. Update (first erase then insert)\n";
    cout << "5. Contains\n";
    cout << "6. Count\n";
    cout << "7. Find\n";
    cout << "8. Lower Bound\n";
    cout << "9. Upper Bound\n";
    cout << "10. Equal Range\n";
    cout << "11. Empty\n";
    cout << "12. Size\n";
    cout << "13. Clear\n";
    cout << "14. Merge (with defined set)\n";
    cout << "15. Show\n";
    cout << "0. Exit\n";
}

int main() {
    set<int> mySet;
    set<int> definedSet = { 10, 20, 30, 40 };
    int choice, value, oldValue, newValue;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            mySet.insert(value);
            cout << value << " inserted into the set.\n";
            break;
        case 3:
            cout << "Enter value to erase: ";
            cin >> value;
            mySet.erase(value);
            cout << value << " erased if it existed.\n";
            break;
        case 4: {
            cout << "Enter the value to update: ";
            cin >> oldValue;

            if (mySet.find(oldValue) != mySet.end()) {
                cout << "Enter the new value: ";
                cin >> newValue;

                mySet.erase(oldValue);
                mySet.insert(newValue);

                cout << "Value updated.\nUpdated Set: ";
                for (const int& x : mySet)
                    cout << x << " ";
                cout << "\n";
            }
            else {
                cout << "Error: Value " << oldValue << " not found in the set.\n";
            }
            break;
        }
        case 5:
            cout << "Enter value to check: ";
            cin >> value;
            cout << (mySet.count(value) ? "Value exists in the set.\n" : "Value not found.\n");
            break;
        case 6:
            cout << "Enter value to count: ";
            cin >> value;
            cout << "Count: " << mySet.count(value) << "\n";
            break;
        case 7:
            cout << "Enter value to find: ";
            cin >> value;
            if (mySet.find(value) != mySet.end())
                cout << "Value found in the set.\n";
            else
                cout << "Value not found.\n";
            break;
        case 8:
            cout << "Enter value for lower bound: ";
            cin >> value;
            if (mySet.lower_bound(value) != mySet.end())
                cout << "Lower Bound: " << *mySet.lower_bound(value) << "\n";
            else
                cout << "No lower bound found.\n";
            break;
        case 9:
            cout << "Enter value for upper bound: ";
            cin >> value;
            if (mySet.upper_bound(value) != mySet.end())
                cout << "Upper Bound: " << *mySet.upper_bound(value) << "\n";
            else
                cout << "No upper bound found.\n";
            break;
        case 10: {
            cout << "Enter value to find equal range: ";
            cin >> value;

            auto range = mySet.equal_range(value);

            cout << "Equal Range Results:\n";
            if (range.first != mySet.end()) {
                cout << "Lower Bound: " << *range.first << "\n";
            }
            else {
                cout << "Lower Bound not found.\n";
            }

            if (range.second != mySet.end()) {
                cout << "Upper Bound: " << *range.second << "\n";
            }
            else {
                cout << "Upper Bound not found.\n";
            }
            break;
        }
        case 11:
            cout << (mySet.empty() ? "Set is empty.\n" : "Set is not empty.\n");
            break;
        case 12:
            cout << "Size of the set: " << mySet.size() << "\n";
            break;
        case 13:
            mySet.clear();
            cout << "Set cleared.\n";
            break;
        case 14: {
            cout << "Merging original set with defined set...\n";
            mySet.insert(definedSet.begin(), definedSet.end());

            cout << "Merge completed. Original Set after merging:\n";
            for (const int& x : mySet)
                cout << x << " ";
            cout << "\n";
            break;
        }
        case 15:
            cout << "Set elements: ";
            for (int x : mySet) cout << x << " ";
            cout << "\n";
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
        cout << "\n";
    } while (choice != 0);

    return 0;
}