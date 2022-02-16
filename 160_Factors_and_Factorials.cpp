#include <iostream>
#include <map>
using namespace std;

bool isPrime (int anyNum);
void evaluteNum (int number, map<int,int> &primesMap);
void getPrimes(int notPrime, map<int,int> &pNumbers);
void printResults (int N, map<int,int> &primeNumbers);

int main (){
    int N;
    int tempN;
    map <int, int> primeNumbers;

    cin >> N;
    while(N <= 100 && N >= 2){
        primeNumbers.clear();
        
        for (int i = 2; i <= N; i++){
            tempN = i;
            evaluteNum(tempN, primeNumbers);
        }   
        printResults(N, primeNumbers);

        cin.ignore(); 
        cin >> N;
    }

    return 0;
}

bool isPrime (int anyNum){
    int half = anyNum / 2;

    for (int i = 2; i <= half; i++){
        if (anyNum % i == 0){
            return false;
        }
    }
    return true;
}

void evaluteNum (int number, map<int,int> &primesMap){
    if ( isPrime(number) ){
        primesMap[number]++;
        return;
    }
    else{
        getPrimes(number, primesMap);
    }  
}

void getPrimes(int notPrime, map<int,int> &pNumbers){

    if (notPrime % 2 == 0){
        notPrime = notPrime / 2;
        pNumbers[2]++;
        evaluteNum(notPrime, pNumbers);        
    }
    else if (notPrime % 3 == 0){
        notPrime = notPrime / 3;
        pNumbers[3]++;
        evaluteNum(notPrime, pNumbers);      
    }
    else if (notPrime % 5 == 0){
        notPrime = notPrime / 5;
        pNumbers[5]++;
        evaluteNum(notPrime, pNumbers);    
    }
    else {
        notPrime = notPrime / 7;
        pNumbers[7]++;
        evaluteNum(notPrime, pNumbers);
    }
}

void printResults (int N, map<int,int> &primeNumbers){
    map <int,int>::iterator itr;
    int counter = 0;
    
    if(N < 10){
        cout << "  " << N << "! =";
    }
    else if(N < 100){
        cout << " " << N << "! =";
    }
    else{
        cout << N << "! =";
    }

    for (itr = primeNumbers.begin(); itr != primeNumbers.end(); ++itr){
        if(counter == 15){
            counter = 0;
            cout << endl;
            cout << "      ";
        }

        if(itr->second < 10){
            cout << "  " << itr->second;
        }
        else {
            cout << " " << itr->second;
        }
        counter++;
    }
    cout << endl;
}
    
