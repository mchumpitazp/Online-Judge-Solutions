#include <iostream>
using namespace std;

int main (){
    unsigned int testCases, numCase = 1;
    unsigned int N, K, P, player;

    cin >> testCases;

    while (testCases){
        cin >> N; cin >> K; cin >> P; 
        bool goodN = (N >= 2) && (N <= 23);
        bool goodK = (K >= 1) && (K <= N);
        bool goodP = (P >= 1) && (P <= 200);
        if ( !goodN || !goodK || !goodP ) {throw out_of_range("Invalid input parameters");}
        player = K;

        for (int i = 0; i < P; i++){
            if (player == N){
                player = 1;
            }
            else{
                player++;
            }
        }
        cout << "Case "<< numCase << ": "<< player << endl;
        testCases--;
        numCase++;
    }
    return 0;
}

