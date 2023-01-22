//
// Created by brand on 1/21/2023.
//

#ifndef DECK_OF_CARDS_CARD_H
#define DECK_OF_CARDS_CARD_H


#include <type_traits>
#include <ostream>
#include <vector>

struct Card {

    enum class Rank : unsigned char{
        ace = 1,
        two = 2,
        three = 3,
        four = 4,
        five = 5,
        six = 6,
        seven = 7,
        eight = 8,
        nine = 9,
        ten = 10,
        jack = 11,
        queen = 12,
        king = 13
    };

    enum class Suit : unsigned char{
        hearts,
        diamonds,
        clubs,
        spades
    };

    //Store rank and suit in an array of pointers
    static const char* rank_strings[];
    static const char* suit_strings[];

    Rank card_rank;
    Suit card_suit;

    //Overload operator<< to output Card object to the output stream
    friend std::ostream& operator<<(std::ostream& os, const Card& card) {
        os << Card::rank_strings[static_cast<int>(card.card_rank)] << " of " << Card::suit_strings[static_cast<int>(card.card_suit)];
        return os;
    }

};


#endif //DECK_OF_CARDS_CARD_H
