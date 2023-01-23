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
                ++total_cards;
            }
        }
        //Ensure deck is in a valid state
        check_invariant();
        //Shuffle the deck to insure a random order after constructing the deck.
        shuffle_deck();
    }

void Deck::shuffle_deck() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck_of_cards.begin(), deck_of_cards.end(), g);

}

std::vector<Card> Deck::draw(int n) {
    if (n > deck_of_cards.size()) {
        std::cout << "Error: Attempting to draw more cards than are in the deck.\n";
        return hand;
    }
    check_invariant();
    for (int i = 0; i < n && !deck_of_cards.empty(); i++) {
        hand.push_back(deck_of_cards.front());
        deck_of_cards.erase(deck_of_cards.begin());
    }
    check_invariant();
    return hand;
}

void Deck::discard(int const n) {
    if (n > hand.size()) {
        std::cout << "Error: Attempting to discard more cards than are in the hand.\n";
        return;
    }
    check_invariant();
    for (int i = 0; i < n && !deck_of_cards.empty() && !hand.empty(); i++) {
        discard_pile.push_back(hand.front());
        hand.erase(hand.begin());

        }
    check_invariant();
    }

void Deck::reconstruct_deck() {
    //Clear all vectors storing cards.
    deck_of_cards.clear();
    hand.clear();
    discard_pile.clear();
    total_cards = 0;

    //Rebuild the deck
    for (int suit = 0; suit <= 3; suit++) {
        for (int rank = 1; rank <= 13; rank++) {
            Card card;
            card.card_rank = static_cast<Card::Rank>(rank);
            card.card_suit = static_cast<Card::Suit>(suit);
            deck_of_cards.push_back(card);
            ++total_cards;
        }
    }
    //Ensure the deck is constructed in a valid state
    check_invariant();

    //Shuffle the deck to insure a random order after constructing the deck.
    shuffle_deck();
}


