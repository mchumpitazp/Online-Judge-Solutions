#include <iostream>
using namespace std;

int main (){   
    int casesNum, frec, amp;
    int temp;
    bool inLimit;
    cin >> casesNum;

    while (casesNum > 0){
        cin.ignore();
        cin.ignore();
        cin >> amp;
        cin.ignore();
        cin >> frec;

        for (int j = 0; j < frec; j++){
            temp = 1;
            inLimit = false;
            while(temp > 0){
                for(int i = 0; i < temp; i++){
                    cout << temp;
                    cout.flush();
                }
                if(temp == amp){
                    inLimit = true;
                }

                if(inLimit == true){
                    temp--;
                }
                else{
                    temp++;
                }
                cout << endl;
            }
            if(casesNum == 1 && j == frec-1){
            }
            else{
                cout << endl; 
            }
                                
        }
        casesNum--;
        
    }
    return 0;
}