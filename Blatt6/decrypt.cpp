#include <iostream>
#include <string>
#include <fstream>
#include <map>

std::map <char, int> init_alpha() {

    std::map <char, int> map;

    for (char c = 'a'; c<= 'z'; ++c) {
        map.insert(std::pair <char, int> (c,0));
    }

    return map;
}


int main() {

    std::map <char, int> map = init_alpha();
    for ( auto & element : map) {
        std::cout << element.first << ": " << element.second << std::endl;
    }

    
    // std::ifstream infile("encrypted_text.txt");  // Datei mit einzulesendem Text
    // std::string text;  // initialisiere Strings zum Einlesen
    // std::string line;
    // while (infile) {  // Zeilenweise Speichern der Textdatei in einem String
    //     std::getline(infile, line);
    //     text += line + "\n";
    // }

    // std::transform(text.begin(), text.end(), text.begin(), std::tolower);  // transform all letters to lower case to handle them better

    // std::map <char, int> counts;  // initialize empty map




    // for (auto iter = text.begin(); iter != text.end(); ++iter) {
    //     char c = *iter;
    //     if (std::map.first)
    // }

    return 0;
}