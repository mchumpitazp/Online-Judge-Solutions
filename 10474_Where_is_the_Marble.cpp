#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main () {
    unsigned int N, Q, number;
    unsigned char numOfCase = 1;

    cin >> N;
    cin >> Q;
    while (N != 0 && Q != 0) 
    {
        unsigned int  arrNumbers[N];

        for (int i = 0; i < N; i++){
            cin >> number;
            arrNumbers[i] = number;
        }
        sort(arrNumbers, arrNumbers + N);

        cout << "CASE# " << (int)numOfCase << ":" << endl;
        while (Q) {
            cin >> number;
            cout << number;
            
            auto it = find(arrNumbers, arrNumbers + N, number);
            if ( it != arrNumbers + N ) {
                cout << " found at " << (distance(arrNumbers, it) + 1)<< endl;
            }
            else {
                cout << " not found" << endl;
            }
            Q--;
        }

        numOfCase = (int)numOfCase + 1;
        cin >> N;
        cin >> Q;
    }

    return 0;
}