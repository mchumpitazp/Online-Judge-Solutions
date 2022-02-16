#include <map>
#include <iterator>
#include <iostream>
using namespace std;

int main (){

    map <string, int> InputList;
    map <string, int>::iterator it;
    string Country;
    int numofConquest;

    cin >> numofConquest;

    while(numofConquest--){
        cin.ignore(256, '\n');

        cin >> Country;
        InputList[Country]++;           
    }

    for(it = InputList.begin(); it != InputList.end(); ++it)
    {
        cout << it->first << " " << it->second << "\n";
    }

    return 0;
}