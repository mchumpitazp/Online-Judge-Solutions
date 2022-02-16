#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

inline unsigned long int getReverse (string &number, char* &ptr){
    reverse(number.begin(), number.end());
    ptr = &number[0];
    while (*ptr == '0') { ptr++; }

    return strtoul(ptr, NULL, 0);
}

int main(){
    unsigned int numofCases, counter;
    unsigned long int number, rev_number;
    char* ptr;
    string str_number;

    cin >> numofCases;
    while ( numofCases-- ) {
        
        counter = 0;
        cin >> str_number;

        ptr = &str_number[0];
        number     = strtoul(ptr, NULL, 0);
        rev_number = getReverse (str_number, ptr);

        do {
            counter++;
            number = number + rev_number;
            
            str_number = to_string(number);
            rev_number = getReverse (str_number, ptr);   

        } while ( number != rev_number);

        cout << counter << " " << number << '\n';
    }

    return 0;
}