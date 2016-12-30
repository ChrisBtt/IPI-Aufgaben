#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

/////////////////////////////////////////////////
// die 2-dimensionale Punkt-Klasse aus der Vorlesung
class Point
{
    // die Koordinaten des Punktes
    double x_;
    double y_;

  public:

    // Standardkonstruktor: initialisiere Punkt (0,0)
    Point()
    : x_(0.0)
    , y_(0.0)
    {}

    // Konstruktor mit zwei Koordinaten: initialisiere Punkt (x,y)
    Point(double x, double y)
    : x_(x)
    , y_(y)
    {}

    // Getter-Funktionen fuer die Koordinaten
    double x() const
    {
        return (*this).x_;
    }

    double y() const
    {
        return (*this).y_;
    }

    // teste ob zwei Punkte gleich sind
    bool operator==(Point const & other) const
    {
        return (*this).x() == other.x() && (*this).y() == other.y();
    }

    // teste ob zwei Punkte ungleich sind
    bool operator!=(Point const & other) const
    {
        return (*this).x() != other.x() || (*this).y() != other.y();
    }

    // erzeuge neuen Punkt, desssen x- und y-Koordinate
    // vertauscht sind
    Point transpose() const
    {
        Point res((*this).y(), (*this).x());
        return res;
    }

    // erzeuge neuen Punkt, der um den Vektor v verschoben ist
    Point translate(Point const & v) const
    {
        Point res((*this).x() + v.x(), (*this).y() + v.y());
        return res;
    }
};

// wandle den Punkt in einen String der Form "[x, y]"
std::string to_string(Point const & p)
{
    return "[" + std::to_string(p.x()) + ", " + std::to_string(p.y()) + "]";
}

/////////////////////////////////////////////////
// Implementieren Sie die Rectangle-Klasse.
class Rectangle
{
    Point p0_; // linke untere Ecke
    Point p1_; // rechte obere Ecke

  public:

    // Implementieren Sie die folgenden Konstruktoren.
    Rectangle()
    : p0_(0.0, 0.0)
    , p1_(0.0, 0.0)
    {}

    Rectangle(Point const & p1)
    : p0_(0.0,0.0)
    , p1_(p1)
    {}

    Rectangle(Point const & p0, Point const & p1)
    : p0_(p0)
    , p1_(p1)
    {}

    // read-only Getter-Funktionen fuer die Member-Variablen
    Point const & p0() const
    {
        return (*this).p0_;
    }

    Point const & p1() const
    {
        return (*this).p1_;
    }

    // Implementieren Sie die folgenden Getter-Funktionen.
    double x0() const // linke x-Koordinate
    {
        return (*this).p0_.x();
    }

    double x1() const // rechte x-Koordinate
    {
        return (*this).p1_.x();
    }

    double y0() const // untere y-Koordinate
    { 
        return (*this).p0_.y();
    }

    double y1() const // obere  y-Koordinate
    {
        return (*this).p1_.y();
    }

    double width() const  // Breite
    {
        return (*this).x1()-(*this).x0();
    }

    double height() const // Hoehe
    {
        return (*this).y1()-(*this).y0();
    }

    // Implementieren Sie eine Funktion, die genau dann 'true'
    // zurueckgibt, wenn das Rechteck nicht ungueltig ist.
    bool is_valid() const
    {
        if ((*this).width() >=0 && (*this).height() >=0) {  // Prüfe, ob der Punkt p0 rechts unterhalb von p1 liegt (positive Längen)
            return true;

        } else {
            return false;
        }
    }

    // Implementieren Sie eine Funktion, die die Flaeche des
    // Rechtecks zurueckgibt, bzw. -1.0, wenn das Rechteck
    // ungueltig ist.
    double area() const
    {
        // Prüfe die Entartung des Rechtecks und gib entsprechend den Flächeninhalt aus
        if ((*this).height()>0 && (*this).width()>0) { 
            return (*this).height() * (*this).width();

        } else if ((*this).height()>=0 || (*this).width()>=0) {
            return 0.000000;

        } else { return -1.000000; }
    }

    // Implementieren Sie eine Funktion, die ein neues Rechteck
    // zurueckgibt, bei dem die x- und y-Koordinaten vertauscht sind.
    Rectangle transpose() const
    {
        Rectangle rect = {Point((*this).x1(), (*this).y1()), Point((*this).x0(), (*this).y0())};
        return rect;
    }

