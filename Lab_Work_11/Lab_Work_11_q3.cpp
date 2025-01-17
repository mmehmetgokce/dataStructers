#include <iostream>
#include <map>
#include <string>

int main() {
    std::multimap<int, std::string> studentGrades;
    std::string studentName;
    int grade;

    while (true) {
        std::cout << "Enter student name (Enter 'q' to exit): ";
        std::getline(std::cin, studentName);

        if (studentName == "q") {
            break;
        }

        std::cout << "Enter your grade: ";
        std::cin >> grade;
        std::cin.ignore();

        studentGrades.insert({ grade, studentName });
    }

    int lowerLimit, upperLimit;
    std::cout << "Enter the grade range (lower limit and upper limit): ";
    std::cin >> lowerLimit >> upperLimit;

    std::cout << "Students with grades between " << lowerLimit << " and " << upperLimit << std::endl;
    for (const auto& registration : studentGrades) {
        if (registration.first >= lowerLimit && registration.first <= upperLimit) {
            std::cout << registration.second << " - " << registration.first << std::endl;
        }
    }

    return 0;
}