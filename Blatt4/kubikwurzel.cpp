#include <iostream>
#include <cassert>
#include <cmath>

/* Abbruchbedingung: y^3-zahl < 1e-15, also muss die Differenz zwischen berechneter Kubikwrzel hoch drei und der Ursprungszahl muss sehr klein werden.
   Iterationsvorschrift: mit f(x) = x^3-y und f'(x) = 3x^2 folgt: x_1 = (2*x_0 + y/x^2)/3
 */

double cbrt (double zahl) {
//	if (zahl<0.0) {
//		std::cout << "Wurzel aus negativer Zahl \n" ;
//		return -1.0;
//	}
    
	if (zahl==0.0) {
		return 0.0;
	}
	double abbruch = 1e-15; // Genauigkeit der Iteration
	double y = zahl;  // initial guess als Ergebnis
	while (std::abs(std::pow(y,3)-zahl) > abbruch) {
		y = (2*y+zahl/y/y)/3;
	}
	return y;
}

int main() {
//	double anfangswert;
//	std::cin >> anfangswert;
//	std::cout << cbrt(anfangswert) << "\n";
    
    assert(cbrt(8) == std::pow(8,1.0/3.0));
    assert(cbrt(27) == std::pow(27,1.0/3.0));

    
    std::cout << cbrt(-8) << "\n";
    std::cout << -cbrt(8) << "\n";
    // Results are the same as predigted

	return 0;
}
