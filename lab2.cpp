#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAXSAMPLES = 1000;
const string DATAFILE = "datafile.txt"; // Replace with your file path

struct ReadingRow {
    int sensorNumber;
    string timestamp;
    int sensorReading;
};

ReadingRow sensorReadings[MAXSAMPLES];
int numberOfReadings = 0;
double averageTemperature = 0.0;

void readDataFromFile() {
    ifstream dfile;
    int sNumber = 0;
    string currentTS = "";
    int sReading = 0;
    int readingCount = 0;
    int sumOfTemps = 0;
    
    dfile.open(DATAFILE);
    if (dfile.is_open()) {
        while (dfile >> sNumber >> currentTS >> sReading) {
            readingCount++;
            sensorReadings[readingCount].sensorNumber = sNumber;
            sensorReadings[readingCount].timestamp = currentTS;
            sensorReadings[readingCount].sensorReading = sReading;
            sumOfTemps += sReading;
        }
        numberOfReadings = readingCount;
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

    for (int i = 1; i <= numberOfReadings; ++i) {
        if (sensorReadings[i].sensorNumber == selectedSensor) {
            displayDataForSensor(i);
            break;
        }
    }

    return 0;
}
