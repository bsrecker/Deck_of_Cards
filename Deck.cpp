//
// Created by brand on 1/21/2023.
//

#include <iostream>
#include "Deck.h"
#include <algorithm>
#include <random>


Deck::Deck() {
        for (int suit = 0; suit <= 3; suit++) {
            for (int rank = 1; rank <= 13; rank++) {
                Card card;
                card.card_rank = static_cast<Card::Rank>(rank);
                card.card_suit = static_cast<Card::Suit>(suit);
                deck_of_cards.push_back(card);
            }
        }
        //Shuffle the deck to insure a random order after constructing the deck.
        shuffle_deck();
    }

void Deck::display_deck() const{
    for (auto card : deck_of_cards) {
        std::cout << Card::rank_strings[static_cast<int>(card.card_rank)]
        << " of " << Card::suit_strings[static_cast<int>(card.card_suit)] << "\n";
    }
}

void Deck::display_hand() const{
    for (auto card : hand){
        std::cout << Card::rank_strings[static_cast<int>(card.card_rank)]
                  << " of " << Card::suit_strings[static_cast<int>(card.card_suit)] << "\n";
    }
}

void Deck::shuffle_deck() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck_of_cards.begin(), deck_of_cards.end(), g);

}

std::vector<Card> Deck::draw(int const n) {
    for (int i = 0; i < n && !deck_of_cards.empty(); i++) {
        hand.push_back(deck_of_cards.front());
        deck_of_cards.erase(deck_of_cards.begin());
    }
    return hand;
}

void Deck::discard(int const n) {
    for (int i = 0; i < n && !deck_of_cards.empty() && !hand.empty(); i++) {
        discard_pile.push_back(hand.front());
        hand.erase(hand.begin());

        }
    }

void Deck::reconstruct_deck() {
    //Clear all vectors storing cards.
    deck_of_cards.clear();
    hand.clear();
    discard_pile.clear();

    //Rebuild the deck
    for (int suit = 0; suit <= 3; suit++) {
        for (int rank = 1; rank <= 13; rank++) {
            Card card;
            card.card_rank = static_cast<Card::Rank>(rank);
            card.card_suit = static_cast<Card::Suit>(suit);
            deck_of_cards.push_back(card);
        }
    }
    //Shuffle the deck to insure a random order after constructing the deck.
    shuffle_deck();
}


