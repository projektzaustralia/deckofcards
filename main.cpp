#include <iostream>
#include <string>
#include <cstdlib> //for rand and srand
#include <cstdio>
using namespace std;

string type[] = {"Diamonds", "Hearts", "Spades", "Clubs"};
string facevalue[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
int numberOfCardsDrawn = 0;
string drawnCards[52];

string drawCard () {
    string card;
    int cardvalue = rand()%13;
    int cardsuit = rand()%4;
    card += facevalue[cardvalue];
    card += " of ";
    card += suit[cardsuit];
    return card;
}

bool isMyCardAlreadyDrawn (string card) {
    for(int i = 0; i < 52; i++) {
        if(card.compare(drawnCards[i]) == 0) { // if this is true, then both strings are the same
            return true;
        }
    }
    return false; // if the code reaches this point, then the card has not been drawn yet
}

string getCard () {
    string card = drawCard();
    while (isMyCardAlreadyDrawn(card) == true) { // keep drawing until an undrawn card is found
        card = drawCard(); // draw a new card
    }
    drawnCards[numberOfCardsDrawn] = card;
    numberOfCardsDrawn++;
    return card;
}

int main () {
    int numberOfCards = 52;
    for (int i = 0; i < numberOfCards; i++){
        cout << "You drew a " << getCard() << endl;
    }
}
