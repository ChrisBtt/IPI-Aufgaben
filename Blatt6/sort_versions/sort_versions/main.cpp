//
//  main.cpp
//  sort_versions
//
//  Created by logosal mac on 02.12.16.
//  Copyright © 2016 logosal. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cassert>
#include "sort_versions.hpp"

using namespace std;

// a.)

vector<int> split_version(string version) {
    
    // Returning vector
    
    vector<int> numbers;
    
    // deviding in substrings and push_back as integers
 
    while(version.find(".") != std::string::npos) {
        string version_substr = version.substr(0, version.find(".")).c_str();
        numbers.push_back(atoi(version.substr(0, version.find(".")).c_str()));
        version = version.substr(version.find(".") + 1);
    }
    numbers.push_back(atoi(version.c_str()));
    
    return numbers;
}

// b.)

bool version_less(string v1, string v2) {
    
    vector<int> n1 = split_version(v1);
    vector<int> n2 = split_version(v2);
    
    // checking if identical
    
    if (n1 == n2) {
        return false;
    }
    
    auto iter1 = n1.begin();
    auto iter2 = n2.begin();
    while(iter1 != n1.end()) {
        // n2 shorter then n1
        if(iter2 == n2.end()) {
            return false;
            break;
        }else if (*iter1 > *iter2) {
            return false;
            break;
        }else if (*iter1 < *iter2) {
            return true;
            break;
        }else {
            iter1++;
            iter2++;
            continue;
        }
    }
    
    return true;
}

int main() {
    
    // c.)
    
    sort(versions.begin(), versions.end(), [](string a, string b) {return version_less(a, b);});
    
    for(auto i = versions.begin(); i != versions.end(); i++) {
        cout << *i << endl;
    }
    
    return 0;
}
