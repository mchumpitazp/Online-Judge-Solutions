#include <iostream>
using namespace std;

int main(){
    unsigned int numCases, sizeWalls;

    cin >> numCases;
    if(numCases > 29){ throw out_of_range("Number of cases is out of range");}

    for (int j = 1; j <= numCases; j++){
        cin >> sizeWalls;
        if(numCases > 49){ throw out_of_range("Number of walls is out of range");}

        unsigned int high = 0, low = 0;
        unsigned int arrWalls[sizeWalls];

        for (int i = 0; i < sizeWalls; i++){
            cin >> arrWalls[i];
            if(arrWalls[i] > 10){ throw out_of_range("Wall height is out of range");}
        }

        for (int i = 0; i < (sizeWalls - 1); i++){
            if( arrWalls[i] < arrWalls[i+1]){
                high++;
            }
            else if( arrWalls[i] > arrWalls[i+1]){
                low++;
            }
        }
        cout << "Case " << j << ": " << high << " " << low << endl;
    }
    return 0;
}