#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map <string, string> mapDictionary;
    string strInput;

    while ( getline(cin, strInput) && strInput.size() ) {
        size_t whiteSpace = strInput.find_first_of(' ', 1);
        mapDictionary[strInput.substr(whiteSpace + 1)] = strInput.substr(0, whiteSpace);
    }

    while (cin >> strInput) {
        if ( mapDictionary.find(strInput) == mapDictionary.end() ) {
            cout << "eh" << endl;
        }
        else {
            cout << mapDictionary[strInput] << endl;
        }
    }

    return 0;
}