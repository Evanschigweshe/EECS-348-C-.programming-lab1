#include <iostream>
#include <fstream>
#include <iomanip> // Include the <iomanip> header for setw()

const int MAX_SIZE = 10; // Maximum size of the matrix

// Function to read matrix data from a file
void readMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int& size, const std::string& filename) {
    std::ifstream file(filename); // Open the file
    if (file.is_open()) { // Checking if the file is open
        file >> size; // Reads the size of matrices
        // Reads the elements of the first matrix
        for (int i = 0; i < size; ++i) {           
            for (int j = 0; j < size; ++j) {
                file >> matrix1[i][j];
            }
        }
        // Reads the elements of the second matrix
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                file >> matrix2[i][j];
            }
        }
        file.close(); // Closes the file after reading
    } else {                                         // If the file cannot be opened/If the user enters a wrong file name
        std::cout << "Unable to open file: " << filename << std::endl;  // Displays a message to inform the user
        exit(1); // Exits the program with the message
    }
}


// Function to print a matrix
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {      // Loops through each row of the matrix
    for (int i = 0; i < size; ++i) {   // Loops through each column of the current row
        for (int j = 0; j < size; ++j)
            std::cout << std::setw(5) << matrix[i][j]; // Prints the element at current row and column with a width of 5 spaces
        std::cout << std::endl;  // Moves to the next line after printing each row
    }
}

// Function to add two matrices
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) // Iterates over rows
        for (int j = 0; j < size; ++j) // Iterates over columns
            result[i][j] = matrix1[i][j] + matrix2[i][j]; //Adds corresponding elements from matrix1 and matrix2 and store the result in result matrix
}

// Function to multiply two matrices
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {  // Loops through rows of the first matrix
        for (int j = 0; j < size; ++j) { // Loops through columns of the second matrix
            result[i][j] = 0;  // Initializes result element at position (i, j) to 0
            for (int k = 0; k < size; ++k)  // Loops through corresponding elements in rows and columns to calculate the dot product
                result[i][j] += matrix1[i][k] * matrix2[k][j]; // Adds the product of corresponding elements
        }
    }
}

// Function to subtract one matrix from another
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) // Loops through each row of the matrices
        for (int j = 0; j < size; ++j) // Loops through each column of the matrices
            result[i][j] = matrix1[i][j] - matrix2[i][j]; // Subtracts corresponding elements of matrix1 and matrix2 and store the result in result matrix
}

// Function to update an element of the first matrix
void updateElement(int matrix[MAX_SIZE][MAX_SIZE], int row, int col, int value, int size) {
    if (row >= 0 && row < size && col >= 0 && col < size) // Checks if the row and column indices are within bounds
        matrix[row][col] = value; // If indices are valid, update the element with the new value
    else
        std::cout << "Invalid row or column index." << std::endl; // If indices are out of bounds, display an error message
}

// Function to find the max value of the first matrix
int getMaxValue(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int maxVal = matrix[0][0]; // Initializes maxVal with the value at the top-left corner of the matrix at position(0,0)
    for (int i = 0; i < size; ++i) // Loops through each element of the matrix
        for (int j = 0; j < size; ++j)
            if (matrix[i][j] > maxVal) // Checks if the current element is greater than the current maxVal
                maxVal = matrix[i][j]; // If so, update maxVal to the value of the current element
    return maxVal; // Returns the maximum value found in the matrix
}

// Function to transpose a matrix
void transposeMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) // Iterates over rows
        for (int j = 0; j < size; ++j) // Iterates over columns
            transposed[i][j] = matrix[j][i]; // Assign the value at current position (i,j) in the transposed matrix to the value at position (j,i) in the original matrix
}


int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE], size;

    // Read the matrices from the file
    readMatrices(matrix1, matrix2, size, "matrix_input.txt");

// Displays Matrix 1
    std::cout << "Matrix 1:" << std::endl;
    printMatrix(matrix1, size);
    std::cout << std::endl;

// Displays Matrix 2
    std::cout << "Matrix 2:" << std::endl;
    printMatrix(matrix2, size);
    std::cout << std::endl;

// Displays the sum of Matrix 1 and Matrix 2
    std::cout << "Matrix 1 + Matrix 2:" << std::endl;
    addMatrices(matrix1, matrix2, result, size);
    printMatrix(result, size);
    std::cout << std::endl;

// Displays the product of Matrix 1 and Matrix 2
    std::cout << "Matrix 1 * Matrix 2:" << std::endl;
    multiplyMatrices(matrix1, matrix2, result, size);
    printMatrix(result, size);
    std::cout << std::endl;

// Displays the difference of Matrix 1 and Matrix 2
    std::cout << "Matrix 1 - Matrix 2:" << std::endl;
    subtractMatrices(matrix1, matrix2, result, size);
    printMatrix(result, size);
    std::cout << std::endl;

// Updates an element in Matrix 1
    updateElement(matrix1, 1, 1, 99, size);
    std::cout << "Matrix 1 after updating element (1,1) with 99:" << std::endl;
    printMatrix(matrix1, size);
    std::cout << std::endl;

// Displays the maximum value in Matrix 1
    std::cout << "Maximum value of Matrix 1: " << getMaxValue(matrix1, size) << std::endl;
    std::cout << std::endl;

// Transpose Matrix 1 and display the result
    int transposedMatrix[MAX_SIZE][MAX_SIZE];
    transposeMatrix(matrix1, transposedMatrix, size);
    std::cout << "Transpose of Matrix 1:" << std::endl;
    printMatrix(transposedMatrix, size);

    return 0;
}