#include <string>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

using FreqTable = map<string, int>;

void buildFreqTable(FreqTable &);
void printTable(const FreqTable &);
void saveTableToFile(const FreqTable &, const string &);

int main() {
    FreqTable wordFreqTable;
    buildFreqTable(wordFreqTable);
    printTable(wordFreqTable);
    saveTableToFile(wordFreqTable, "word_freq_table.txt");
    return 0;
}

void buildFreqTable(FreqTable &aFreqTable) {
    string aWord = "";
    cout << "Enter words (Ctrl+Z on Windows, Ctrl+D on Mac systems to end):" << endl;
    while (cin >> aWord) {
        auto keyiter = aFreqTable.find(aWord);
        if (keyiter != aFreqTable.end()) {
            aFreqTable[aWord]++;
        } else {
            aFreqTable[aWord] = 1;
        }
    }
}

void printTable(const FreqTable &aFreqTable) {
    cout << "Word frequency table:" << endl;
    for (const auto &pair : aFreqTable) {
        cout << pair.first << " : " << pair.second << endl;
    }
}

void saveTableToFile(const FreqTable &aFreqTable, const string &filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    file << "Word frequency table:" << endl;
    for (const auto &pair : aFreqTable) {
        file << pair.first << " : " << pair.second << endl;
    }

    file.close();
    cout << "Word frequency table saved to " << filename << endl;
}
