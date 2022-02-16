#include <iostream>
#include <sstream>
using namespace std;

int main(){ 
    int counter = 2;
    char checkEOF;
    char text;

    checkEOF = getchar();

    while(checkEOF != EOF){
        text = checkEOF;
        if(text == '"'){
            if(counter % 2 == 0){
                cout << "``";
                counter++;
            }
            else
            {
                cout << "''";
                counter++;
            }            
        }
        else{
            cout << text;
        }

        checkEOF= getchar();
    }

    return 0;
} 