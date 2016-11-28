#include <iostream>
#include <string>
#include <cassert>


int abs(int x) {
	return (x>=0) ? x : -x;
}

int weekday2001(int d, int m, int y) {
	int z = y - 2001; // angepasstes Jahr
	int j_i = (365* z + z/4- z /100 + z/400) % 7; 
	int schaltjahr = ((y%4 == 0 && y%100 != 0) || (y%400 == 0))? 0 : 1; // 0 heisst "ist Schaltjahr"
	int p = (m==1) ? d : (m==2)? (d+31) : 
				(m>2 && schaltjahr !=0) ? (d + 59 + (153*m - 457)/5) : (d + 60 + (153*m - 457)/5);
	int w = (j_i + p-1)%7;

	return w;
}

int floorDiv(int a, int b) {
	int x = a/b ;
	x = (x>0) ? x : -((abs(a)+abs(a%b))/abs(b));
	return x;
}

int floorMod (int a, int b) {
	/* Antwort zu 2c)
		Sobald der Betrag vom Ergebnis der Modulo Funktion kleiner als eins ist, wird beim Standardisierten Modulo in C++ das erste Argument ausgegeben, bei FloorMod wird trotzdem die Differenz zum zweiten Argument berechnet.
	*/
	int c = floorDiv(a,b);
	int result = a-b*c;

	return result;
}

int weekday(int d, int m, int y) { // angepasste Funktion für y<2001
	int z = y - 2001;
	int j_i = floorMod((365* z + floorDiv(z,4)- floorDiv(z,100) + floorDiv(z,400)),7); 
	int schaltjahr = ((floorMod(y,4) == 0) && (floorMod(y,100) !=0)) ? 0 : 
						(floorMod(y,400) ==0) ? 0 :1;
	int p = (m==1) ? d : (m==2)? (d+31) : 
				(m>2 && schaltjahr !=0) ? (d + 59 + floorDiv((153*m - 457),5)) : 
					(d + 60 + floorDiv((153*m - 457),5));
	int w = (j_i + p-1)%7;

	return w;
}

int weekday1(int d, int m, int y) { // warum haben wir uns diese scheiss Arbeit gemacht??
/* Antwort zu Aufgabe 2e):
	Diese Vereinfachung des Codes erzeugt nun keine negtiven Zahlen mehr, wodurch eine Implementierung einer eigens geschriebenen Funktion für eine extra Division der negativen Zahlen nicht benötigt wird und dadurch ist auch eine extra Funktion 'floorMod' unnötig.
*/
	int z = y - 1; // angepasstes Jahr
	int j_i = (365* z + z/4- z /100 + z/400) % 7; 
	int schaltjahr = (y%4 == 0 && y%100 != 0)? 0 : (y%400 ==0) ? 0 :1;
	int p = (m==1) ? d : (m==2)? (d+31) : 
				(m>2 && schaltjahr !=0) ? (d + 59 + (153*m - 457)/5) : (d + 60 + (153*m - 457)/5);
	int w = (j_i + p-1)%7;

	return w;
}

int main() {
	assert (weekday2001(9, 2, 2005) == 2); // assert Test mit Jahren größer als 2000
	assert (weekday2001(23, 6, 2010) == 2);
	assert (weekday2001(24, 12, 2016) == 5);

	assert (weekday(23, 6, 1995) == 4); // assert Test mit Jahr kleiner als 2001 (floorDiv)
	assert (weekday(10, 4, 1997) == 3); 
	assert (weekday(30, 6, 1997) == 0); 
	assert (weekday(30, 6, 2010) == 2); 
	assert (weekday(30, 6, 2016) == 3); 
	assert (weekday(30, 6, 1997) == 0); 
	assert (weekday(1, 1, 2001) == 0);
	assert (weekday(30, 1, 1999) == 5);
	// assert (weekday(18, 1, 1900) == 3);
	// assert (weekday(18, 1, 2000) == 1); 

	assert (weekday1(23, 6, 1995) == 4); // assert Test mit Jahr kleiner als 2001 (floorDiv)
	assert (weekday1(10, 4, 1997) == 3); 
	assert (weekday1(30, 6, 1997) == 0); 
	assert (weekday1(30, 6, 2010) == 2); 
	assert (weekday1(30, 6, 2016) == 3); 
	assert (weekday1(30, 6, 1997) == 0); 
	assert (weekday1(1, 1, 2001) == 0);
	assert (weekday1(30, 1, 1999) == 5);
	assert (weekday1(18, 1, 1900) == 3);
	assert (weekday1(18, 1, 2000) == 1); 


	// assert (weekday2001(23, 6, 1995) == 4); // assert Test mit unangepasster Funktion
}





