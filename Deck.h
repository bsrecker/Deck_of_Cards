//
// Created by brand on 1/21/2023.
//

#ifndef DECK_OF_CARDS_DECK_H
#define DECK_OF_CARDS_DECK_H


#include "Card.h"
#include <vector>

class Deck {

private:
    int total_cards;
    void check_invariant() const{
        if (deck_of_cards.size() + hand.size() + discard_pile.size() != 52){
            throw std::logic_error("Invariant violated: total cards should be 52");
        }
    }


public:
    Deck();

    std::vector<Card> deck_of_cards;
    std::vector<Card> hand;
    std::vector<Card> discard_pile;

    void shuffle_deck();
    std::vector<Card> draw(int const);
    void discard(int);
    void reconstruct_deck();
};


#endif //DECK_OF_CARDS_DECK_H
