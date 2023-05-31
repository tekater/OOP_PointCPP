#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

class Point {
    double x;
    double y;

public:

    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    Point():Point(1,1) {}
    Point(const Point& a) {
        x = a.x;
        y = a.y;
    }
    void display() {
        /*for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (i == x && j == y) {
                    cout << "*";
                }
                else {
                    cout << "_";
                }
            }
            cout << endl;
        }
        cout << endl;*/
        cout << "(" << x << ";" << y << ");\n";
    }
    void read() {
        cout << "Заполните X\n";
        cin >> x;
        cout << "Заполните Y\n";
        cin >> y;
    }

    static bool isEqual(const Point& p1, const Point& p2) {
        if (p1.x == p2.x && p1.y == p2.y) {
            return true;
        }
        else {
            return false;
        }
        
    }

    static Point add(const Point& p1, const Point& p2) {
        Point addP;
        addP.x = p1.x + p2.x;
        addP.y = p1.y + p2.y;

        return addP;
    }
    static Point mult(const Point& p1, double n) {
        Point multP;
        multP.x = p1.x * n;
        multP.y = p1.y * n;
        return multP;
    }

    double length() const {
        return sqrt((x * x) + (y * y));
    }
    static double distance(const Point& p1, const Point& p2) {

        int one = (p2.x - p1.x);
        int two = (p2.y - p1.y);
        
        return sqrt((one * one) + (two * two));
    }
    // 3 способ
    Point operator+(const Point& p2) { // 1 параметр this ( в неявном виде)?

        return Point(x + p2.x, y + p2.y);

    }
    Point operator*(double n) {
        return Point(x * n, y * n);
    }
    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }
    Point operator-() {
        return Point(-x, -y);
    }
    //friend Point operator+(const Point& p1, const Point& p2);
    //friend Point operator-(const Point& p1);
    Point& operator++() { // Префиксная
        ++x;
        ++y;
        return *this;
    }
    Point operator++(int) { // Постфиксная
        Point temp(*this);
        ++x;
        ++y;
        return temp;
    }

    bool operator>(const Point& p2) {
        return length() > p2.length();
    }
    bool operator<(const Point& p2) {
        return length() < p2.length();
    }
    bool operator>=(const Point& p2) {
        return length() >= p2.length();
    }
    bool operator<=(const Point& p2) {
        return length() <= p2.length();
    }

    bool operator==(const Point& p2)  {
        if (x == p2.x && y == p2.y) {
            return true;
        }
        else {
            return false;
        }
    }
    friend istream& operator>>(istream& in, Point& p1);
    
};
// 1Обычная функция (перегрузка)
//static Point operator+(const Point& p1, const Point& p2) {
//
//    return Point(p1.getX()+ p2.getX(), p1.getY()+ p2.getY());
//}


// 2Дружественная функция (перегрузка) friend <function>

//Point operator+(const Point& p1, const Point& p2) {
//
//    return Point(p1.x + p2.x, p1.y + p2.y);
//
//}

//1
//static Point operator-(const Point& p1) {
//    return  Point(-(p1.getX()), -(p1.getY()));
//}

//2
//Point operator-(const Point& p1) {
//
//    return Point(-(p1.x), -(p1.y));
//
//}

ostream& operator<<(ostream& out, const Point& p1) {
    out << "(" << p1.getX() << ";" << p1.getY() << ")";
    return out;
}

istream& operator>>(istream& in, Point& p1)  {
     in >> p1.x >> p1.y;
     return in;
}

class Circle {
    double length;
    double radius;
public:
    Circle(double rad) {
        radius = rad;
        length = 2 * 3.14 * radius;
    }
    Circle() {
        Circle(5);
    }
    Circle(const Circle& c) {
        Circle(c.radius);
    }

    void setRad(double rad) {
        radius = rad;
        length = 2 * 3.14 * radius;
    }

    void setLen(double rad) {
        length = 2 * 3.14 * rad;
    }

    double getRad() {
        return radius;
    }
    double getLen() {
        return length;
    }

    void print() {
        cout << "Radius: " << radius <<"\nLength: " << length << endl;
    }

    Circle& operator+=(double n) {
        radius += n;
        setLen(radius);
        return *this;
    }
    Circle& operator-=(double n) {
        radius -= n;
        setLen(radius);
        return *this;
    }

    bool operator==(const Circle& c2) {
        return radius == c2.radius;
    }
    bool operator!=(const Circle& c2) {
        return radius != c2.radius;
    }

