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
	int z = (x == 57) ? 50 : (x == 56 && d == 28 && a > 10) ? 49 : x ;

	int h = (z < 32) ? z : (z -31) ;
	std::string string_h = std::to_string(h);
	std::string result =  (z>32)? (string_h + ". April") : (string_h + ". März") ;

	return result ;
}

int main() {
	
	assert (easter(2016) == "27. März");
	assert (easter(2010) == "4. April");
	assert (easter(2017) == "16. April");
	assert (easter(1647) == "21. April");
	assert (easter(1821) == "22. April");
	assert (easter(2004) == "11. April");
	assert (easter(1995) == "16. April");
	assert (easter(1969) == "6. April");
	assert (easter(1875) == "28. März");
	assert (easter(1904) == "3. April");

	return 0 ;
}