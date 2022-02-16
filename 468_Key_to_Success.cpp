#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

bool sortByVal(const pair<char, int> &a, const pair<char, int> &b){ 
    return (a.second > b.second); 
} 

int main(){
    int numofCases;
    char temp_char;
    string order;
    map <char, int>::iterator it;
    map <char, int> mapCounter;
    vector <pair<char, int>> vecNewLetter;
    vector <pair<char, int>> vecOldLetter;

    cin >> numofCases;
    cin.ignore(256, '\n');

    while(numofCases != 0){
        cin.ignore(256, '\n');
        order.clear();
        mapCounter.clear();
        vecOldLetter.clear();
        vecNewLetter.clear();

        while((temp_char = getchar()) != '\n'){
            mapCounter[temp_char]++;
        }

        for (it = mapCounter.begin(); it != mapCounter.end(); ++it){
            vecNewLetter.push_back(make_pair(it->first, it->second));
        }
        sort (vecNewLetter.begin(), vecNewLetter.end(), sortByVal);
        mapCounter.clear();

        while((temp_char = getchar()) != '\n'){
            mapCounter[temp_char]++;
            order = order + temp_char;
        }
        
        for (it = mapCounter.begin(); it != mapCounter.end(); ++it){
            vecOldLetter.push_back(make_pair(it->first, it->second));
        }
        sort (vecOldLetter.begin(), vecOldLetter.end(), sortByVal);

        for(int i = 0; i < order.length(); i++){
            for(int j = 0; j < vecOldLetter.size(); j++){
                if(order[i] == vecOldLetter[j].first){
                    cout << vecNewLetter[j].first;
                }
            }
        }
        if(numofCases > 1){
            cout << "\n" << "\n";
        }
        else{
            cout << "\n";
        }
        
        numofCases--;     
    }   
    
    return 0;
}