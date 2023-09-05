#include <iostream>

int* allocateIntArray(int number_elements) {
    if (number_elements <= 0) {
        return nullptr;
    }

    int* arr = new int[number_elements]; 

    return arr;
}

int main() {
    int number_elements;
    std::cout << "Enter the number of elements for the array: ";
    std::cin >> number_elements;

    int* dynamicArray = allocateIntArray(number_elements);

    if (dynamicArray != nullptr) {
        // Access and use the dynamically allocated array here

        // Don't forget to delete the dynamically allocated memory when done
        delete[] dynamicArray;
    } else {
        std::cout << "Invalid input for the number of elements." << std::endl;
    }

    return 0;
}
