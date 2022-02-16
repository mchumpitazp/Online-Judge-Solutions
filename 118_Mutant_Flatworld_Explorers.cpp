#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main () {
    unsigned int boundaryX, boundaryY;
    signed int posX, posY;
    char orientation;
    string instructions;
    vector < pair <signed int, signed int> > gridScent;

    cin >> boundaryX >> boundaryY;
    
    while (cin >> posX >> posY >> orientation >> instructions) {
        bool isLost = false;
        
        for(int i = 0; i < instructions.size(); i++) {
            switch (instructions[i])
            {
            case 'L':
                switch (orientation)
                {
                case 'N': orientation = 'W'; break;
                case 'S': orientation = 'E'; break;
                case 'W': orientation = 'S'; break;
                case 'E': orientation = 'N';
                }
                break;

            case 'R':
                switch (orientation)
                {
                case 'N': orientation = 'E'; break;
                case 'S': orientation = 'W'; break;
                case 'W': orientation = 'N'; break;
                case 'E': orientation = 'S';
                }
                break;

            case 'F': 
                switch (orientation)
                {
                case 'N': posY++; break;
                case 'S': posY--; break;
                case 'W': posX--; break;
                case 'E': posX++;
                }
            }

            if (posX < 0 || posY < 0 || posX > boundaryX || posY > boundaryY) {
                switch (orientation)
                {
                case 'N': posY--; break;
                case 'S': posY++; break;
                case 'W': posX++; break;
                case 'E': posX--;
                }

                if ( find(gridScent.begin(), gridScent.end(), make_pair(posX, posY) ) == gridScent.end() ) {
                    gridScent.push_back( make_pair(posX, posY) );
                    isLost = true;
                    break;
                }
            }
        }

        cout << posX << " " << posY << " " << orientation;
        (isLost == true)? cout << " LOST" << endl : cout << endl;
    }

    return 0;
}