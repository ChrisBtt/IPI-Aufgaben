//
//  main.cpp
//  woerter_zerwuerfeln
//
//  Created by logosal mac on 26.11.16.
//  Copyright © 2016 logosal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "text.hpp"

using namespace std;

vector<string> split_words(string s) {
    
    // checking if last char is space and delete if so
    
    char last = s[s.size()-1];
    
    if (last == ' ') {
        s = s.substr(0, s.size()-1);
    }
    
    // initalizing result-vector
    
    vector<string> res;
    
    // finding indices of spaces
    
    vector<int> space_index;
    
    for (int i = 0; i < s.size(); i++) {
        
        if (s[i] == ' ') {
            
            space_index.push_back(i);
            
        } else {
            continue;
        }
    }
    
    // seperating words
    
    vector<int> test;
    
    if (space_index == test) {
        res.push_back(s);
    } else {
        
        res.push_back(s.substr(0, space_index[0]));
        
        for (int i = 0; i < space_index.size(); i = i + 1) {
            
            string word;
            
            if (i != space_index.size() - 1) {
                word = s.substr(space_index[i] + 1, space_index[i+1] - space_index[i]);
            } else {
                word = s.substr(space_index[i] + 1);
            }
            
            res.push_back(word);
        }
    }
    
    /*
    // printing to console, debugging
     
    cout << "[";
    for (int i = 0; i < res.size(); i++){
        if (i != res.size()-1) {
            cout << res[i];
            cout << ", ";
        } else {
            cout << res[i];
        }
    }
    cout << "]" << endl;
    */
     
    return res;
}

string mix(string s) {
    
    // finding index first and last letter
    
    int first_alpha = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            first_alpha = i;
            break;
        } else {
            continue;
        }
    }
    
    int last_alpha = 0;
    
    for (int i = s.size()-1; i >= 0; i--) {
        if (isalpha(s[i])) {
            last_alpha = i;
            break;
        } else {
            continue;
        }
    }
    
    //cout << first_alpha << endl;
    //cout << last_alpha << endl;
    
    // substring first to last letter
    
    string to_mix = s.substr(first_alpha + 1, last_alpha - first_alpha - 1);
    
    //cout << to_mix << endl;

    // mix string
    
    string str_mixed = to_mix;
    
    random_shuffle(str_mixed.begin(),str_mixed.end());
    
    //cout << str_mixed << endl;
     
    // creating new word
    
    //cout << s.substr(0, first_alpha + 1) << endl;
    //cout << s.substr(last_alpha, s.size() - last_alpha) << endl;
    
    string new_word = s.substr(0, first_alpha + 1) + str_mixed + s.substr(last_alpha, s.size() - last_alpha);
    
    //cout << new_word << endl;
    
    return new_word;
}

string split_and_mix(string s) {
    
    // split string
    
    vector<string> s_splitted = split_words(s);
    
    // mixing words
    
    for (int i = 0; i < s_splitted.size(); i++) {
        s_splitted[i] = mix(s_splitted[i]);
    }
    
    // putting string together again
    
    string new_string;
    
    for (int i = 0; i < s_splitted.size(); i++) {
        if (i != s_splitted.size()-1) {
            new_string = new_string + s_splitted[i] + " ";
        } else {
            new_string = new_string + s_splitted[i];
        }
    }
    
    //cout << new_string << endl;
    
    return new_string;
}

int main() {
    
    /*
    split_words("hallo, wie geht es dir? ");
    
    mix("informatik...");
    
    split_and_mix("hallo, wie geht es dir heute?");
     */
    
    // testing of given strings
    
    cout << "Ursprünglicher Text in str1:" << endl;
    cout << str1 << endl;
    cout << endl;
    cout << "Ergebis von split_and_mix(str1):" << endl;
    cout << split_and_mix(str1) << endl;
    cout << endl;
    
    cout << "Ursprünglicher Text in str2:" << endl;
    cout << str2 << endl;
    cout << endl;
    cout << "Ergebis von split_and_mix(str2):" << endl;
    cout << split_and_mix(str2) << endl;
    cout << endl;
    
    cout << "Ursprünglicher Text in str3:" << endl;
    cout << str3 << endl;
    cout << endl;
    cout << "Ergebis von split_and_mix(str3):" << endl;
    cout << split_and_mix(str3) << endl;
    cout << endl;
    
    cout << "Ursprünglicher Text in str4:" << endl;
    cout << str4 << endl;
    cout << endl;
    cout << "Ergebis von split_and_mix(str4):" << endl;
    cout << split_and_mix(str4) << endl;
    cout << endl;
    
    cout << "Ursprünglicher Text in str5:" << endl;
    cout << str5 << endl;
    cout << endl;
    cout << "Ergebis von split_and_mix(str5):" << endl;
    cout << split_and_mix(str5) << endl;
    cout << endl;
    
    return 0;
}
