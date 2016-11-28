#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Funktion zu Aufgabe 5.3a)
std::vector <std::string> split_words(std::string s) {  // separate a sentence into its single words

   std::vector <std::string> single_words;  // initialize vector to write results to it
   std::string substring = "";
   int last_space = 0;  // recognize last space to create right substring

   for (int i = 0; i<=s.size(); i++) {  
       if (s[i] == ' ' || i==s.size()) {  // find the space to separate string in front of it or the last one

           substring = s.substr(last_space, i - last_space);  // create substring and add it to the vector
           single_words.push_back(substring);  // this two lines could work in one, but it would be chaotic

           last_space = i+1;  // +1 to skip space in next string
       }
   }

   return single_words;
}

// Funktion zu Aufgabe 5.3b)
std::string mix(std::string s) {
    std::cout << "0";
    for (int i =0; i<s.size(); i++) { 
        std::cout << "1";
        if (std::isalpha(s[i])) {  // search for first letter in string
            std::cout << "2";
            for (int e = s.size()-1; e>=i; e-=1) {
                        std::cout << "3";
                if (std::isalpha(s[e])) {  // search for last letter in string
                        std::cout << "4";
                    if (e>i+2) {  // only words with size higher than 3 can be shuffled
                        // std::random_shuffle(s[i+1], s[e]);
                        std::cout << "5";
                        std::random_shuffle(s[i+1], s[e]);
                        return s;
                    }
                    break;
                }
            }
            break;
        }  
    }
    return s;
}


int main() {

    // std::string s = "Die Zug Fahrt endet nicht";  // print out single words of a sentence
//    for (int i = 0; i<split_words(s).size(); i++) {
//        std::cout << split_words(s)[i] << "\n \n";
//    }

    std:: string s = "Hausmeister";
    std::cout << mix(s) << "\n";

    return 0;
}
