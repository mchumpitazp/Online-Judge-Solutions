#include <iostream>
using namespace std;

int caseMoves, minMoves;
string binLetters;

inline void isLess(string bins) {
    if (caseMoves < minMoves) {
        minMoves = caseMoves;
        binLetters = bins;
    }
}

int main() {
    int totalSum;
    int arrBins[9];
    
    while (cin >> arrBins[0] >> arrBins[1] >> arrBins[2] >> arrBins[3] >> arrBins[4]
              >> arrBins[5] >> arrBins[6] >> arrBins[7] >> arrBins[8]) {

        totalSum = 0;
        for(int i = 0; i < 9; i++) {
            totalSum += arrBins[i];
        }

        binLetters = "BCG";
        minMoves = totalSum - arrBins[0] - arrBins[5] - arrBins[7];

        caseMoves = totalSum - arrBins[2] - arrBins[3] - arrBins[7];
        isLess("CBG");

        caseMoves = totalSum - arrBins[0] - arrBins[4] - arrBins[8];
        isLess("BGC");

        caseMoves = totalSum - arrBins[2] - arrBins[4] - arrBins[6];
        isLess("CGB");           

        caseMoves = totalSum - arrBins[1] - arrBins[3] - arrBins[8];
        isLess("GBC");

        caseMoves = totalSum - arrBins[1] - arrBins[5] - arrBins[6];
        isLess("GCB");
        
        cout << binLetters << " " << minMoves << endl;
    }
    return 0;
}