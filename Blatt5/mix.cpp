#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "text.hpp"

// Funktion zu Aufgabe 5.3a)
using namespace std;

std::vector <std::string> split_words(std::string s) {  // separate a sentence into its single words

   std::vector <std::string> single_words;  // initialize vector to write results to it
   std::string substring = "";
   int last_space = 0;  // recognize last space to create right substring

   for (int i = 0; i<=s.size(); i++) {
       if (s.compare(i,1," ") == 0 || i==s.size()) {  // find the space to separate string in front of it or the last one

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
            for (int e = s.size()-1; e>=i+1; e-=1) {
                        std::cout << "3";
                if (std::isalpha(s[e])) {  // search for last letter in string
                        std::cout << "4";
                    if (e>i+2) {  // only words with size higher than 3 can be shuffled
                        
                        std::cout << "5";
                        std::string test = "";
                        for (int a = i+1; a<=e-1; ++a){
                        	test += s[a];
                        	std::cout<<"\n"<<test<<"\n";

                        }
                        //test entspricht nun dem "zu shufflendem" Bereich
                        std::cout<<"\n"<<test<<"\n";
                        std::random_shuffle(test.begin(), test.end());
                        std::string newstring = "";
                        //den neuen String zusammen setzten aus den einzelnen Elementen
                        for (int a = 0; a<i+1; ++a){
                                              newstring += s[a]; 
                                                 }
                        for (int a = i; a<=e-2; ++a){
                                              newstring += test[a-i];
                                                 }
                        for (int a = e; a<=s.size()-1; ++a){
                                                newstring += s[a];
                                                 }

                        return newstring;
                    }
                    break;
                }
            }
            break;
        }
    }
    return s;
}

//Aufgabe 5c)
std::string split_and_mix(std::string s){
	std::vector<string> mystringvec = split_words(s);
	std::string ergebnis ="";
	for (int i = 0; i < mystringvec.size(); ++i) {
		//cout << mystringvec[i] << endl;
		ergebnis += mix(mystringvec[i]);
		if(i<mystringvec.size()){ //Sinn: am Ende soll kein Leerzeichen stehen
			ergebnis += " ";

		}
	}

	return ergebnis;
}


int main() {
	std::string newstr1;
	std::string newstr2;
	std::string newstr3;
	std::string newstr4;
	std::string newstr5;
	newstr1 = split_and_mix(str1);
	newstr1 = split_and_mix(str2);
	newstr1 = split_and_mix(str3);
	newstr1 = split_and_mix(str4);
	newstr1 = split_and_mix(str5);
	std::string brandnewstr1;
	std::string brandnewstr2;
	std::string brandnewstr3;
	std::string brandnewstr4;
	std::string brandnewstr5;
	brandnewstr1 = split_and_mix(newstr1);
	brandnewstr2 = split_and_mix(newstr2);
	brandnewstr3 = split_and_mix(newstr3);
	brandnewstr4 = split_and_mix(newstr4);
	brandnewstr5 = split_and_mix(newstr5);
	cout<<newstr1<<"\n";
	cout<<newstr2<<"\n";
	cout<<newstr3<<"\n";
	cout<<newstr4<<"\n";
	cout<<newstr5<<"\n";
	cout<<brandnewstr1<<"\n";
	cout<<brandnewstr2<<"\n";
	cout<<brandnewstr3<<"\n";
	cout<<brandnewstr4<<"\n";
	cout<<brandnewstr5<<"\n";
    return 0;
}
//Aus unbekanntem Grund konnte auf str1, ... nicht zugegriffen werden, daher war ein Test mit diesen nicht möglich. 
