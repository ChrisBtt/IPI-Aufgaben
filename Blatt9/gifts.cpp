#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

double const big_number = 1e300;

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



double bssf_score(Rectangle const& free, Rectangle const& obj) {

    // Rückgabe je nach Größe der Differenzen
    if ((free.width() - obj.width()) < (free.height() - obj.height())) { 

        return (free.width() - obj.width() >=0) ? (free.width() - obj.width()) : big_number;

    } else {
        return (free.height() - obj.height() >=0) ? (free.height() - obj.height()) : big_number;
    }
}

int main()
{
    Rectangle              table(Point(100.0, 80.0));
    Rectangle              tree_stand(Point(30.0, 30.0));

    std::vector<Rectangle> gifts = { Rectangle(Point(20.0, 10.0)),
                                     Rectangle(Point(10.0, 11.0)),
                                     Rectangle(Point(3.0, 46.0)),
                                     Rectangle(Point(3.0, 4.0)),
                                     Rectangle(Point(6.0, 16.0)),
                                     Rectangle(Point(10.0, 20.0)),
                                     Rectangle(Point(20.0, 8.0)),
                                     Rectangle(Point(12.0, 37.0)),
                                     Rectangle(Point(11.0, 15.0)),
                                     Rectangle(Point(40.0, 63.0)),
                                     Rectangle(Point(23.0, 6.0)),
                                     Rectangle(Point(16.0, 12.0)),
                                     Rectangle(Point(25.0, 20.0)),
                                     Rectangle(Point(67.0, 3.0)),
                                     Rectangle(Point(31.0, 29.0)),
                                     Rectangle(Point(12.0, 11.0)),
                                     Rectangle(Point(8.0, 9.0)),
                                     Rectangle(Point(3.0, 8.0)),
                                     Rectangle(Point(21.0, 13.0)),
                                     Rectangle(Point(46.0, 13.0)),
                                     Rectangle(Point(11.0, 75.0)),
                                     Rectangle(Point(4.0, 3.0)),
                                     Rectangle(Point(19.0, 7.0)),
                                     Rectangle(Point(33.0, 7.0)),
                                     Rectangle(Point(6.0, 16.0)),
                                     Rectangle(Point(21.0, 4.0)),
                                     Rectangle(Point(8.0, 8.0)),
                                     Rectangle(Point(3.0, 86.0)),
                                     Rectangle(Point(20.0, 6.0)),
                                     Rectangle(Point(21.0, 3.0)),
                                     Rectangle(Point(13.0, 59.0)),
                                     Rectangle(Point(4.0, 20.0))
    };

    std::vector<Rectangle> to_be_placed = gifts;
    to_be_placed.push_back(table);
    std::vector<Rectangle> free_rectangles = {table};
    std::vector<Rectangle> already_placed = {};

// speichere das Rechteck mit dem besten BSSF Wert in einer Variablen
// den Score zum Vergleich und die Ausrichtung des Paeckchens
    bool transpose = false;
    double best_score = big_number;
    Rectangle best_free;
    Rectangle best_obj;
    int best_obj_position ;

// Suche das am besten passendste Rechteck heraus und ordne es einem freien Rechteck zu
    for (Rectangle & obj : to_be_placed, int i = 0, i<to_be_placed.size(), ++i) {
        for (Rectangle & free : free_rectangles) {

            if (bssf_score(free, obj) < best_score) {
                best_score = bssf_score(free, obj);
                best_free = free;
                best_obj = obj;
                best_obj_position = i;
            }

            if (bssf_score(free, obj.transpose()) < best_score) {
                best_score = bssf_score(free, obj);
                best_free = free;
                best_obj = obj;
                transpose = true;    
            }
        }
    }

// Platziere das Rechteck auf dem Tisch und ziehe es vom freien Platz ab
    if (best_score < big_number) {

        if (transpose) {

            best_obj = best_obj.translate(Point(best_free.x0()-best_obj.x0(), best_free.y0()-best_obj.y0()));

            already_placed.push_back(best_obj.transpose());
            to_be_placed.erase(std::find(to_be_placed.begin(), to_be_placed.end(), best_obj));
            free_rectangles.erase(std::find(free_rectangles.begin(), free_rectangles.end(), best_free));

// zwei neue kleinere Rechtecke erzeugen
            Point new_Edge = Point(best_obj.x1(), best_obj.y1());
            std::vector <Rectangle> new_Rectangles = {Rectangle(Point(best_obj.x0(), best_obj.y1()), Point(best_obj.x1(), best_free.y1())),
                                                       Rectangle(Point(best_obj.x1(), best_obj.y1()), Point(best_free.x1(), best_free.y1())),
                                                       Rectangle(Point(best_obj.x1(), best_obj.y0()), Point(best_free.x1(), best_obj.y1()))
                                                    };



        } else {
            already_placed.push_back(best_obj);
            to_be_placed.erase(std::find(to_be_placed.begin(), to_be_placed.end(), best_obj));
            free_rectangles.erase(std::find(free_rectangles.begin(), free_rectangles.end(), best_free));
        }
    }

    return 0;
}