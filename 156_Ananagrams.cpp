#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

int main(){
    string word;
    vector <string> inWords;
    vector <string>::iterator it;
    map <string, int> wordMap;
    map <string, int>::iterator itr, itr2;

    while ( cin >> word && word != "#"){        
        inWords.push_back(word);

        for (int i = 0; i < word.size(); i++){
            if ( (int)word[i] < 97 ){
                word[i] = word[i] + ' ';
            }
        }  
        sort (word.begin(), word.end());   
        wordMap[word]++;      
    }

    itr = wordMap.begin();
    while (itr != wordMap.end()){
        if ( itr->second > 1 ){
            itr2 = itr;
            ++itr;
            wordMap.erase(itr2->first);
        }
        else{
            ++itr;
        }
    }
    
    sort (inWords.begin(), inWords.end());
    for( it = inWords.begin(); it != inWords.end(); ++it ){
        string temp = *it;
        for (int i = 0; i < temp.size(); i++){
            if ( (int)temp[i] < 97 ){
                temp[i] = temp[i] + ' ';
            }
        }  
        sort (temp.begin(), temp.end()); 
            
        for (itr = wordMap.begin(); itr != wordMap.end(); ++itr){
            if ( temp == itr->first ){
                cout << *it << endl;
                break;
            }
        }
    }

    return 0;
}