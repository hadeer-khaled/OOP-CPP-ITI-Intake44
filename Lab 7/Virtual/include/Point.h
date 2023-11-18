#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;
class Point
{
    int x ;
    int y;

public:

    Point (int x = 0, int y= 0)
    {
        this-> x = x ;
        this-> y = y;
    }
    ~Point(){}
    friend ostream & operator << (ostream &out, Point &p);
    friend istream & operator >> (istream &in , Point &p);

    void set_xy(int x, int y)
    {
        this-> x = x ;
        this-> y = y;
    }
    void set_x(int x)
    {
        this-> x = x ;
    }
    void set_y(int y)
    {
        this-> y = y ;
    }

    int get_x(void)
    {
        return this-> x ;
    }

    int get_y(void)
    {
        return this-> y ;
    }
    void Draw()
    {
        cout << "(" << x << " , " << y  << ")"<< endl ;
    }
};
ostream & operator << (ostream &out, Point &p)
        {
            out << "( ";
            out << p.get_x() ;
            out << " , ";
            out << p.get_y() ;
            out << " )";
            return out;
        }
 istream & operator >> (istream &in,  Point &p)
        {
            //cout << "Enter The X Coordinate: ";
            in >>p.x;
           // cout << "Enter The Y Coordinate: ";
            in >>p.y;
            return in;
        }
#endif // POINT_H
