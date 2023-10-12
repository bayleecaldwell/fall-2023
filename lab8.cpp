#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream> 
using namespace std;


struct ProductSales {
    int productNumber;
    int units;
    double price;
    double sales; 
};

// Function prototypes
void readDataFromFile(vector<ProductSales> &salesData);
void sortTheData(vector<ProductSales> &salesData);
void displaySales(const vector<ProductSales> &salesData); 
void showTotals(const vector<ProductSales> &salesData);    

int main() {
    vector<ProductSales> mySalesData;
    readDataFromFile(mySalesData);
    sortTheData(mySalesData);
    displaySales(mySalesData);
    showTotals(mySalesData);
    return 0;
}

void readDataFromFile(vector<ProductSales> &salesData) {
    const string DATAFILE = "lab08data.txt";
    ifstream dfile(DATAFILE); 

    if (!dfile.is_open()) {
        cerr << "Error: Unable to open data file" << endl;
        exit(1);
    }

    ProductSales oneRowOfSales;

    while (dfile >> oneRowOfSales.productNumber >> oneRowOfSales.units >> oneRowOfSales.price) {
        oneRowOfSales.sales = oneRowOfSales.units * oneRowOfSales.price;
        salesData.push_back(oneRowOfSales);
    }

    dfile.close();
}

void sortTheData(vector<ProductSales> &salesData) {
    int size = salesData.size();
    for (int startScan = 0; startScan < (size - 1); startScan++) {
        int maxIndex = startScan;
        double maxValue = salesData[startScan].sales;
        for (int index = startScan + 1; index < size; index++) {
            if (salesData[index].sales > maxValue) {
                maxValue = salesData[index].sales;
                maxIndex = index;
            }
        }

        
        swap(salesData[maxIndex], salesData[startScan]);
    }
}

void displaySales(const vector<ProductSales> &salesData) {
    cout << "Product Number\tSales\n";
    cout << "----------------------------------\n";
    for (const ProductSales &salesRow : salesData) {
        cout << salesRow.productNumber << "\t\t$";
        cout << setw(8) << fixed << setprecision(2) << salesRow.sales << endl;
    }
    cout << endl;
}

void showTotals(const vector<ProductSales> &salesData) {
    int sumOfUnits = 0;
    double sumOfSales = 0.0;

    for (const ProductSales &salesRow : salesData) {
        sumOfUnits += salesRow.units;
        sumOfSales += salesRow.sales;
    }

    cout << "Total Units Sold: " << sumOfUnits << endl;
    cout << "Total Sales:     $" << fixed << setprecision(2) << sumOfSales << endl;
}
