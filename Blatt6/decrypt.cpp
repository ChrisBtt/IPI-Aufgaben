#include <iostream>  // std::cout
#include <string>  //std::string
#include <fstream>
#include <map>  // std::map
#include <cctype>  // 
#include <algorithm>  // std::transform()
#include <vector>  // std::vector

std::map <char, int> init_alpha() {

    std::map <char, int> map;

    for (char c = 'a'; c<= 'z'; ++c) {
        map.insert(std::pair <char, int> (c,0));
    }

    return map;
}

std::map <char, int> check_occurrence(std::string text) {

    std::map <char, int> map = init_alpha();  // initialize alphabetic map

    // loop through the string to check each character
    for (auto & text_element : text) {

        if (std::isalpha(text_element)) {
            map[std::tolower(text_element)] +=1;
        }
    }

    return map;
}

std::map <int, char> invert(std::map <char, int> map) {

    std::map <int, char> sorted;

    for (auto & element : map) {  // add new inverted tupel for each tupel in given map
        sorted.insert(std::pair<int, char> (element.second, element.first));
    }

    return sorted;
}
        // was heisst hier sorted[i->second] = i->first, wenn i iterator?


int main() {
// variables
    std::string text;
    std::string line;
    std::ifstream infile("encrypted_text.txt");  // external file with text

// include strings from external file to our own program
    while (infile) {  // save string per line in a string and add it to an other 
        std::getline(infile, line);
        text += line + "\n";
    }

    // std::transform(text.begin(), text.end(), text.begin(), ::tolower);  // transform all letters to lower case to handle them better

    std::map <char, int> map = check_occurrence(text);  // check occurrence through the defined function

    std::map <int, char> sorted = invert(map);  // this could be written in one line but would be quite confusing

// hardcoded standard apperence of alphabetic letters in texts
    std::vector <char> letters = {'z','j','q','x','k','v','b','y','g','p','w','f','m','c','u','l','d','r','h','s','n','i','o','a','t','e'};

// create a a key vector to translate the whole string
    std::map <char, char> decrypt;
    {
        int i = 0;  // created a counter variable to loop through the vector and the map at once
        for (auto & element : sorted) {
            decrypt.insert(std::pair<char, char> (element.second, letters[i]));
            decrypt.insert(std::pair<char, char> (std::toupper(element.second), std::toupper(letters[i])));
            i++;
        }
    }

// encrypt the given string by the created key vector 'decrypt'
    // do not use transform because of extra argument 'decrypt'
    for (auto &character : text) {
        if (std::isalpha(character)) {  // only convert the letters and leave out the rest
            character = decrypt[character];
        }
    }

// print out the decrypted text to read it easily
    std::cout << "\n" << text << "\n \n";

    return 0;
}




