#include <string>
#include <cassert>
#include <iostream>


bool is_email(std::string s) {

	int i = 0;   // variable to refer to chars at an index

	if (s.find('@') != std::string::npos) {  // check for existence of an @ sign
		std::string first_s = s.substr(0, s.find('@'));  // seperate string at @ sign
		std::string last_s = s.substr(s.find('@') +1);

		while (i<first_s.size()) {  // check first string for alowed characters and stop if condition is false
			if (std::isalpha(s[i]) || std::isdigit(s[i]) || s[i] == '.' || s[i] == '-' || s[i] == '_') {
				++i;
				continue;
			} else {
				std::cout << "Ungültige Zeichen in der eingegebenen Adresse \n";
				return false;
			}
		}

		if (last_s.find('@') == std::string::npos) {  // test string after @ sign for regular signs

			i = 0;  // reset counter variable
		
			if (std::isalpha(last_s[i]) || std::isdigit(last_s[i]) || last_s[i] == '-' || last_s[i] == '_') {
				++i;

			} else {
				std::cout << "Kein gültiges Zeichen nach dem @ Zeichen \n";
				return false;   // end function if sign after @ is dot 
			}


			while (i< last_s.size()) {	// check substring for regular signs with the dot

				if (std::isalpha(last_s[i]) || std::isdigit(last_s[i]) || last_s[i] == '.' || last_s[i] == '-' || last_s[i] == '_') {
					++i;

				} else {
					std::cout << "Ungültige Zeichen in der eingegebenen Adresse \n";
					return false;
				}
			}

			if (last_s.rfind('.') != std::string::npos) {

				last_s = last_s.substr(last_s.find('.')+1);

				if (last_s.size()>0) {  // check for regular sign after the last dot (can not be a dot)
					return true;

				} else {
					std::cout << "Ungültige Endung der eingegebenen Adresse \n";
					return false;
				}

			} else {  // end funtion if no dot after the @ sign is found
				std::cout << "Ungültige Endung der eingegebenen Adresse \n";
				return false;
			}

		} else {  // end function if another @ sign is found
			std::cout << "Zu viele @ Zeichen in der eingegebenen Adresse \n";
			return false;
		}
	} else {			
		std::cout << "Kein @ Zeichen in der eingegebenen Adresse \n";
		return false;
	}
}



int main() {

// accepted email addresses 
	assert(is_email("chris-blattgerste@gmx.de"));
	assert(is_email("chris-blattgerste@stud.uni-heidelberg.de"));
	assert(is_email("chrisblattgerste@gmx.de"));
	assert(is_email("c_h_r_I.s@gmx.de"));
	assert(is_email("chris-blattgerste@gmx.de"));
	assert(is_email("chris-blattgerste@gmx.de"));

// false email addresses cause an error in accept() test

	// assert(is_email("chris@blattgerste@gmx.de"));
	// assert(is_email("chrisblattgerste@.gmx.de"));
	// assert(is_email("@gmx.de"));
	// assert(is_email("chrislatte@gmxde"));
	// assert(is_email("chris-blattgerste@."));
	// assert(is_email("chris-blattgerste@gmx-de"));

// enter your own mail address if you want

	std::string email = "";
	std::cout << "Bei Eingabe der (1): Eingabe der gewünschten Adresse , sonst: Abbruch \n";
	std::cin >> email;
	std::cout << "\n";

	if (email == "1") {
		std::cout << "Bitte geben Sie eine Email-Adresse ein: \n";
		std::cin >> email;  // Eingabe der zu prüfenden Adresse

		if (is_email(email)) {  // Ausgabe des Ergebnisses der Funktion is_email
			std::cout << "\nDer eingegebene String ist eine gültige Email-Adresse. \n\n";
		} else {
			std::cout << "\nDer eingegebene String ist keine gültige Email-Adresse. \n\n";
		}
	}

	return 0;
}