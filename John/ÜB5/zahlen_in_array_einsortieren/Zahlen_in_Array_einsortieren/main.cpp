//
//  main.cpp
//  Zahlen_in_Array_einsortieren
//
//  Created by logosal mac on 25.11.16.
//  Copyright © 2016 logosal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    
    // initalizing
    
    vector<int> numbers(1,0);
    
    int in_number = 0;
    
    // user interaction
    
    while (true){
        cout << "Bitte gib eine positive, ganze Zahl ein: " << endl;
        cin >> in_number;
        
        // checking if number positive
        
        if (in_number < 0) {
            break;
        }
        
        // inserting number at right position, starting at right end if number already in vector
        
        for (int i = numbers.size()-1; i >= 0; i = i-1){
            if (numbers[i] <= in_number){
                numbers.insert(numbers.begin()+i+1, in_number);
                break;
            } else{
                continue;
            }
        }
    }
    
    // printing to console
    
    cout << "[";
    for (int i = 0; i < numbers.size(); i++){
        if (i != numbers.size()-1) {
            cout << numbers[i];
            cout << ", ";
        } else{
            cout << numbers[i];
        }
    }
    cout << "]" << endl;
        
    return 0;
}


