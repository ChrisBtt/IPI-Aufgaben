#include <iostream>
#include <cmath>

bool is_square(int n) {  //Aufgabenteil a
	double wurzel = std::sqrt(n);
	wurzel = std::floor(wurzel);
	wurzel *= wurzel;
	return ((wurzel-n) == 0) ? true : false;
	/* Wenn die Wurzel nicht aus den ganzen Zahlen kommt, 
	wird die Zahl abgerundet und ergibt quadriert nicht wieder n 
	wegen dem Rundungsfehler.
	*/
}

bool is_square_opt(int n) {  //Verbesserung von is_square für Teil b)

	if (n<0 && ((n%4) <= 1)) {  // schneller, oberflächlicher Test der Quadratzahl
		std::cout << "Keine gültige Quadratzahl eingegeben \n";
		return false;
	}
	double wurzel = std::sqrt(n);
	wurzel = std::floor(wurzel);
	wurzel *= wurzel;

	if ((wurzel-n) == 0) { // Quadratzahl liegt vor
						   // Textausgabe für Schleife in pythagoraen-triple sinnlos
		// std::cout << "Diese Zahl ist eine Quadratzahl \n";
		return true;
	} else {
		// std::cout << "Keine gültige Quadratzahl eingegeben \n";
		return false;
	}
}

void pythagorean_triple(int bmax) {

	// std::cout << "Schleife läuft" << "\n";  // Test des Funktionsaufrufs

	for (int b=1; b<=bmax; ++b) {  // Schleife für Integer b (lange Grundseite)
		if (is_square_opt(b)) {   // teste, ob b Quadratzahl ist
			// std::cout << b << "\n";  // Ausgabe zum Testen der Funktion

			for (int a=1; a<b; ++a) {  // Schleife für Integer a (kuerzere Grundseite)
				if (is_square_opt(a)) {  // teste, ob a Quadratzahl ist

					if (is_square_opt((b + a))) {
						std::cout << std::sqrt(b+a) << "," << std::sqrt(b)  << "," << std::sqrt(a) << "\n";
						break;
					}
				}
			}
		}
	}
}

int main() {
	int bmax = 400;  // Eingabe eines Maximalwerts für die längere Grundseite
	pythagorean_triple(bmax);  // Ausgabe aller Pythagoraeischen Tripel
	// is_square_opt(5);
	// is_square_opt(8);
	// is_square_opt(16);	
}