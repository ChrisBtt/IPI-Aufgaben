#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>

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
    
    // nicht definierter Punkt zur Verwendung in Rectangle-Klasse
    Point not_defined() const
    {
        Point res(NAN, NAN);
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

// nicht definierter Punkt zur Verwendung in Rectangle-Klasse
Point not_defined()
{
    Point res(NAN, NAN);
    return res;
}

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
    : p0_(0.0, 0.0)
    , p1_(p1.x() >= 0 && p1.y() >= 0 ? p1 : not_defined())
    {}
    
    Rectangle(Point const & p0, Point const & p1)
    : p0_(p0.x() >= 0 && p0.y() >= 0 ? p0 : not_defined())
    , p1_(p1.x() >= 0 && p1.y() >= 0 ? p1 : not_defined())
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
    double const & x0() const // linke x-Koordinate
    {
        return (*this).p0().x();
    }
    
    double x1() const // rechte x-Koordinate
    {
        return (*this).p1().x();
    }
    
    double y0() const // untere y-Koordinate
    {
        return (*this).p0().y();
    }
    
    double y1() const // obere  y-Koordinate
    {
        return (*this).p1().y();
    }
    
    double width() const  // Breite
    {
        return (*this).p1().x() - (*this).p0().x();
    }
    
    double height() const // Hoehe
    {
        return (*this).p1().y() - (*this).p0().y();
    }
    
    // Implementieren Sie eine Funktion, die genau dann 'true'
    // zurueckgibt, wenn das Rechteck nicht ungueltig ist.
    bool is_valid() const
    {
        return isnan((*this).x0()) || isnan((*this).y0()) || isnan((*this).x1()) || isnan((*this).y1()) ? false : true;
    }
    
    // Implementieren Sie eine Funktion, die die Flaeche des
    // Rechtecks zurueckgibt, bzw. -1.0, wenn das Rechteck
    // ungueltig ist.
    double area() const
    {
        return (*this).is_valid() ? (*this).width() * (*this).height() : -1.0;
    }
    
    // Implementieren Sie eine Funktion, die ein neues Rechteck
    // zurueckgibt, bei dem die x- und y-Koordinaten vertauscht sind.
    Rectangle transpose() const
    {
        Point new_p0((*this).p0().y(), (*this).p0().x());
        Point new_p1((*this).p1().y(), (*this).p1().x());
        Rectangle res(new_p0, new_p1);
        return res;
    }
    
    // Implementieren Sie eine Funktion, die ein neues Rechteck
    // zurueckgibt, das um den Vektor v verschoben ist.
    Rectangle translate(Point const & v) const
    {
        Point new_p0((*this).p0().translate(v));
        Point new_p1((*this).p1().translate(v));
        Rectangle res(new_p0, new_p1);
        return res;
    }
    
    // Implementieren Sie eine Funktion, die genau dann 'true'
    // zurueckgibt, wenn der Punkt p im Rechteck (*this) enthalten
    // ist. Wenn (*this) ungueltig ist, soll 'false' zurueckgegeben
    // werden.
    bool contains(Point const & p) const
    {
        return p.x() >= (*this).p0().x() && p.x() <= (*this).width() + (*this).p0().x() && p.y() <= (*this).height() + (*this).p0().y() && p.y() >= (*this).p0().y() && (*this).is_valid() ? true : false;
    }
    
    // Implementieren Sie eine Funktion, die genau dann 'true'
    // zurueckgibt, wenn das Rechteck r im Rechteck (*this) enthalten
    // ist. Wenn (*this) oder r ungueltig sind, soll 'false' zurueckgegeben
    // werden.
    bool contains(Rectangle const & r) const
    {
        return contains(r.p0()) && contains(r.p1()) && (*this).is_valid() && r.is_valid() ? true : false;
    }
};

// Implementieren Sie eine Funktion, die das Rechteck
// in einen String der Form "[x0:x1, y0:y1]" umwandelt.
std::string to_string(Rectangle const & r)
{
    std::string x0_long = std::to_string(r.p0().x());
    std::string x1_long = std::to_string(r.p1().x());
    std::string y0_long = std::to_string(r.p0().y());
    std::string y1_long = std::to_string(r.p1().y());
    
    int x0_dot = x0_long.find('.');
    int x1_dot = x1_long.find('.');
    int y0_dot = y0_long.find('.');
    int y1_dot = y1_long.find('.');
    
    std::string x0 = x0_long.substr(0, x0_dot+2);
    std::string x1 = x1_long.substr(0, x1_dot+2);
    std::string y0 = y0_long.substr(0, y0_dot+2);
    std::string y1 = y1_long.substr(0, y1_dot+2);
    
    return "[" + x0 + ":" + x1 + ", " + y0 + ":" + y1 + "]";
}

