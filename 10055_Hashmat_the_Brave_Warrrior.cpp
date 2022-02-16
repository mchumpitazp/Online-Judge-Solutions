#include <iostream>
using namespace std;

int main () {
    long int s[2];

    while (cin >> s[0] && cin >> s[1]) {
        cout << abs(s[0] - s[1]) << endl;
    }

    return 0;
}