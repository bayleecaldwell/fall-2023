#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

namespace CandySalesApp {

    struct CandySales {
        string candy;
        double northAmerica;
        double southAmerica;
        double asia;
        double europe;
        double australia;
    };

    void displayTotalSales(const map<string, vector<CandySales>>& candySalesData) {
        cout << "Total Sales by Region and Candy:" << endl;

        for (const auto& entry : candySalesData) {
            const string& candy = entry.first;
            double totalNorthAmerica = 0.0;
            double totalSouthAmerica = 0.0;
            double totalAsia = 0.0;
            double totalEurope = 0.0;
            double totalAustralia = 0.0;

            for (const CandySales& sales : entry.second) {
                totalNorthAmerica += sales.northAmerica;
                totalSouthAmerica += sales.southAmerica;
                totalAsia += sales.asia;
                totalEurope += sales.europe;
                totalAustralia += sales.australia;
            }

            cout << candy << " - "
                    << "North America: " << totalNorthAmerica << ", "
                    << "South America: " << totalSouthAmerica << ", "
                    << "Asia: " << totalAsia << ", "
                    << "Europe: " << totalEurope << ", "
                    << "Australia: " << totalAustralia << endl;
        }
    }

    void displaySalesByRegion(const map<string, vector<CandySales>>& candySalesData) {
        cout << "\nSelect a candy type to display sales by world region:" << endl;

        int candyIndex = 1;
        map<int, string> candyIndexMap;

        for (const auto& entry : candySalesData) {
            cout << candyIndex << ". " << entry.first << endl;
            candyIndexMap[candyIndex] = entry.first;
            candyIndex++;
        }

        int selectedCandyIndex;
        cin >> selectedCandyIndex;

        if (candyIndexMap.find(selectedCandyIndex) != candyIndexMap.end()) {
            const string& selectedCandy = candyIndexMap[selectedCandyIndex];

            cout << "\nSales by World Region for " << selectedCandy << ":" << endl;

            for (const CandySales& sales : candySalesData.at(selectedCandy)) {
                cout << "Month: " << sales.candy << " | "
                        << "North America: " << sales.northAmerica << " | "
                        << "South America: " << sales.southAmerica << " | "
                        << "Asia: " << sales.asia << " | "
                        << "Europe: " << sales.europe << " | "
                        << "Australia: " << sales.australia << endl;
            }
        } else {
            cout << "Invalid candy selection." << endl;
        }
    }
}

int main() {
    ifstream inputFile("wonka.txt"); // Assuming your data is in a file named "wonka.txt"

    if (!inputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    using namespace CandySalesApp;

    map<string, vector<CandySales>> candySalesData;
    string line;

    // Read and process each line in the file
    while (getline(inputFile, line)) {
        istringstream iss(line);
        CandySales candySales;

        if (!(iss >> candySales.candy >> candySales.northAmerica >> candySales.southAmerica >>
                candySales.asia >> candySales.europe >> candySales.australia)) {
            cerr << "Error reading data from line: " << line << endl;
            continue;
        }

        candySalesData[candySales.candy].push_back(candySales);
    }

    displayTotalSales(candySalesData);
    displaySalesByRegion(candySalesData);

    inputFile.close();

    return 0;
}
