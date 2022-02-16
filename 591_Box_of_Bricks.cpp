#include <iostream>
using namespace std;

inline void printOutput(unsigned int &set, unsigned int moves){
    cout << "Set #" << set << endl;
    cout << "The minimum number of moves is " << moves << ".\n" << endl;
    set++;
}

int main() {
    unsigned int  numOfStacks, numOfSet = 1;

    while (cin >> numOfStacks && numOfStacks != 0){
        unsigned int arr[numOfStacks];
        unsigned int wallSize = 0, minMoves = 0;

        // Reads stacks sizes and get the average wall size
        for (int i = 0; i < numOfStacks; i++){
            cin >> arr[i];
            wallSize += arr[i];
        }
        wallSize = wallSize / numOfStacks;

        // Get the minimum moves to balance all stacks
        for (int i = 0; i < numOfStacks; i++){
            if (arr[i] > wallSize){
                minMoves += (arr[i] - wallSize);
            }
        }

        printOutput(numOfSet, minMoves);
    }

    return 0;
}