    // Implementieren Sie eine Funktion, die ein neues Rechteck
    // zurueckgibt, das um den Vektor v verschoben ist.
    Rectangle translate(Point const & v) const
    {
        Rectangle rect = {Point((*this).x1() + v.x(), (*this).y1() + v.y()), Point((*this).x0() + v.x(), (*this).y0() + v.y())};
        return rect;
    }

    // Implementieren Sie eine Funktion, die genau dann 'true'
    // zurueckgibt, wenn der Punkt p im Rechteck (*this) enthalten
    // ist. Wenn (*this) ungueltig ist, soll 'false' zurueckgegeben
    // werden.
    bool contains(Point const & p) const
    {
        if ((*this).x0() <= p.x() && p.x() <= (*this).x1()  // Prüfe die x und y Koordinaten des Punktes separat
            && (*this).y0() <= p.y() && p.y() <= (*this).y1()) {
            return true;

        } else { return false; }
    }

    // Implementieren Sie eine Funktion, die genau dann 'true'
    // zurueckgibt, wenn das Rechteck r im Rechteck (*this) enthalten
    // ist. Wenn (*this) oder r ungueltig sind, soll 'false' zurueckgegeben
    // werden.
    bool contains(Rectangle const & r) const
    {
        if (r.is_valid() && (*this).is_valid()) {

            if ((*this).x0() <= r.x0() && r.x1() <= (*this).x1()
                && (*this).y0() <= r.y0() && r.y1() <= (*this).y1()) {
              return true;
            } else { return false; }

        } else { return false; }

    }
};

// Implementieren Sie eine Funktion, die das Rechteck
// in einen String der Form "[x0:x1, y0:y1]" umwandelt.
std::string to_string(Rectangle const & r)
{
    std::string string = "[" + std::to_string(r.x0()) + ":" + std::to_string(r.x1()) + ", " + std::to_string(r.y0()) + ":" + std::to_string(r.y1()) + "]";
    return string;
}

// Implementieren Sie eine Funktion, die das kleinste Rechteck
// zurueckgibt, das r1 und r2 enthaelt.
Rectangle rectangle_intersection(Rectangle const & r1, Rectangle const & r2)
{
    // Wenn r1 und r2 gueltig sind ...
    if (r1.is_valid() && r2.is_valid()) {

            // berechne neue Eckpunkte eines gemeinsamen Rechtecks
            Point min_point = {std::min(r1.x0(), r2.x0()),std::min(r1.y0(), r2.y0())};  
            Point max_point = {std::max(r1.x1(), r2.x1()),std::max(r1.y1(), r2.y1())};

            return {min_point, max_point};

    } else {    
        return {Point(0.0, 0.0), Point(-1.0, -1.0)};
    }
}

// Implementieren Sie eine Funktion, die den Durchschnitt
// der Rechtecke r1 und r2 zerueckgibt, oder ein beliebiges
// ungueltiges Rechteck, falls r1 und r2 nicht ueberlappen.
Rectangle rectangle_union(Rectangle const & r1, Rectangle const & r2)
{
 // Wenn r1 und r2 gueltig sind ...
    if (r1.is_valid() && r2.is_valid()) {
        // ... und die Rechtecke sich ueberschneiden:
        if (r1.x1() >= r2.x0() && r1.y1() >= r2.y0()) {  

            // berechne neue Eckpunkte eines gemeinsamen Rechtecks
            Point min_point = {std::max(r1.x0(), r2.x0()),std::max(r1.y0(), r2.y0())};  
            Point max_point = {std::min(r1.x1(), r2.x1()),std::min(r1.y1(), r2.y1())};

            return {min_point, max_point};
        }
    } 
    // Ansonsten ungueltiges Rechteck ausgeben  
    return {Point(0.0, 0.0), Point(-1.0, -1.0)};
}

