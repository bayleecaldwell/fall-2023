#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

stack<char> characterStack;

void loadFirstFile(string filename);
void saveSecondFile(string filename);

int main() {
    string firstFile = "";
    string secondFile = "";

    cout << "Enter the name of the first file: ";
    cin >> firstFile;
    cout << "Enter the name of the second file for the reversed content: ";
    cin >> secondFile;

    loadFirstFile(firstFile);
    saveSecondFile(secondFile);

    cout << "File has been reversed and saved as " << secondFile << endl;

    return 0;
}

void loadFirstFile(string filename) {
    fstream file1(filename, ios::in);
    char ch;

    if (!file1.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    while (file1.get(ch)) {
        characterStack.push(ch);
    }

    file1.close();
}

void saveSecondFile(string filename) {
    fstream file2(filename, ios::out);

    if (!file2.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    while (!characterStack.empty()) {
        file2.put(characterStack.top());
        characterStack.pop();
    }

    file2.close();
}
