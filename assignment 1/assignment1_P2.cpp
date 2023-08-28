#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

const int NUM_CANDIES = 3; // Update this based on the actual number of candies
const int NUM_REGIONS = 5; // Update this based on the actual number of regions
const int NUM_MONTHS = 12;

// Function to get the index of a candy type
int getCandyIndex(const std::string &candyName, const std::vector<std::string> &candies) {
    for (int i = 0; i < candies.size(); ++i) {
        if (candies[i] == candyName) {
            return i;
        }
    }
    return -1; // Candy not found
}

int main() {
    std::ifstream inputFile("wonka.txt"); // Update the file name accordingly
    
    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }
    
    std::vector<std::string> candies;
    double totalSales[NUM_CANDIES][NUM_REGIONS] = {0};

    // Read and store candy names from the first line
    std::string headers;
    std::getline(inputFile, headers);
    std::istringstream headerStream(headers);
    std::string header;
    headerStream >> header; // Ignore "Month" header

    for (int i = 0; i < NUM_CANDIES; ++i) {
        headerStream >> header;
        candies.push_back(header);
    }

    // Process the data
    std::string month;
    double sales;
    std::string candyName;

    while (inputFile >> month) {
        for (int i = 0; i < NUM_CANDIES; ++i) {
            inputFile >> sales;
            for (int j = 0; j < NUM_REGIONS; ++j) {
                totalSales[i][j] += sales;
            }
        }
    }

    // Task 1: Display total sales for the year in each region by type of candy
    std::cout << "Total Sales by Candy Type and Region:\n\n";
    std::cout << "Region\t";
    for (std::vector<std::string>::const_iterator it = candies.begin(); it != candies.end(); ++it) {
    const std::string &candy = *it;
    std::cout << candy << "\t";
    }

    std::cout << "Total\n";

    for (int j = 0; j < NUM_REGIONS; ++j) {
        std::cout << "Region " << j + 1 << "\t";
        double regionTotal = 0;

        for (int i = 0; i < NUM_CANDIES; ++i) {
            std::cout << totalSales[i][j] << "\t";
            regionTotal += totalSales[i][j];
        }
        std::cout << regionTotal << "\n";
    }

    // Task 2: Provide a menu for selecting a candy type and displaying sales by region
    while (true) {
        std::cout << "\nSelect a candy type (0-" << NUM_CANDIES - 1 << ") or -1 to exit: ";
        int selectedCandy;
        std::cin >> selectedCandy;

        if (selectedCandy == -1) {
            break;
        }

        if (selectedCandy >= 0 && selectedCandy < NUM_CANDIES) {
            candyName = candies[selectedCandy];
            int candyIndex = getCandyIndex(candyName, candies);

            std::cout << "\nSales by Region for " << candyName << ":\n";
            std::cout << "Region\tSales\n";
            
            for (int j = 0; j < NUM_REGIONS; ++j) {
                std::cout << "Region " << j + 1 << "\t" << totalSales[candyIndex][j] << "\n";
            }
        } else {
            std::cout << "Invalid candy selection. Please try again.\n";
        }
    }

    return 0;
}
