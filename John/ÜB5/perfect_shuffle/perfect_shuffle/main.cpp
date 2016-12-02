//
//  main.cpp
//  perfect_shuffle
//
//  Created by logosal mac on 26.11.16.
//  Copyright © 2016 logosal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

// a.)

vector<int> init_deck() {
    vector<int> res_vector(1,0);
    for (int i = 1; i < 52; i++) {
        res_vector.push_back(i);
    }
    return res_vector;
}

// b.)

bool check_deck(vector<int> cards) {
    
    // vector for testing
    
    vector<int> test = init_deck();
    
    // vectors have to have same size
    
    if (cards.size() != 52) {
        return false;
    }
    
    // checking if vectors are identical
    
    if (test == cards) {
        return true;
    }
    
    return false;
}

// c.)

vector<int> shuffle(vector<int> cards, bool out) {
    
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

int main() {
    
    // b.)
    
    assert(check_deck(init_deck()));
    
    // printing to console, debugging
    
    /*
    
    vector<int> test = init_deck();
    
    vector<int> shuffled = shuffle(test, false);
    
    cout << "[";
    for (int i = 0; i < shuffled.size(); i++){
        if (i != shuffled.size()-1) {
            cout << shuffled[i];
            cout << ", ";
        } else{
            cout << shuffled[i];
        }
    }
    cout << "]" << endl;
     
     */
    
    // d.)
    
    // out-shuffle
    
    int iterations_out = 1;
    
    vector<int> iterate_out = shuffle(init_deck(), true);
    
    while (!check_deck(iterate_out)) {
        iterate_out = shuffle(iterate_out, true);
        iterations_out++;
    }
    
    string str_iterations_out = to_string(iterations_out);
    
    cout << "Durchgänge für out-shuffle: " + str_iterations_out << endl;
    
    // in-shuffle
    
    int iterations_in = 1;
    
    vector<int> iterate_in = shuffle(init_deck(), false);
    
    while (!check_deck(iterate_in)) {
        iterate_in = shuffle(iterate_in, false);
        iterations_in++;
    }
    
    string str_iterations_in = to_string(iterations_in);
    
    cout << "Durchgänge für in-shuffle: " + str_iterations_in << endl;
    
    return 0;
}
