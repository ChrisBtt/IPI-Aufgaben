#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <locale>
#include <codecvt>
#include <algorithm>

std::wstring read_file(std::string filename)
{
    // Datei zum Lesen von wchar_t oeffnen
    std::wifstream infile(filename);

    // Daten einlesen
    std::wstringstream textstream;
    textstream << infile.rdbuf();

    // Inhalt als std::wstring zurueckgeben
    return textstream.str();
}

void write_file(std::string filename, std::wstring const & text)
{
    // Datei zum Schreiben von wchar_t oeffnen
    std::wofstream outfile(filename);

    // Text in Datei schreiben
    outfile << text;
}

struct Character
{
    wchar_t encrypted;
    wchar_t clear;
    int count;
};

int biggest_code(std::wstring const & text);

int main()
{
#if defined(_MSC_VER)
    // unter Windows/Visual Studio: locale fuer Deutsch definieren
    std::locale german("de-de");
#elif defined(__APPLE__)
    // unter MacOS: locale fuer Deutsch mit UTF-8 definieren
    std::locale german("de_DE.UTF-8");
#elif defined(__linux__)
    // unter Linux: locale fuer sprachunabhaengiges UTF-8 definieren
    std::locale german("C.UTF-8");
#else
    // sonst: verwende die Spracheinstellungen des Betriebssystems
    std::locale german("");
#endif

    // Konverter zwischen UTF-8 (Zeichentyp in der Datei) und
    // wchar_t (Zeichentyp im Programm) erzeugen
    std::locale codec(german, new std::codecvt_utf8<wchar_t>);

    // Konverter global setzen (er wird ab jetzt von allen
    // Ein-/Ausgabeoperationen in diesem Programm verwendet)
    std::locale::global(codec);

    // Datei einlesen
    std::wstring text = read_file("verschluesselt_utf8.txt");

    // Ihre Loesung hier

    // Ergebnis in Datei schreiben
    write_file("entschluesselt.txt", text);
}


