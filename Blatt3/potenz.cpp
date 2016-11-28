#include <iostream>
#include <string>
#include <cassert>
#include <cmath>

double sq (double x) {
	return x * x;
}

double power (double x, int n) {
	int n_even = (n % 2 == 0) ? 1 : 0; // bei 1 ist n gerade
	return ((n == 1)? x :
		 (n_even == 1) ? sq(power(x, n/2)) : 
		 	x*power(x, n-1));
}
// Für den Fall n gerade wäre die Schreibweise x^(n/2)*x^(n/2) kontraproduktiv.
// Das Ergebnis wäre das gleiche, doch die Berechnung braucht noch genau so 
// viele Multiplikationen, wie die ausgeschrieben Variante. Die Verkürzung wird nur
// durch die Verwendung der sg()-Funktion erreicht.


int main() {
	std::cout << std::to_string(power(2,8)) << std::endl ;
	std::cout << std::to_string(std::pow(2,8)) << std::endl ;

	std::cout << std::to_string(std::pow(-2,8)) << std::endl ;
	std::cout << std::to_string(power(-2,8)) << std::endl ;

	std::cout << std::to_string(std::pow(1,100)) << std::endl ;
	std::cout << std::to_string(power(1,100)) << std::endl ;

	std::cout << std::to_string(std::pow(5,5)) << std::endl ;
	std::cout << std::to_string(power(5,5)) << std::endl ;

	std::cout << std::to_string(std::pow(3.1415,3)) << std::endl ;
	std::cout << std::to_string(power(3.1415,3)) << std::endl ;

	std::cout << std::to_string(std::pow(0,13)) << std::endl ;
	std::cout << std::to_string(power(0,13)) << std::endl ;

	std::cout << std::to_string(std::pow(2/3, 3)) << std::endl ;
	std::cout << std::to_string(power(2/3, 3)) << std::endl ;

	std::cout << std::to_string(std::pow(-0.1111,5)) << std::endl ;
	std::cout << std::to_string(power(-0.1111,5)) << std::endl ;

	return 0;
}