//
//  main.cpp
//  archimedes
//
//  Created by logosal mac on 17.12.16.
//  Copyright © 2016 logosal. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>

using namespace std;

// a.)

float side_length_in(int n) {
    
    // check if #corner higher or equal 4 and even
    
    if (n < 4 || n % 2 != 0) {
        return 0.0f;
    }
    
    // calculationg s2n
    
    if (n==4) {
        return pow(2.0f, 0.5f);
    } else {
        return pow(2.0f - pow(4.0f - pow(side_length_in(n/2), 2.0f), 0.5f), 0.5f);
    }
}

float side_length_out(int n) {
    
    // check if #corner higher or equal 4 and even
    
    if (n < 4 || n % 2 != 0) {
        return 0.0f;
    }
    
    // calculationg t2n
    
    if (n==4) {
        return 2.0f;
    } else {
        return (2.0f/side_length_out(n/2))*(pow(4.0f+pow(side_length_out(n/2), 2.0f), 0.5f)-2.0f);
    }
}

// b.)

double side_length_in2(int n) {
    
    // check if #corner higher or equal 4 and even
    
    if (n < 4 || n % 2 != 0) {
        return 0.0;
    }
    
    // calculationg s2n
    
    if (n==4) {
        return pow(2.0, 0.5);
    } else {
        return pow(2.0 - pow(4.0 - pow(side_length_in2(n/2), 2.0), 0.5), 0.5);
    }
}

double side_length_out2(int n) {
    
    // check if #corner higher or equal 4 and even
    
    if (n < 4 || n % 2 != 0) {
        return 0.0;
    }
    
    // calculationg t2n
    
    if (n==4) {
        return 2.0;
    } else {
        return (2.0/side_length_out2(n/2))*(pow(4.0+pow(side_length_out2(n/2), 2.0), 0.5)-2.0);
    }
}

int main() {
    
    // a.)
    
    int sides = 4;
    
    for (int doubles = 0; doubles < 14; doubles++) {
        
        // calculating limits
        
        float lower_limit = (sides/2.0f)*side_length_in(sides);
        float upper_limit = (sides/2.0f)*side_length_out(sides);
        
        // printing to console
        
        cout << endl;
        cout << "Unterer Schätzwert: " << setprecision(10) << lower_limit << endl;
        cout << "Abweichung von PI: " << setprecision(10) << M_PI - lower_limit << endl;
        cout << "Oberer Schätzwert: " << setprecision(10) << upper_limit << endl;
        cout << "Abweichung von PI: " << setprecision(10) << upper_limit - M_PI << endl;
        cout << endl;
        
        sides = sides * 2;
    }
    
    // b.)
    
    int sides2 = 4;
    
    for (int doubles = 0; doubles < 14; doubles++) {
        
        // calculating limits
        
        float lower_limit = (sides2/2.0)*side_length_in2(sides2);
        float upper_limit = (sides2/2.0)*side_length_out2(sides2);
        
        // printing to console
        
        cout << endl;
        cout << "Unterer Schätzwert: " << setprecision(10) << lower_limit << endl;
        cout << "Abweichung von PI: " << setprecision(10) << M_PI - lower_limit << endl;
        cout << "Oberer Schätzwert: " << setprecision(10) << upper_limit << endl;
        cout << "Abweichung von PI: " << setprecision(10) << upper_limit - M_PI << endl;
        cout << endl;
        
        sides2 = sides2 * 2;
    }

    return 0;
}

/*
 
 // a.)
 
 Ab der 7. Iteration wird die Annäherung wieder schlechter, dies liegt an den Rundungsfehlern, die bei der Berechnung mit dem Typ "float" gemacht werden. Außerdem ist zu beobachten, dass die Annäherungen irgendwann den Wert von PI über- bzw. untersteigen, also negative Abweichungen auftreten, die Ursache ist dieselbe.
 
 // b.)
 
 Die Annäherungen sind jetzt bis zur 11 Itertion sehr gut, erst dann wird die untere Schätzung größer als PI. Ursache sind wieder Rundungsfehler die auftreten.
 
 */
