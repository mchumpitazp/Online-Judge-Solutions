#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map <int, vector<string>> spreadsheet;

int posOfFirstDigit(string s){
    int i; 
    for (i = 0; i < s.size(); i++){
        if ((int)s[i] > 47 && (int)s[i] < 58){
            break;
        }
    }
    return i;
}

int lettersToInteger(string letters){
    int columnNumber = 0;
    int indexFactor = 1;

    for (int i = letters.size()-1; i >= 0; i--){
        columnNumber = columnNumber + indexFactor * ((int)letters[i] - 64);
        indexFactor = indexFactor * 26;
    }
    return columnNumber;
}

inline void getDataReady(string &data){
    data.erase(0, 1);
    replace(data.begin(), data.end(), '+', ' ');
}

int getCellValue(int column, int row){
    string data = spreadsheet[column][row];
    if (data[0] != '='){
        return stoi(data);
    }

    string sub_data;
    int result = 0;
    int firstDigit;
    int columnIndex, rowIndex;
    getDataReady(data);

    while( sub_data != data ){
        sub_data = data.substr(0, data.find(' '));
        firstDigit = posOfFirstDigit(sub_data);
        columnIndex = lettersToInteger(sub_data.substr(0, firstDigit));
        rowIndex = stoi(sub_data.substr(firstDigit, sub_data.size())) - 1;
        result = result + getCellValue(columnIndex, rowIndex);
        data = data.substr(data.find(' ')+1, data.size());
    }
    return result;
}

void readMatrix(int columns, int rows){
    string data;
    for(int i = 0; i < rows; i++){
        for(int j = 1; j <= columns; j++){
            cin >> data;
            spreadsheet[j].push_back(data);
        }
    }
}

void printMatrix(int columns, int rows){
    for(int i = 0; i < rows; i++){
        for(int j = 1; j <= columns; j++){
            cout << getCellValue(j, i);
            (j < columns)? cout << " " : cout << "\n";
        }
    }
}

int main() {
    int columns, rows, numOfSpreadsheets;
    cin >> numOfSpreadsheets;

    while (numOfSpreadsheets--){
        spreadsheet.clear();
        cin >> columns;
        cin >> rows;

        readMatrix(columns, rows);
        printMatrix(columns, rows);
    }
    return 0;
}