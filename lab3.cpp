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

void displayDataForSensor(unsigned int sensorID) {
    cout << "Sensor number: " << sensorReadings[sensorID].sensorNumber << endl;
    cout << "Timestamp    : " << sensorReadings[sensorID].timestamp << endl;
    cout << "Temperature  : " << sensorReadings[sensorID].sensorReading << endl;
}

int main() {
    readDataFromFile();

    cout << "Overall average temperature: " << averageTemperature << endl;

    int selectedSensor;
    cout << "Enter sensor number to display reading: ";
    cin >> selectedSensor;

    for (unsigned int i = 0; i < numberOfReadings; ++i) {
        if (sensorReadings[i].sensorNumber == selectedSensor) {
            displayDataForSensor(i);
            break;
        }
    }

    return 0;
}