    bool operator>(const Circle& c2) {
        return length > c2.length;
    }
    bool operator<(const Circle& c2) {
        return length < c2.length;
    }

    bool operator>=(const Circle& c2) {
        return length >= c2.length;
    }
    bool operator<=(const Circle& c2) {
        return length <= c2.length;
    }

    friend ostream& operator<<(ostream& out, const Circle& c1);
    friend istream& operator>>(istream& in, Circle& c1);
};

ostream& operator<<(ostream& out, const Circle& c1) {
    out << "Radius: " << c1.radius << "\nLength: " << c1.length << "\n";
    return out;
}
istream& operator>>(istream& in, Circle& c1) {
    in >> c1.radius;
    c1.setLen(c1.radius);
    return in;
}

class Airplane {
    char* type;
    int pass;
    int max;
public:
    Airplane(const char* t, int p, int m) {
        pass = p;
        max = m;
        type = new char[strlen(t) + 1];
        strcpy(type, t);
    }
    Airplane() {
        Airplane("None",0, 10);
    }
    Airplane(const Airplane& a) {
        Airplane(a.type,a.pass, a.max);
    }
    
    void setType(const char* t) {
        delete[] type;
        type = new char[strlen(t) + 1];
        strcpy(type, t);
    }
    void setPass(int p) {
        pass = p;
    }
    void setMax(int m) {
        max = m;
    }
    int getPass() {
        return pass;
    }
    int getMax() {
        return max;
    }

    bool operator==(const Airplane& a2) {
        return !(strcmp(type,a2.type));
    }
    bool operator!=(const Airplane& a2) {
        return (strcmp(type, a2.type));
    }

    ~Airplane() {
        delete[] type;
    }

    Airplane& operator++() { 
        if (pass != max) {
            ++pass;
        }
        return *this;
    }
    Airplane& operator--() {
        if (pass != 0) {
            --pass;
        }
        return *this;
    }

    bool operator>(const Airplane& a2) {
        return max > a2.max;
    }
    bool operator<(const Airplane& a2) {
        return max < a2.max;
    }

    bool operator>=(const Airplane& a2) {
        return max >= a2.max;
    }
    bool operator<=(const Airplane& a2) {
        return max <= a2.max;
    }

    friend ostream& operator<<(ostream& out, const Airplane& a1);
    friend istream& operator>>(istream& in, Airplane& a1);
};

ostream& operator<<(ostream& out, const Airplane& a1) {
    out << "Type: " << a1.type << "\nPass: " << a1.pass << "\nMax: " << a1.max << "\n";
    return out;
}
istream& operator>>(istream& in, Airplane& a1) {
    char a[20];
    in >> a >> a1.pass >> a1.max;
    a1.setType(a);
    
    return in;
}

int main() {

    setlocale(0, "");
    srand(time(NULL));

    //Point point{ 3,2 };
    //Point point2{ 2,3 };

    //cout << "Point:\n";
    //point.display();

    //cout << "\nPoint2:\n";
    //point2.display();

    //point.add(point, point2);
    //
    //Point addr{ Point::add(point,point2) }; cout << endl << "Addr:\n";
    //addr.display();

    //Point multr{ Point::mult(point, 5 )}; cout << endl << "MultR:\n";
    //multr.display();
    //
    //cout << "\nДлина вектора: " << point.length() << endl;
    //cout << "Расстояние между точками point - point2 : " << Point::distance(point, point2) << endl;

    //Point p3{ point + point2 };
    //p3.display();

    //Point p6{ -p3 }; cout << "\nP6:\n";
    //p6.display();

    //Point p4{ 1,1 }; cout << "\nP4:\n";
    //p4.display();
    ////++p4; 
    //p4.display();
   
    //Point p5{ 1,1 };
    //
    //if (p5 == p4) {
    //    cout << "равны\n";
    //}
    //cout << point << " " << point2 << endl;
    //cin >> point >> point2; 
    //cout << point << " " << point2 << endl;

    /*Circle cir{ 5 };
    cout << cir;
    cin >> cir;
    cout << cir;
    cir += 5;
    cout << cir;*/
    Airplane air{ "A105", 10, 15 };
    Airplane air2{ "A105",15,15 };
    Airplane plane{ "A202",20,20 };
    cout << "Air:\n" << air << "\nAir2:\n" << air2 << "\nPlane:\n" << plane << endl;
    cout << "Air == Air2: " << (air == air2) << endl;
    cout << "Air > Air2: " << (air > air2) << endl;
    cout << "Air == Plane: " << (air == plane) << endl;

}
