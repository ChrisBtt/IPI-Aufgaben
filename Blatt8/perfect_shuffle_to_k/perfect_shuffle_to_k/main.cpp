//
//  main.cpp
//  perfect_shuffle_to_k
//
//  Created by logosal mac on 16.12.16.
//  Copyright © 2016 logosal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdint.h>
#include <cassert>

using namespace std;

// binary code of k

vector <int> binary(uint8_t k) {
    
    // binary code in wrong order
    
    vector<int> rev;
    
    for (int x = 0; x < 8; x++) {
        int remain = k % 2;
        rev.push_back(remain);
        k = (k / 2);
    }
    
    // revert vector
    
    vector<int> res;
    
    for (int i = rev.size()-1; i >= 0 ; i--) {
        res.push_back(rev[i]);
    }
    
    return res;
}

// in- and out-Shuffle

vector<int> shufflex(vector<int> cards, bool out) {
    
    // initializing result-vector
    
    vector<int> result;
    
    // vector has to have size 52
    
    if (cards.size() != 52) {
        return result;
    }
    
    // shuffling
    
    if (out) {
        // out-shuffle
        for (int i = 0; i < 26; i++) {
            result.push_back(cards[i]);
            result.push_back(cards[i + 26]);
        }
    } else {
        // in-shuffle
        for (int i = 0; i < 26; i++) {
            result.push_back(cards[i + 26]);
            result.push_back(cards[i]);
        }
        
    }
    
    return result;
}

// shuffle to position k

vector<int> shuffle_top_to(vector<int> deck, uint8_t k) {
    
    vector<int> k_binary = binary(k);
    
    for (int i = 0; i < k_binary.size(); i++) {
        if (k_binary[i] == 0) {
            deck = shufflex(deck, true);
        } else {
            deck = shufflex(deck, false);
        }
    }
    
    return deck;
}

int main() {
    
    vector <int> cards;
    
    for (int i=0; i<52; i++) {
        cards.push_back(i);
    }
    
    // testing
    
    for (int i = 0; i < 52; i++) {
        vector<int> test_deck;
        test_deck = shuffle_top_to(cards, i);
        assert(test_deck[i] == 0);
    }
    
    return 0;
}
