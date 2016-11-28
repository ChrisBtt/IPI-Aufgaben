#include <iostream>
#include <cmath>

double taylor_sin(double x_bogen) { // Taylor Naeherung des Sinus
	double sin = x_bogen - std::pow(x_bogen,3)/6;
	return sin;
	// Antwort 2a)vx_0 (Abweichung kleiner als e-06) = 9°
}

double x_bogen(double x_grad) { // Umrechnung von Grad Zahlen in Bogenmaß
	double pi = 3.14159265; //Implementierung einer Konstanten
	return x_grad * pi/180;
}

double fehler (double wert, double naeherung) { // Abweichung als absolute Funktion
	return std::abs(wert-naeherung);
}

double pump_sin (double sin_third) { // nutze das Additionstheorem des Sinus
	return 3*sin_third - 4*std::pow(sin_third,3);
	// Abweichung x_o = 15° (besser als taylor_sin())
}

double my_sin (double x) { // Winkel im Bogenmaß als Argument
	double pi = 3.14159265;
	int n = x/pi + 1;
	double x_eingeschraenkt = ((x <= pi) && x>= -pi) ? x : (x - n*pi);

	double result = (std::abs(x_eingeschraenkt) < x_bogen(10)) ? taylor_sin(x_eingeschraenkt) : 
						((std::abs(x_eingeschraenkt)<x_bogen(16) ? pump_sin(taylor_sin(x_eingeschraenkt/3)) : 
							my_sin(x_eingeschraenkt/3))) ;

	return result;
}

