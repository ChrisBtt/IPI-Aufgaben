//
//  main.cpp
//  format_numbers
//
//  Created by logosal mac on 02.12.16.
//  Copyright © 2016 logosal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include "format_numbers.hpp"
#include <stdio.h>
#include <ctype.h>

using namespace std;

// a.)

// rounding function

int rd(double x) {
    
    double sign;
    
    if (x < 0.0) {
        sign = -1.0;
    } else {
        sign = 1.0;
    }
    
    x = x + sign * 0.5;
    
    int res = (int)x;
    
    return res;
}

// transformation function

vector<int> vec_to_int (vector<double> v) {
    
    vector<int> result(v.size());
    
    transform (v.begin(), v.end(), result.begin(), rd);
    
    return result;
    
}

// b.)

// rounding function

double rd_2(double x) {
    
    x = x * 100;
    x = rd(x);
    double res = x / 100;
    
    return res;
}

vector<double> vec_rounded(vector<double> v) {
    
    vector<double> result(v.size());
    
    transform (v.begin(), v.end(), result.begin(), rd_2);
    
    return result;
    
}

// c.)

string double_to_string(double x) {
    
    // find sign
    
    double sign;
    
    if (x < 0.0) {
        sign = -1.0;
    } else {
        sign = 1.0;
    }
    
    x = sign * x;
    
    // rounding
    
    x = rd_2(x);
    
    // avoiding -0.00
    
    if (x == 0.00) {
        sign = 1.0;
    }
    
    // converting to string & make sure two decimals
    
    string x_dot_nill = to_string(x).substr(to_string(x).size()-7);
    string x_dot = x_dot_nill.substr(0, 3);
    int dot_index = to_string(x).find('.');
    string x_to_dot = to_string(x).substr(0, dot_index);
    string res = x_to_dot + x_dot;
    
    // inserting '
    
    if (x_to_dot.size() < 4) {
        res = res;
    } else {
        res.insert(dot_index - 3, "'");
        while (res.find("'") > 3) {
            res = res.insert(res.find("'") - 3, "'");
        }
    }
    
    // making sure that length not above 16
    
    if (sign > 0 && res.size() > 16) {
        res = res.substr(res.size()-16);
    }
    
    if (sign < 0 && res.size() > 15) {
        res = res.substr(res.size()-15);
    }
    
    // number spaces to insert
    
    int spaces;
    
    if (sign < 0) {
        spaces = 15 - res.size();
    } else {
        spaces = 16 - res.size();
    }
    
    // adding spaces
    
    if (res.size() == 16) {
        res = res;
    } else {
        if (sign > 0) {
            while (res.size() < 16) {
                res.insert(0, " ");
            }
        } else {
            while (res.size() < 15) {
                res.insert(0, " ");
            }
        }
    }
    
    // inserting sign
    
    if (sign < 0) {
        res =  res.insert(spaces, "-");
    }
    
    return res;
}

// d.)

vector<string> format_numbers(vector<double> v) {
    
    vector<string> result(v.size());
    
    transform (v.begin(), v.end(), result.begin(), double_to_string);
    
    return result;
}

int main() {
    
    // e.)
    
    vector <string> numbers_str = format_numbers(numbers);
    
    // printing to console

    for (int i = 0; i < numbers_str.size(); i++){
        cout << numbers_str[i] << endl;
    }
    
    return 0;
}