// Implementieren Sie eine Funktion, die das kleinste Rechteck
// zurueckgibt, das r1 und r2 enthaelt.
Rectangle rectangle_union(Rectangle const & r1, Rectangle const & r2)
{
    // Auf Ungültigkeit checken
    if (!r1.is_valid() || !r2.is_valid()) {
        return Rectangle(Point(-1.0, -1.0));
    }
    
    // finde Punkt der am meisten links und den, der am meisten oben liegt
    double x0_r1 = r1.x0();
    double x0_r2 = r2.x0();
    double x_min = std::min(x0_r1, x0_r2);
    Point p0_union = x_min == r1.x0() ? r1.p0() : r2.p0();
    
    double y1_r1 = r1.y1();
    double y1_r2 = r2.y1();
    double y_max = std::max(y1_r1, y1_r2);
    Point p1_union = y_max == r1.y0() ? r1.p1() : r2.p1();
    
    // Union-Rechteck zurückgeben
    Rectangle res(p0_union, p1_union);
    return res;
}

// Implementieren Sie eine Funktion, die den Durchschnitt
// der Rechtecke r1 und r2 zerueckgibt, oder ein beliebiges
// ungueltiges Rechteck, falls r1 und r2 nicht ueberlappen.
Rectangle rectangle_intersection(Rectangle const & r1, Rectangle const & r2)
{
    // Union-Rechteck
    Rectangle union_rec = rectangle_union(r1, r2);
    
    //Finde Punkte von Überschnitt
    Point p0 = union_rec.p0() == r1.p0() ? r2.p0() : r1.p0();
    Point p1 = union_rec.p1() == r1.p1() ? r2.p1() : r1.p1();
    
    // Resultierendes Rechteck zurückgeben
    Rectangle res(p0, p1);
    return r1.contains(res) && r2.contains(res) ? res : Rectangle(Point(-1.0, -1.0));
}

// Implementieren Sie Tests fuer die Rectangle-Klasse.
void testRectangle()
{
    Rectangle r0(Point(3.0, 5.0));
    
    assert(r0.p0() == Point(0.0, 0.0));
    assert(r0.p1() == Point(3.0, 5.0));
    assert(r0.x0() == 0.0);
    assert(r0.x1() == 3.0);
    assert(r0.y0() == 0.0);
    assert(r0.y1() == 5.0);
    assert(to_string(r0) == "[0.0:3.0, 0.0:5.0]");
    assert(r0.width() == 3.0);
    assert(r0.is_valid());
    assert(r0.area() == 15.0);
    assert(to_string(r0.transpose()) == "[0.0:5.0, 0.0:3.0]");
    assert(to_string(r0.translate(Point(2.0, 2.0))) == "[2.0:5.0, 2.0:7.0]");
    assert(r0.contains(Point(1.0, 1.0)));
    assert(r0.contains(Point(3.0, 5.0)));
    
    Rectangle r(Point(1.0, 2.0), Point(3.0, 5.0));
    
    assert(r.x0() == 1.0);
    assert(r.x1() == 3.0);
    assert(r.y0() == 2.0);
    assert(r.y1() == 5.0);
    assert(to_string(r) == "[1.0:3.0, 2.0:5.0]");
    assert(r.height() == 3.0);
    assert(r.is_valid());
    assert(r.area() == 6.0);
    assert(to_string(r.transpose()) == "[2.0:5.0, 1.0:3.0]");
    assert(to_string(r.translate(Point(1.0, 1.0))) == "[2.0:4.0, 3.0:6.0]");
    assert(r.contains(Point(1.0, 3.0)));
    assert(r.contains(Point(1.0, 2.0)));
    assert(r0.contains(r));
    assert(to_string(rectangle_union(r, r0)) == "[0.0:3.0, 0.0:5.0]");
    
    // Fuegen Sie weitere Tests entsprechend der Aufgabe hinzu.
    // Kommentar: Negative Werte für die Höhe und Breite können nicht zurückgegben werden, da solche Rechntecke die Werte "NAN" für entsprechende Einträge haben (siehe oben)
    
    Rectangle r00;
    
    assert(r00.x0() == 0.0);
    assert(r00.x1() == 0.0);
    assert(r00.y0() == 0.0);
    assert(r00.y1() == 0.0);
    assert(to_string(r00) == "[0.0:0.0, 0.0:0.0]");
    assert(r00.width() == 0.0);
    assert(r00.height() == 0.0);
    assert(r00.is_valid());
    assert(!r00.contains(Point(2.0, 2.0)));
    
    Rectangle r2(Point(-3.0, 5.0));
    
    assert(r2.area() == -1.0);
    
    Rectangle test=rectangle_union(r0, Rectangle(Point(10.0, 10.0)));
    
    assert(to_string(test) == "[0.0:10.0, 0.0:10.0]");
    
    Rectangle test2 = rectangle_intersection(r0, r);
    
    assert(r.contains(Point(3.0, 5.0)));
    
    assert(to_string(test2) == "[1.0:3.0, 2.0:5.0]");
    
    std::cout << "alle Rectangle-Tests erfolgreich\n";
}

int main()
{
    testRectangle();
}
