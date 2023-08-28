/************
Baylee Caldwell
00160404
Problem 1
August 21, 2023
*************/

#include <iostream>
using namespace std;

int main() {
    // one-off error
    int oneOffArray[5] = {1,2,3,4,5};
    for (int i = 0; i <= 5; ++i) {
        cout << oneOffArray[i] << " ";
    }

    //array out of bounds error
    int outOfBoundsArray[3] = {10,20,30};
    cout << endl;
    cout << outOfBoundsArray[4];

    return 0;

}