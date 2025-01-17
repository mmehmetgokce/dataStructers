#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Structure to define points in the matrix, including blob number and character value
struct Point {
    int blobNumber; // Blob number assigned to the point
    char value;     // Character value of the point (e.g., part of a blob or empty space)
};

// Matrix to store the grid and blob information
vector<vector<Point>> matrix;
int maxBlob = 0; // Maximum number of blobs found
int rows = 0;   // Number of rows in the matrix
int columns = 0; // Number of columns in the matrix

// Function to print the matrix to the console
void printMatrix() {
    cout << "  ";
    for (int j = 0; j < columns; j++) cout << j % 10; // Print column indices
    cout << "\n +";
    for (int j = 0; j < columns; j++) cout << "-"; // Print top border
    cout << "+\n";

    for (int i = 0; i < rows; i++) {
        cout << i % 10 << "|"; // Print row index
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j].value; // Print the matrix content
        }
        cout << "|" << i % 10 << endl; // Print row border
    }

    cout << " +";
    for (int j = 0; j < columns; j++) cout << "-"; // Print bottom border
    cout << "+\n  ";
    for (int j = 0; j < columns; j++) cout << j % 10; // Print column indices
    cout << endl;
}

// Function to fill a cell and its connected cells with a blob number
void fillCell(int r, int c, int blobNo) {
    if (r < 0 || r >= rows || c < 0 || c >= columns || blobNo == 0) return; // Check bounds and blob number
    if (matrix[r][c].value != ' ' && matrix[r][c].blobNumber == 0) { // If cell is part of a blob and not yet visited
        matrix[r][c].blobNumber = blobNo; // Assign blob number to the cell
        fillCell(r + 1, c, blobNo);  // Recursively fill down
        fillCell(r - 1, c, blobNo);  // Recursively fill up
        fillCell(r, c + 1, blobNo);  // Recursively fill right
        fillCell(r, c - 1, blobNo);  // Recursively fill left
    }
}

// Function to find all blobs in the matrix
void findBlobs() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (matrix[i][j].value != ' ' && matrix[i][j].blobNumber == 0) { // If cell is part of a new blob
                maxBlob++; // Increment blob count
                fillCell(i, j, maxBlob); // Fill the blob starting from this cell
            }
        }
    }
}

int main() {

    // Read the file name from the user
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream file(filename); // Open the file
    string line;

    if (file.is_open()) { // If file is successfully opened
        file >> rows >> columns; // Read the number of rows and columns
        file.ignore(); // Ignore the newline character

        matrix.resize(rows, vector<Point>(columns)); // Resize the matrix to match dimensions

        // Read each line from the file and populate the matrix
        for (int i = 0; i < rows; i++) {
            getline(file, line);
            for (int j = 0; j < columns; j++) {
                matrix[i][j].value = line[j]; // Set the character value
                matrix[i][j].blobNumber = 0;  // Initialize blob number to 0
            }
        }
        file.close(); // Close the file
    }
    else {
        cout << "Error: Could not open the file." << endl; // Print error if file cannot be opened
    }

    // Print the matrix to the console
    printMatrix();

    // Find and label blobs in the matrix
    findBlobs();

    // Print blob information: blob number, number of pixels, and center of mass (CoM)
    cout << "\n+------+------------+---------+------------+\n";
    cout << "| BLOB | NoOfPixels | CoM Row | CoM Column |\n";
    cout << "+------+------------+---------+------------+\n";

    // Calculate and display blob details for each blob
    for (int blobNo = 1; blobNo <= maxBlob; blobNo++) {
        int pixelCount = 0;
        double sumRow = 0, sumCol = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j].blobNumber == blobNo) { // If the cell belongs to the current blob
                    pixelCount++; // Increment pixel count
                    sumRow += i; // Accumulate row indices
                    sumCol += j; // Accumulate column indices
                }
            }
        }

        if (pixelCount > 0) { // If the blob has pixels
            double comRow = sumRow / pixelCount; // Calculate center of mass row
            double comCol = sumCol / pixelCount; // Calculate center of mass column
            printf("| %4d | %10d | %7.2f | %10.2f |\n", blobNo, pixelCount, comRow, comCol);
        }
    }

    cout << "+------+------------+---------+------------+\n";

    return 0;
}