//
//  main.cpp
//  decrypt
//
//  Created by logosal mac on 02.12.16.
//  Copyright © 2016 logosal. All rights reserved.
//


# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include <algorithm>
# include <vector>

using namespace std;

int main() {
    
    // a.)
    
    // reading file
    
    ifstream infile ("encrypted_text.txt");
    string text;
    string line;
    while (infile) {
        getline(infile, line);
        text += line + "\n";
    }
    
    // b.)
    
    map<char, int> counts;
    int i;
    
    for(i = 0; i <26; i++) {
        counts.insert(pair<char, int>('a'+i, 0));
    }
    
    // transforming text lowercase
    
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    
    // counting letters

    for (auto iter = counts.begin(); iter != counts.end(); iter++) {
        (*iter).second = count(text.begin(), text.end(), (*iter).first);
    }
    
    // c.)
    
    // sorted map
    
    map<int, char> sorted;
        
    for (auto iter1 = counts.begin(); iter1 != counts.end(); iter1++) {
        sorted.insert(pair<int, char>((*iter1).second, (*iter1).first));
    }
    
    // reference vector
    
    vector<char> letters = {'z','j','q','x','k','v','b','y','g','p','w','f','m','c','u','l','d','r','h','s','n','i','o','a','t','e'};

    // d.)
    
    map<char, char> decrypt;
    
    auto iter_sorted = sorted.begin();
    auto iter_letters = letters.begin();
        
    for(;iter_sorted != sorted.end(); iter_sorted++, iter_letters++) {
        decrypt.insert(pair<char, char>((*iter_sorted).second, *iter_letters));
    }
    
    // e.)
    
    // decrypting text
    
    for(auto iter = text.begin(); iter != text.end(); iter++) {
        if (isalpha(*iter)) {
            *iter = decrypt.at(*iter);
        } else {
            continue;
        }
    }
    
    // writing in new file
    
    ofstream outfile("decrypted_text.txt");
    outfile << text;
    
    return 0;
}

