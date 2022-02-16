#include <iostream>
#include <string>
#include <deque>
#include <fstream>
using namespace std;

deque<char> player, dealer, table;
bool isGameOver, playerLoss = false;

inline bool isFaceCard (char cardNum) {
    return cardNum == 'A' || cardNum == 'J' || cardNum == 'Q' || cardNum == 'K';
}

inline int getChances (char cardNum) {
    int chances = 0;
    switch (cardNum)
    {
    case 'A': chances = 4; break;
    case 'J': chances = 1; break;
    case 'Q': chances = 2; break;
    case 'K': chances = 3;
    }
    return chances;
}

inline void dropCard (deque<char> &deck) {
    table.push_front(deck.back());
    deck.pop_back();
}

inline void printWinner (bool isPlayer, bool isDigit) {
    (isPlayer == true)? cout << 2 : cout << 1;
    (isDigit == true)? cout << "  " : cout << " ";
    (isPlayer == true)? cout << player.size() << endl : cout << dealer.size() << endl;
}

void passDeck (deque<char> &deck) {
    while ( !table.empty() ) {
        deck.push_front(table.back());
        table.pop_back();
    }
}

bool solveSequence (bool isPlayerTurn) {
    int chances = getChances(table.front());

    for (int i = 0; i < chances; i++) {
        if ( isPlayerTurn && !player.empty() ) {
            dropCard(player);
        }
        else if ( !isPlayerTurn && !dealer.empty() ) {
            dropCard(dealer); 
        }
        else {
            isGameOver = true;
            if ( isPlayerTurn && player.empty() ){
                playerLoss = true;
            }
            break;
        }

        if ( !isGameOver && isFaceCard(table.front()) ) {
            return true;
        }
    }

    if ( !isGameOver ) {
        (isPlayerTurn == true)? passDeck(dealer) : passDeck(player);   
    }
    return false;
}

int main () { 
    string playerCard, dealerCard;

    while ( cin >> playerCard && playerCard != "#" ) {
        cin >> dealerCard;

        player.clear();
        dealer.clear();
        table.clear();
   
        player.push_back(playerCard[1]);
        dealer.push_back(dealerCard[1]);

        for (int i = 0; i < 25; i++) {
            cin >> playerCard;
            cin >> dealerCard;
            player.push_back(playerCard[1]);
            dealer.push_back(dealerCard[1]);
        }

        isGameOver = false;
        bool isPlayerTurn = true;

        while ( !isGameOver ) {
            if ( isPlayerTurn && !player.empty() ){
                dropCard(player);
            }
            else if ( !isPlayerTurn && !dealer.empty() ){
                dropCard(dealer);
            }
            else {
                isGameOver = true;
                if ( isPlayerTurn && player.empty() ){
                    playerLoss = true;
                }
            }
                        
            if ( !isGameOver && isFaceCard(table.front()) ) {
                bool isSwitching = true;

                while ( isSwitching ) {  
                    isSwitching = solveSequence(!isPlayerTurn);
                    if ( isSwitching ) {
                        isPlayerTurn = !isPlayerTurn;
                    }
                }                                     
            }            
            else {
                if ( !isGameOver ){
                    isPlayerTurn = !isPlayerTurn;
                }                
            }                        
        }

        if ( playerLoss && player.empty () ) {
            printWinner(false, dealer.size() < 10);
        }
        else {
            printWinner(true, player.size() < 10);
        }
    }

    return 0;
}