#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct ReadingRow {
    int sensorNumber;
    string timestamp;
    int sensorReading;
};

const string DATAFILE = "datafile.txt";
vector<ReadingRow> sensorReadings;
int numberOfReadings = 0;
double averageTemperature = 0.0;

void readDataFromFile() {
    ifstream dfile;
    ReadingRow tempRow;
    int sumOfTemps = 0;

    dfile.open(DATAFILE);
    if (dfile.is_open()) {
        while (dfile >> tempRow.sensorNumber >> tempRow.timestamp >> tempRow.sensorReading) {
            sensorReadings.push_back(tempRow);
            sumOfTemps += tempRow.sensorReading;
        }
        numberOfReadings = sensorReadings.size();
        averageTemperature = static_cast<double>(sumOfTemps) / numberOfReadings;
        dfile.close();
    } else {
        cerr << "Error: Unable to open data file" << endl;
        exit(1);
    }
}

bool searchForSensor(int sensorNumber, int &rowNumber) {
    bool found = false;
    rowNumber = -1;
    for (int index = 0; index < sensorReadings.size(); ++index) {
        if (sensorNumber == sensorReadings[index].sensorNumber) {
            rowNumber = index;
            found = true;
            break;
        }
    }
    return found;
}

void displayDataForSensor(int sensorID) {
    bool foundInData = false;
    int rowNumber = -1;
    foundInData = searchForSensor(sensorID, rowNumber);
    if (foundInData) {
        cout << "Sensor number: " << sensorReadings[rowNumber].sensorNumber << endl;
        cout << "Timestamp    : " << sensorReadings[rowNumber].timestamp << endl;
        cout << "Temperature  : " << sensorReadings[rowNumber].sensorReading << endl;
    } else {
        cerr << "Error: Invalid sensor number entered." << endl;
    }
}

int displayMenu() {
    int choice;
    cout << "Enter sensor number to display reading (0 to exit): ";
    cin >> choice;
    return choice;
}

void menuHandler() {
    bool keepGoing = true;
    int choice;
    do {
        choice = displayMenu();
        if (choice == 0) {
            keepGoing = false;
        } else {
            displayDataForSensor(choice);
        }
    } while (keepGoing);
}

int main() {
    readDataFromFile();
    cout << "Overall average temperature: " << averageTemperature << endl;
    menuHandler();
    return 0;
}
