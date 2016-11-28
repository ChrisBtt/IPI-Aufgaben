#include <iostream>
#include <vector>
#include <cassert>



std::vector <int> init_deck() {  // no input value necessary

    std::vector<int> cards (52, 0.0);  // init integers from 0-51 as 0.0 to set size

    for (int i=0; i<52; i++) {  // write correct numbers to the initialized vector
        cards[i] = i;
    }

    return cards;
}

bool check_deck(std::vector <int> cards) {

    for (int i=0; i<52; i++) {  // test vector in a for loop to get every number once

        if (cards[i] == i) {
            continue;
        } else {  // if test failse return false
            return false;
        }
    }

    return true;  // return true when every test is done successfully
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



int main() {

    assert(check_deck(init_deck()));  // program continues if assert is true

    int shuffles_out = 0;
    std::vector <int> deck = init_deck();
    assert(check_deck(deck));

    do {  // do-while to assure one shuffle is done before checking
        deck = shuffle(deck, true);
        shuffles_out++;
    } while ( !check_deck(deck) );

    std::cout << shuffles_out << "\n";

    assert(check_deck(deck));  // program continues if assert is true
    int shuffles_in = 0;

    do {  // do-while to assure one shuffle is done before checking
        deck = shuffle(deck, false);
        shuffles_in++;
    } while ( !check_deck(deck) );

    std::cout << shuffles_in << "\n \n";

    if (shuffles_in < shuffles_out) {  // Output depending on the comparison of the two results
        std::cout << "Die In-Shuffle Methode ist effizienter \n";
    } else if (shuffles_in > shuffles_out) {
        std::cout << "Die Out-Shuffle Methode ist effizienter \n";
    } else {
        std::cout << "Beide Methoden sind gleich effizient \n";
    }


    return 0;
}








