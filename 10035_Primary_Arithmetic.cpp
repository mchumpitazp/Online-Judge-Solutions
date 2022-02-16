#include <iostream>
using namespace std;

int main(){
    string num1, num2;
    unsigned int inum1, inum2, size1, size2, counter;
    bool carry;

    while (1){
        cin >> num1;
        cin >> num2;
        counter = 0;
        size1 = num1.size();
        size2 = num2.size();
        inum1 = num1[size1-1] - '0';
        inum2 = num2[size2-1] - '0';

        if ( inum1 == 0 && size1 == 1 && inum2 == 0 && size2 == 1) {break;}

        int bigSize = size1;
        if (size1 > size2){
            for (int i = 0; i < size1-size2; i++){
                num2 = "0" + num2;
            }
        }
        else if (size2 > size1){
            for (int i = 0; i < size2-size1; i++){
                num1 = "0" + num1;
            }
            bigSize = size2;
        }

        carry = false; 
        while (bigSize){
            bigSize--;
            inum1 = num1[bigSize] - '0';
            inum2 = num2[bigSize] - '0';

            if ( inum1+inum2+carry >= 10 ){
                counter++;
                carry = true;
            }
            else{
                carry = false;
            }
        }

        if ( counter < 1 ){
            cout << "No carry operation." << endl;
        }
        else if ( counter == 1) {
            cout << "1 carry operation." << endl;
        }
        else{
            cout << counter << " carry operations." << endl;
        }
    }
    return 0;
}