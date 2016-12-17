#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <locale>
#include <codecvt>
#include <algorithm>

using namespace std;

wstring read_file(string filename)
{
    // Datei zum Lesen von wchar_t oeffnen
    wifstream infile(filename);
    
    // Daten einlesen
    wstringstream textstream;
    textstream << infile.rdbuf();
    
    // Inhalt als wstring zurueckgeben
    return textstream.str();
}

void write_file(string filename, wstring const & text)
{
    // Datei zum Schreiben von wchar_t oeffnen
    wofstream outfile(filename);
    
    // Text in Datei schreiben
    outfile << text;
}

struct Character
{
    wchar_t encrypted;
    wchar_t clear;
    int count;
};

// a.)

int biggest_code(wstring const & text) {
    int biggest_code = 0;
    for (auto iter = text.begin(); iter != text.end(); iter++) {
        if(*iter>biggest_code) {
            biggest_code=*iter;
        }
    }
    return biggest_code;
}

int main()
{
#if defined(_MSC_VER)
    // unter Windows/Visual Studio: locale fuer Deutsch definieren
    locale german("de-de");
#elif defined(__APPLE__)
    // unter MacOS: locale fuer Deutsch mit UTF-8 definieren
    locale german("de_DE.UTF-8");
#elif defined(__linux__)
    // unter Linux: locale fuer sprachunabhaengiges UTF-8 definieren
    locale german("C.UTF-8");
#else
    // sonst: verwende die Spracheinstellungen des Betriebssystems
    locale german("");
#endif
    
    // Konverter zwischen UTF-8 (Zeichentyp in der Datei) und
    // wchar_t (Zeichentyp im Programm) erzeugen
    locale codec(german, new codecvt_utf8<wchar_t>);
    
    // Konverter global setzen (er wird ab jetzt von allen
    // Ein-/Ausgabeoperationen in diesem Programm verwendet)
    locale::global(codec);
    
    // Datei einlesen
    wstring text = read_file("verschluesselt_utf8.txt");
    
    // Ihre Loesung hier
    
    // b.)
    
    vector<Character> characters(biggest_code(text));
    
    // Initialisierung Array
    
    for (int i = 0; i < characters.size(); i++) {
        characters[i].encrypted = i;
        characters[i].clear = i;
        characters[i].count = 0;
    }
    
    // c.)
    
    for (auto iter = text.begin(); iter != text.end(); iter++) {
        characters[tolower(*iter, german)].count++;
    }
    
    // d.)
    
    sort(characters.begin(), characters.end(), [](const Character &a, const Character &b) {return a.count < b.count;});
    
    // e.)
    
    // Datei einlesen
    
    wstring rate = read_file("buchstaben_haeufigkeit_utf8.txt");
    
    // Iterieren über Array
    
    int c = 0;
    
    for (auto iter = characters.begin(); iter != characters.end(); iter++) {
        if ((*iter).count != 0 && islower((*iter).encrypted, german)) {
            (*iter).clear = rate[c];
            c++;
        }
    }
    
    // f.)
    
    sort(characters.begin(), characters.end(), [](const Character &a, const Character &b) {return a.encrypted < b.encrypted;});
    
    // g.)
   
    for(auto iter = text.begin(); iter != text.end(); iter++) {
        if(isupper(*iter, german)) {
            *iter = tolower(*iter, german);
            *iter = characters[*iter].clear;
            *iter = toupper(*iter, german);
        }
        else {
            *iter = characters[*iter].clear;
        }
    }

    // Ergebnis in Datei schreiben
    write_file("entschluesselt.txt", text);
}