int main() {

// Ausgabe Aufgabe 2a)
	std::cout << "5 Grad" << std::endl ;  // gib den benutzten Winkel auf der command line aus
	std::cout << taylor_sin(x_bogen(5)) << std::endl ; // berechne die Taylor Näherung der Sinusfunktion des Winkels
	std::cout << std::sin(x_bogen(5)) << std::endl ; // berechne die Standardfunktion des Sinus für gegebenen Winkel 
	std::cout << fehler(std::sin(x_bogen(5)), taylor_sin(x_bogen(5))) << std::endl ; // berechne den Absolutbetrag des Fehlers

	std::cout << "10 Grad" << std::endl ;
	std::cout << taylor_sin(x_bogen(10)) << std::endl ;
	std::cout << std::sin(x_bogen(10)) << std::endl ;
	std::cout << fehler(std::sin(x_bogen(10)), taylor_sin(x_bogen(10))) << std::endl ;

	std::cout << "20 Grad" << std::endl ;
	std::cout << taylor_sin(x_bogen(20)) << std::endl ;
	std::cout << std::sin(x_bogen(20)) << std::endl ;
	std::cout << fehler(std::sin(x_bogen(20)), taylor_sin(x_bogen(20))) << std::endl ;

	std::cout << "45 Grad" << std::endl ;
	std::cout << pump_sin (taylor_sin (x_bogen(45/3))) << std::endl ;
	std::cout << std::sin(x_bogen(45)) << std::endl ;
	std::cout << fehler(std::sin(x_bogen(45)), pump_sin (taylor_sin (x_bogen(45/3)))) << std::endl ;
	
	std::cout << "90 Grad" << std::endl ;
	std::cout << taylor_sin(x_bogen(90)) << std::endl ;
	std::cout << std::sin(x_bogen(90)) << std::endl ;
	std::cout << fehler(std::sin(x_bogen(90)), taylor_sin(x_bogen(90))) << std::endl ;

	std::cout << "135 Grad" << std::endl ;
	std::cout << taylor_sin(x_bogen(135)) << std::endl ;
	std::cout << std::sin(x_bogen(135)) << std::endl ;
	std::cout << fehler(std::sin(x_bogen(135)), taylor_sin(x_bogen(135))) << std::endl ;

	std::cout << "180 Grad" << std::endl ;
	std::cout << taylor_sin(x_bogen(180)) << std::endl ;
	std::cout << std::sin(x_bogen(180)) << std::endl ;
	std::cout << fehler(std::sin(x_bogen(180)), taylor_sin(x_bogen(180))) << std::endl ;

	std::cout << "225 Grad" << std::endl ;
	std::cout << taylor_sin(x_bogen(225)) << std::endl ;
	std::cout << std::sin(x_bogen(225)) << std::endl ;
	std::cout << fehler(std::sin(x_bogen(225)), taylor_sin(x_bogen(225))) << std::endl ;

	std::cout << "270 Grad" << std::endl ;
	std::cout << taylor_sin(x_bogen(270)) << std::endl ;
	std::cout << std::sin(x_bogen(270)) << std::endl ;
	std::cout << fehler(std::sin(x_bogen(270)), taylor_sin(x_bogen(270))) << std::endl ;

	std::cout << "315 Grad" << std::endl ;
	std::cout << taylor_sin(x_bogen(315)) << std::endl ;
	std::cout << std::sin(x_bogen(315)) << std::endl ;
	std::cout << fehler(std::sin(x_bogen(315)), taylor_sin(x_bogen(315))) << std::endl ;

// Aufgabe 2c) + d)
	std::cout << "5 Grad" << "\n";
	std::cout << my_sin(x_bogen(5)) << "\n" ;
	std::cout << std::sin(x_bogen(5)) << std::endl ;
	std::cout << fehler(std::sin(x_bogen(5)), my_sin(x_bogen(5))) << std::endl ; 

	std::cout << "10 Grad" << "\n";
	std::cout << my_sin(x_bogen(10)) << "\n" ;
	std::cout << std::sin(x_bogen(10)) << std::endl ;
	std::cout << fehler(std::sin(x_bogen(10)), my_sin(x_bogen(10))) << std::endl ; 

	std::cout << "20 Grad" << "\n";
	std::cout << my_sin(x_bogen(20)) << "\n" ;
	std::cout << std::sin(x_bogen(20)) << std::endl ;
	std::cout << fehler(std::sin(x_bogen(20)), my_sin(x_bogen(20))) << std::endl ; 

	std::cout << "45 Grad" << "\n";
	std::cout << my_sin(x_bogen(45)) << "\n" ;
	std::cout << std::sin(x_bogen(45)) << std::endl ;
	std::cout << fehler(std::sin(x_bogen(45)), my_sin(x_bogen(45))) << std::endl ; 

	std::cout << "90 Grad" << "\n";
	std::cout << my_sin(x_bogen(90)) << "\n" ;
	std::cout << std::sin(x_bogen(90)) << std::endl ;
	std::cout << fehler(std::sin(x_bogen(90)), my_sin(x_bogen(90))) << std::endl ; 

	std::cout << "135 Grad" << "\n";
	std::cout << my_sin(x_bogen(135)) << "\n" ;
	std::cout << std::sin(x_bogen(135)) << std::endl ;
	std::cout << fehler(std::sin(x_bogen(135)), my_sin(x_bogen(135))) << std::endl ; 

	std::cout << "180 Grad" << "\n";
	std::cout << my_sin(x_bogen(180)) << "\n" ;
	std::cout << std::sin(x_bogen(180)) << std::endl ;
	std::cout << fehler(std::sin(x_bogen(180)), my_sin(x_bogen(180))) << std::endl ; 

	std::cout << "225 Grad" << "\n";
	std::cout << my_sin(x_bogen(225)) << "\n" ;
	std::cout << std::sin(x_bogen(225)) << std::endl ;
	std::cout << fehler(std::sin(x_bogen(225)), my_sin(x_bogen(225))) << std::endl ; 

	std::cout << "270 Grad" << "\n";
	std::cout << my_sin(x_bogen(270)) << "\n" ;
	std::cout << std::sin(x_bogen(270)) << std::endl ;
	std::cout << fehler(std::sin(x_bogen(270)), my_sin(x_bogen(270))) << std::endl ; 

	std::cout << "315 Grad" << "\n";
	std::cout << my_sin(x_bogen(315)) << "\n" ;
	std::cout << std::sin(x_bogen(315)) << std::endl ;
	std::cout << fehler(std::sin(x_bogen(315)), my_sin(x_bogen(315))) << std::endl ; 


	return 0;
}