#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <algorithm>

#include <locale>

std::string read_file(std::string filename)
{
    // Datei zum Lesen oeffnen
    std::ifstream infile(filename);

    // Daten einlesen
    std::stringstream textstream;
    textstream << infile.rdbuf();

    // Inhalt als std::string zurueckgeben
    return textstream.str();
}

void write_file(std::string filename, std::string const & text)
{
    // Datei zum Schreiben oeffnen
    std::ofstream outfile(filename);

    // Text in Datei schreiben
    outfile << text;
}

struct Character
{
    char encrypted;
    char clear;
    int count;
};

int biggest_code(std::string const & text) {

    int highest_ascii;  // create integer .. 

    for ( auto & letter : text) {  // .. to save highest ascii integer in text

        if ( (int) letter > highest_ascii) {  // type conversion to get ascii code of each letter and compare it to the highest
            highest_ascii = (int) letter;
        }
    }

    return highest_ascii;
}

// Aufgabe 8.4b)
std::vector <Character> existing_character(std::string & text) {

    std::vector <Character> characters;

    for (char & letter : text) {  // find first letter in given text and add it in first struct to vector

        if (std::isalpha(letter)) {

            char first_letter = std::tolower(letter);
            characters.push_back({first_letter, first_letter, 0});
            break;
        }

    }

    for (char & letter : text) {  // iterate each letter in text

        if (!std::isalpha(letter)) // and check for alpha
            { continue; }

        bool new_index = true;

        for (auto & index : characters) {  // iterate over the existing indizes in character

            if (index.clear == std::tolower(letter)) {  // check if index (char) already exists
                new_index = false;
            }
        }

        if (new_index) {  // push_back new struct to the end of the vector (not sorted)
            char new_letter = std::tolower(letter);
            characters.push_back({new_letter, new_letter, 0});
        }
    }

    return characters;
}

// Aufgabe 8.4c)
std::vector <Character> check_occurrence(std::string & text) {

    std::vector <Character> decrypt_key = existing_character(text);  // initialize vector with existing characters in text

    // loop through the string to check each character
    for (auto & text_element : text) {

        if (std::isalpha(text_element)) {
            
            for (auto & item : decrypt_key) {

                if (item.clear == std::tolower(text_element)) {

                    item.count ++;
                    break;

                }
            }
        }
    }

    return decrypt_key;
}

// Aufgabe 8.4d)
std::vector <Character> create_key_vector(std::vector <Character> characters, std::string haeufigkeit) {

    int index = 0;
    for (auto & element : characters) {  // swap each characters.clear character with the one from vector haeufigkeit

        element.clear  = haeufigkeit[index];
        index++;
    }

    return characters;
}

std::string decrypted (std::string & text, std::vector <Character> & characters) {

    for (char & letter : text) {
        if (!std::isalpha(letter)) continue;  // if letter is no alphabetic skip swaping letter

        if (std::isupper(letter)) {
            
            for (auto & element : characters) {

                if (element.encrypted == std::tolower(letter)) {
                    letter = std::toupper(element.clear);
                    break;
                }
            }
        } else {

            for (auto & element : characters) {

                if (element.encrypted == letter) {
                    letter = element.clear;
                    break;
                }
            }
        }
    }

    return text;
}



int main() {

    // std::locale::global(std::locale("de_DE.UTF-8"));
    // Datei einlesen
    std::string text = read_file("verschluesselt_ascii.txt");

    // Ihre Loesung hier

    std::cout << biggest_code(text) << " das entspricht:" << (char) biggest_code(text) << " \n";

    std::vector <Character> characters = check_occurrence(text);  // create a vector as a decrypt characters as defined in the function above

    std::sort(characters.begin(), characters.end(), [] (Character a, Character b) {return a.count < b.count;});  // refer to the contiguous structs.count to compare
    characters = create_key_vector(characters, read_file("buchstaben_haeufigkeit_ascii.txt"));

    for (auto & item : characters) {
        std::cout << item.count << "  is " << item.encrypted << ": " << item.clear << "\n";
    }

    text = decrypted(text, characters);

    // Ergebnis in Datei schreiben

    write_file("entschluesselt.txt", text);

    return 0;
}


