#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>

std::vector <int> init_deck() {  // no input value necessary

    std::vector<int> cards (52, 0.0);  // init integers from 0-51 as 0.0 to set size

    for (int i=0; i<52; i++) {  // write correct numbers to the initialized vector
        cards[i] = i;
    }

    return cards;
}

std::vector <int> to_binary(int position) {
    
    std::vector <int> binary;  // create vector to save position as binary number

    while (position > 0) {  // the remainer modulo 2 is the wanted binary information

        binary.insert(binary.begin(), position % 2); // insert new remainder at position 0 to get correct order
        position = position/2;
    }

    return binary;
}

std::vector <int> shuffle(std::vector <int> cards, bool out) {  // argument sets type of shuffling to out or in

    std::vector <int> first_half (52/2, 0.0);
    std::vector <int> second_half (52/2, 0.0);

    for (int i = 0; i< cards.size(); i++) {  // loop to separate elements into two vectors devided in the middle

        if (i < cards.size()/2) {  // copy numbers from the beginning in vector first_half
            first_half.at(i) = cards.at(i);

        } else {  // copy numbers greater than 30 in vector second_half
            second_half.at(i-cards.size()/2) = cards.at(i);
        }
    }

    if (out) {  // out-shuffle

        for (int i =0; i < cards.size(); i++) {  // recombine the cards

            if (i%2 == 0) {  // get every second card from the first_half vector
                cards.at(i) = first_half [i/2];

            } else {  // get the other cards from the second_half vector
                cards.at(i) = second_half [(i-1)/2];  
            }
        }

    } else {  // in-shuffle

        for (int i =0; i < cards.size(); i++) {  // recombine the cards

            if (i%2 == 0) {  // get every second card from the first_half vector
                cards.at(i) = second_half [i/2];

            } else {  // get the other cards from the second_half vector
                cards.at(i) = first_half [(i-1)/2];  
            }
        }
    }

    return cards;  // shuffled cards in the same variable as the input
}


std::vector<int> shuffle_top_to(std::vector<int> deck, int k) {

    std::vector <int> binary = to_binary(k);

     // test if k is not empty for safety

        for (auto & element : binary) {  // loop through the uint8_t number to reach the single entries

            if (element == 0) {  // depending on the binary entrie
                deck = shuffle(deck, true);  // ... use an out- or in-shuffle 
            } else if (element == 1) {
                deck = shuffle(deck, false);
            } else {
                std::cout << element << "\n";
            }
        }

    return deck;
}

int main() {

    int position;

    // std::cout << "Geben Sie die Position der ersten Karte ein: ";
    // std::cin >> position;
    // std::cout << "\n";

    std::vector<int> deck = shuffle_top_to(init_deck(), 10);
    for (int i =0; i<deck.size(); ++i) {
        if (deck[i] == 0) {
            position = i;
        }
    }
    assert(position  == 10);

    return 0;
}