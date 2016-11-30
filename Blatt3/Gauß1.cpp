#include <iostream>
#include <string>
#include <cassert>

std::string easter (int year) {
	int a = year % 19 ; // Jahr des Osterzyklus
	int b = year % 4 ;
	int c = year % 7 ; 
	int k = year / 100 ;
	int p = (8* k +13)/25 ;
	int q = k /4 ;
	int m = (15 + k - p - q) % 30 ;
	int d = (19 * a + m) % 30 ;
	int n = (4 + k - q) % 7 ;
	int e = (2*b + 4 * c + 6 * d + n) % 7 ;
	int x = (22 + d + e) ;
	int z = (x == 57) ? 50 : ((x == 56 && d == 28 && a > 10) ? 49 : x) ;

	z = (z < 32) ? z : (z - 31) ;
	std::string string_z = std::to_string(z);
	std::string result = (z <32) ? (string_z + ". März") : (string_z + ". April") ;

	return result ;
}

int main() {
	// std::string text = easter(2016);
	std::cout << easter(2016);
	// assert (easter(2016) == "27. März");
	// assert (easter(2010) == "4. April");
	return 0 ;
}