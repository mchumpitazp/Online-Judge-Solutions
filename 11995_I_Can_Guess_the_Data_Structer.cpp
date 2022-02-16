#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main () {
    int numOfCases;
    bool isStack, isQueue, isPQ;
    stack<int> ss;
    queue<int> qq;
    priority_queue<int> pq;
    
    while (cin >> numOfCases) {
        isStack = isQueue = isPQ = true;
        
        while ( !ss.empty() ) { ss.pop(); }
        while ( !qq.empty() ) { qq.pop(); }
        while ( !pq.empty() ) { pq.pop(); }

        int operation;
        int val;
        int counter = 0;

        for (int i = 0; i < numOfCases; i++) {
            cin >> operation >> val;

            if (operation == 1) {
                ss.push(val);
                qq.push(val);
                pq.push(val);
            }  
            else if (operation == 2) {
                if ( !ss.empty() ){
                    if ( val != ss.top() ) { isStack = false; }
                    if ( val != qq.front() ) { isQueue = false; }
                    if ( val != pq.top() ) { isPQ = false; }

                    ss.pop();
                    qq.pop();
                    pq.pop();
                }
                else {
                    isStack = isQueue = isPQ = false;
                }               
            }                  
        }

        if ( isStack ) { counter++; }
        if ( isQueue ) { counter++; }
        if ( isPQ )    { counter++; }

        if ( counter == 0){
            cout << "impossible" << endl;
        }
        else if ( counter > 1 ) {
            cout << "not sure" << endl;
        }
        else {
            if      ( isStack ) { cout << "stack" << endl; }
            else if ( isQueue ) { cout << "queue" << endl; }
            else    { cout << "priority queue" << endl; }
        }
    }

    return 0;
}