#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAXSIZE = 1000;

int main() {
    int sensorNumber[MAXSIZE];
    string timestamp[MAXSIZE];
    int sensorReadings[MAXSIZE];
    int numReadings = 0;
    double totalReadings = 0.0;

    
    ifstream inputFile("datafile.txt");
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    while (numReadings < MAXSIZE &&
           inputFile >> sensorNumber[numReadings] >> timestamp[numReadings] >> sensorReadings[numReadings]) {
        totalReadings += sensorReadings[numReadings];
        numReadings++;
    }

    inputFile.close();

    if (numReadings == 0) {
        cerr << "No data found in the file." << endl;
        return 1;
    }


    double averageReading = totalReadings / numReadings;
    cout << "Overall average reading: " << averageReading << endl;

    
    int selectedSensor;
    cout << "Enter sensor number to display reading: ";
    cin >> selectedSensor;

    for (int i = 0; i < numReadings; ++i) {
        if (sensorNumber[i] == selectedSensor) {
            cout << "Reading for sensor " << selectedSensor << " at " << timestamp[i] << " is " << sensorReadings[i] << endl;
        }
    }

    return 0;
}
