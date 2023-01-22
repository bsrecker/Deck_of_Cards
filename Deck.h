//
// Created by brand on 1/21/2023.
//

#ifndef DECK_OF_CARDS_DECK_H
#define DECK_OF_CARDS_DECK_H


#include "Card.h"
#include <vector>

class Deck {
public:
    std::vector<Card> deck_of_cards;
    std::vector<Card> hand;
    std::vector<Card> discard_pile;

    Deck();
    void display_deck() const;
    void display_hand() const;
    void shuffle_deck();
    std::vector<Card> draw(int);
    void discard(int);
    void reconstruct_deck();
};


#endif //DECK_OF_CARDS_DECK_H
