#include <cassert>
#include <iostream>
#include <string>
#include <cctype>
//std::string eingabe;
//std::string alllow;

// to_lower macht aus allen Großbuchstaben Kleinbuchstaben
std::string to_lower(std::string s){
	int a = s.size() - 1;
	std::string news = "";
	for(int i=0; i<=a; i++){
		news += std::tolower(s[i]);
	}
	return news;
}
// letters_only filtert aus dem String nur die Buchstaben herraus
std::string letters_only(std::string s){
	std::string news = "";
	for(unsigned int i=0; i<=s.size() - 1; i++){
		bool c = std::isalpha(s[i]);
			if (c == 1){
				news += s[i];
				continue;
			}
		}

	return news;
}

// is_palindrom testet ob es sich bei dem String um ein Palindrom handelt, dazu sollten die Funktionen letters_only und to_lower bereits darauf angewandt worden sein
bool is_palindrom(std::string s){
	bool obPalindrom = true;
	int e = s.size() - 1;
	for(int i=0; i<=e; i++){
		if (s[i]==s[e]) {  //es wird geschaut ob das i te und das e - i te Element gleich sein (wobei e die größe des Strings - 1 ist)
			 //wenn es für ein Buchstabenpaar nicht passt, wird "obPalindrom" false gesetzt und "Dein Wort ist leider kein Palindrom" ausgegeben
			continue;
			
			} else {
				obPalindrom = false;
				std::cout << "Dein Wort ist leider kein Palindrom" << std::endl;
				return obPalindrom;
			}
		e--;
	}
	std::cout<<"Dein Wort ist ein Palindrom!"<<std::endl; //falls es für alle Buchstabenpaar passt, wird: "Dein Wort ist ein Palindrom!" ausgegeben
	return obPalindrom;
}

int main(int argc, char **argv) {
	//der erste Teil der Aufgabe
	/*std::cout<<"Gib bitte ein Wort oder einen Satz ein: \n";
	std::string s;
	std::getline(std::cin, s);

	//std::cin>>eingabe;

	std::string nurbuchstaben = letters_only(s);
	alllow = to_lower(nurbuchstaben);
	bool a = is_palindrom(alllow);*/

	//der Test ob das Programm funktioniert, für verschiedene Worte
	assert(is_palindrom(to_lower(letters_only("Anna"))) == true);
	assert(is_palindrom(to_lower(letters_only("Ein Neger mit Gazelle zagt im Regen nie"))) == true);
	assert(is_palindrom(to_lower(letters_only("Christoph"))) == false);
	assert(is_palindrom(to_lower(letters_only("IPI"))) == true);
	assert(is_palindrom(to_lower(letters_only("Aufgabe"))) == false);
	assert(is_palindrom(to_lower(letters_only("Editor"))) == false);
	assert(is_palindrom(to_lower(letters_only("Pflanze"))) == false);
	assert(is_palindrom(to_lower(letters_only("Trug Tim eine so helle Hose nie mit Gurt?"))) == true);

}
