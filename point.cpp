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
        for (int i = 0; i < 20; i++) {
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
        cout << endl;
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

    static double length(const Point& p1) {
        return sqrt((p1.x * p1.x) + (p1.y * p1.y));
    }
    static double distance(const Point& p1, const Point& p2) {

        int one = (p2.x - p1.x);
        int two = (p2.y - p1.y);
        
        return sqrt((one * one) + (two * two));
    }

};



int main() {

    setlocale(0, "");
    srand(time(NULL));

    Point point{ 3,2 };
    Point point2{ 2,3 };

    point.display();
    point.add(point, point2);
    
    Point addr{ Point::add(point,point2) };
    addr.display();

    Point multr{ Point::mult(point, 5 )};
    multr.display();

}
