//
// Created by brand on 1/22/2023.
//
#include "Deck_Functions.h"
#include <iostream>

void display_deck(const Deck& deck) {
    for (const auto& card : deck.deck_of_cards) {
        std::cout << Card::rank_strings[static_cast<int>(card.card_rank)]
                  << " of " << Card::suit_strings[static_cast<int>(card.card_suit)] << "\n";
    }
}

void display_hand(const Deck& deck){
    for (const Card& card : deck.hand){
        std::cout << Card::rank_strings[static_cast<int>(card.card_rank)]
                  << " of " << Card::suit_strings[static_cast<int>(card.card_suit)] << "\n";
    }
}