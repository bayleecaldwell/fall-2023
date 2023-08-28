#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int MAX_CANDIES = 1000; // Adjust this based on your requirements
const int NUM_MONTHS = 12;
const int NUM_REGIONS = 5;

struct CandySales {
    std::string candyName;
    int salesByRegion[NUM_REGIONS];
};

int main() {
    std::ifstream inputFile("wonka.txt");
    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::vector<CandySales> candies;
    std::string header;
    getline(inputFile, header); // Read and discard the header

    std::string month;
    while (inputFile >> month) {
        CandySales candy;
        candy.candyName = month;
        for (int i = 0; i < NUM_REGIONS; i++) {
            inputFile >> candy.salesByRegion[i];
        }
        candies.push_back(candy);
    }

    inputFile.close();

    // Task 1: Calculate total sales by region for each candy
    int totalSalesByRegion[MAX_CANDIES][NUM_REGIONS] = {0};
    for (int i = 0; i < candies.size(); i++) {
        for (int j = 0; j < NUM_REGIONS; j++) {
            totalSalesByRegion[i][j] = candies[i].salesByRegion[j];
        }
    }

    // Task 2: Display menu and show sales by world region for selected candy
    while (true) {
        std::cout << "Select a candy type:" << std::endl;
        for (int i = 0; i < candies.size(); i++) {
            std::cout << i + 1 << ". " << candies[i].candyName << std::endl;
        }
        std::cout << "0. Exit" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 0) {
            break;
        } else if (choice > 0 && choice <= candies.size()) {
            std::cout << "Sales by world region for " << candies[choice - 1].candyName << ":" << std::endl;
            std::cout << "Region\t\tNorth America\tSouth America\tAsia\tEurope\tAustralia/NZ" << std::endl;

            for (int j = 0; j < NUM_REGIONS; j++) {
                std::cout << j + 1 << ". ";
                std::cout << "\t" << candies[choice - 1].salesByRegion[j] << "\t\t";
            }
            std::cout << std::endl;
        } else {
            std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
    }

    return 0;
}
