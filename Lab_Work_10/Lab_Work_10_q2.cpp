#include <iostream>
#include <map>
using namespace std;

void displayMenu() {
    cout << "--- Map Menu ---\n";
    cout << "1. Clear Screen\n";
    cout << "2. Insert\n";
    cout << "3. Erase\n";
    cout << "4. Update\n";
    cout << "5. Contains\n";
    cout << "6. Count\n";
    cout << "7. Find\n";
    cout << "8. Lower Bound\n";
    cout << "9. Upper Bound\n";
    cout << "10. Equal Range\n";
    cout << "11. Empty\n";
    cout << "12. Size\n";
    cout << "13. Clear\n";
    cout << "14. Merge (with defined map)\n";
    cout << "15. Show\n";
    cout << "0. Exit\n";
}

// Ana program
int main() {
    map<int, int> myMap;
    map<int, int> definedMap = { {1, 10}, {2, 20}, {3, 30}, {4, 40} };
    int choice, key, value;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            break;
        case 2:
            cout << "Enter key and value to insert: ";
            cin >> key >> value;
            myMap[key] = value;
            cout << "Inserted (" << key << ", " << value << ") into the map.\n";
            break;
        case 3:
            cout << "Enter key to erase: ";
            cin >> key;
            myMap.erase(key);
            cout << "Key " << key << " erased if it existed.\n";
            break;
        case 4:
            cout << "Enter the key you want to update and the new value: ";
            cin >> key >> value;
            myMap[key] = value;
            cout << "Updated (" << key << ", " << value << ").\n";
            break;
        case 5:
            cout << "Enter key to check: ";
            cin >> key;
            cout << (myMap.count(key) ? "Key exists in the map.\n" : "Key not found.\n");
            break;
        case 6:
            cout << "Enter key to count: ";
            cin >> key;
            cout << "Count: " << myMap.count(key) << "\n";
            break;
        case 7:
            cout << "Enter key to find: ";
            cin >> key;
            if (myMap.find(key) != myMap.end())
                cout << "Key " << key << " found with value " << myMap[key] << ".\n";
            else
                cout << "Key not found.\n";
            break;
        case 8:
            cout << "Enter key for lower bound: ";
            cin >> key;
            if (myMap.lower_bound(key) != myMap.end())
                cout << "Lower Bound: (" << myMap.lower_bound(key)->first << ", "
                << myMap.lower_bound(key)->second << ")\n";
            else
                cout << "No lower bound found.\n";
            break;
        case 9:
            cout << "Enter key for upper bound: ";
            cin >> key;
            if (myMap.upper_bound(key) != myMap.end())
                cout << "Upper Bound: (" << myMap.upper_bound(key)->first << ", "
                << myMap.upper_bound(key)->second << ")\n";
            else
                cout << "No upper bound found.\n";
            break;
        case 10: {
            cout << "Enter key to find equal range: ";
            cin >> key;

            auto range = myMap.equal_range(key);

            cout << "Equal Range Results:\n";
            if (range.first != myMap.end()) {
                cout << "Lower Bound: " << "(" << range.first->first << ", " << range.first->second << ")" << "\n";
            }
            else {
                cout << "Lower Bound not found.\n";
            }

            if (range.second != myMap.end()) {
                cout << "Upper Bound: " << "(" << range.second->first << ", " << range.second->second << ")" << "\n";
            }
            else {
                cout << "Upper Bound not found.\n";
            }
            break;
        }
        case 11:
            cout << (myMap.empty() ? "Map is empty.\n" : "Map is not empty.\n");
            break;
        case 12:
            cout << "Size of the map: " << myMap.size() << "\n";
            break;
        case 13:
            myMap.clear();
            cout << "Map cleared.\n";
            break;
        case 14: {
            cout << "Merging original map with defined map...\n";
            for (const auto& pair : definedMap)
                myMap.insert(pair);

            cout << "Merge completed. Original Map after merging:\n";
            for (const auto& pair : myMap)
                cout << "(" << pair.first << ", " << pair.second << ")\n";
            break;
        }
        case 15:
            cout << "Map elements:\n";
            for (auto& pair : myMap)
                cout << "(" << pair.first << ", " << pair.second << ")\n";
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