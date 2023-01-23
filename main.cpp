#include <iostream>
#include "Deck.h"
#include "Deck_Functions.h"
#include <limits>


enum user_input {Draw_Cards = 1, Discard_Card, Shuffle_Deck, Display_Hand, Display_Deck, Reconstruct_Deck};

int main() {
    Deck deck;
    while (true){
        std::cout << "=========================================\n";
        std::cout << "(1) - Draw Cards\n (2) - Discard card \n"
                     "(3) - Shuffle Deck \n (4) - Display Hand\n"
                     "(5) - Show Deck\n (6) - Reconstruct Deck\n";

        int choice;
        std::cin >> choice;

        switch(choice){

            case Draw_Cards:
                int n;
                std::cout << "How many cards would you like to draw?\n";
                std::cin >> n;
                deck.draw(n);
                break;

            case Discard_Card:
                if (!deck.hand.empty()){
                    std::cout << "How many cards would you like to discard from your hand?\n";
                    std::cin >> n;
                    deck.discard(n);
                } else{
                    std::cout << "You haven't drawn any cards yet!\n";
                }

                break;

            case Shuffle_Deck:
                deck.shuffle_deck();
                std::cout << "Deck shuffled.\n";
                break;

            case Display_Hand:
                if (!deck.hand.empty()){
                    display_hand(deck);
                }else{
                    std::cout << "No cards in hand!\n";
                }

                break;

            case Display_Deck:
                display_deck(deck);
                break;

            case Reconstruct_Deck:
                deck.reconstruct_deck();
                std:: cout << "Reconstructing deck...\n";
                break;

            default:
                std::cout << "Invalid selection!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                break;
        }
    }


}
