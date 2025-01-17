#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    std::unordered_multiset<int> borrowedBooks;
    std::string bookName;
    int barcode;

    while (true) {
        std::cout << "Enter the book title (Enter 'q' to exit): ";
        std::getline(std::cin, bookName);

        if (bookName == "q") {
            break;
        }

        std::cout << "Enter the barcode number: ";
        std::cin >> barcode;
        std::cin.ignore();

        borrowedBooks.insert(barcode);
    }

    std::cout << "Enter the barcode number of the book you want to learn: ";
    std::cin >> barcode;

    int count = borrowedBooks.count(barcode);

    std::cout << "The book with barcode number " << barcode << " has been borrowed " << count << " times." << std::endl;

    return 0;
}