// Implementieren Sie Tests fuer die Rectangle-Klasse.
void testRectangle()
{
    Rectangle r0(Point(3.0, 5.0));

    assert(r0.p0() == Point(0.0, 0.0));
    assert(r0.p1() == Point(3.0, 5.0));

    Rectangle r(Point(1.0, 2.0), Point(3.0, 5.0));

    assert(r.x0() == 1.0);  


// eigene Tests der drei möglichen Initialisierungen eines
// Rechtecks mit Ausgabe aller Koordinaten

    r0 = {};
    Rectangle r1 = {Point(2.0, 4.0)};
    Rectangle r2 = {Point(2.0, 1.0), Point(5.0, 6.0)};
    Rectangle r3 = {Point(-2.0, -4.0)};


    std::cout << to_string(r0) << "\n";  // Ausgabe als String
    assert(to_string(r0) == "[0.000000:0.000000, 0.000000:0.000000]");

    assert(r0.x0() == 0.0);  // Koordinaten
    assert(r0.x1() == 0.0);
    assert(r0.y0() == 0.0);
    assert(r0.y1() == 0.0);

    assert(r0.height() == 0.000000);  // Hoehe

    assert(r0.area() == 0.000000);  // Flaeche

// Tests von r1
    std::cout << to_string(r1) << "\n";  // Ausgabe als String
    assert(to_string(r1) == "[0.000000:2.000000, 0.000000:4.000000]");

    assert(r1.x0() == 0.0);  // Koordinaten
    assert(r1.x1() == 2.0);
    assert(r1.y0() == 0.0);
    assert(r1.y1() == 4.0);

    assert(r1.width() == 2.000000);  // Hoehe und Breite
    assert(r1.height() == 4.000000);

    assert(r1.is_valid());  // gueltig

    assert(to_string(r1.transpose()) == "[2.000000:0.000000, 4.000000:0.000000]");  // transponiert das Rechteck (vertauscht Punkte)
    assert(to_string(r1.translate(Point(2.0, 2.0))) == "[4.000000:2.000000, 6.000000:2.000000]");  // verschiebt das Rechteck (vertauscht Punkte)

// Tests von r2
    std::cout << to_string(r2) << "\n";  // Ausgabe als String
    assert(to_string(r2) == "[2.000000:5.000000, 1.000000:6.000000]");

    assert(r2.x0() == 2.0);  // Koordinaten
    assert(r2.x1() == 5.0);
    assert(r2.y0() == 1.0);
    assert(r2.y1() == 6.0);

    assert(r2.width() == 3.000000);  // Hoehe und Breite
    assert(r2.height() == 5.000000);

    assert(r2.is_valid());  // gueltig
    assert(r2.area() == 15.000000);  // Flaeche

    std::cout << to_string(r2.transpose()) << "\n"; 
    assert(to_string(r2.transpose()) == "[5.000000:2.000000, 6.000000:1.000000]");  // transponiert das Rechteck (vertauscht Punkte)

    std::cout << to_string(r2.translate(Point(2.0, 2.0))) << "\n";
    assert(to_string(r2.translate(Point(2.0, 2.0))) == "[7.000000:4.000000, 8.000000:3.000000]");  // verschiebt das Rechteck (vertauscht Punkte)

// Tests von r3
    assert(!r3.is_valid());  // gueltig
    assert(r3.area() == -1.000000);  // Flaeche

    assert(to_string(r3.transpose()) == "[-2.000000:0.000000, -4.000000:0.000000]");  // transponiert das Rechteck (vertauscht Punkte)

// Test von contains()

    assert(r0.contains(Point(0.0,0.0)));
    assert(r1.contains(Point(0.0,0.0)));
    assert(r1.contains(r1));
    assert(r2.contains(Rectangle(Point(3.0,1.0), Point(4.0,4.0))));
    assert(r2.contains(Point(2.0,2.0)));
    assert(!r2.contains(Point(1.0,1.0)));
    assert(!r3.contains(r2));

// Pruefe Überschneidungen der Rechtecke

    assert(to_string(rectangle_union(r0, r1)) == "[0.000000:0.000000, 0.000000:0.000000]");
    assert(to_string(rectangle_union(r2, r1)) == "[2.000000:2.000000, 1.000000:4.000000]");
    assert(to_string(rectangle_union(r3, r1)) == "[0.000000:-1.000000, 0.000000:-1.000000]");
    assert(to_string(rectangle_union(r0, r2)) == "[0.000000:-1.000000, 0.000000:-1.000000]");
    assert(to_string(rectangle_intersection(r0, r1)) == "[0.000000:2.000000, 0.000000:4.000000]");
    assert(to_string(rectangle_intersection(r2, r1)) == "[0.000000:5.000000, 0.000000:6.000000]");
    assert(to_string(rectangle_intersection(r3, r1)) == "[0.000000:-1.000000, 0.000000:-1.000000]");
    assert(to_string(rectangle_intersection(r0, r2)) == "[0.000000:5.000000, 0.000000:6.000000]");

    // Fuegen Sie weitere Tests entsprechend der Aufgabe hinzu.

    std::cout << "alle Rectangle-Tests erfolgreich\n";
}

int main()
{
    testRectangle();
}