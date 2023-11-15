#ifndef POINT_H
#define POINT_H

using namespace std;
class Point
{
    int x ;
    int y;

public:

    Point (int x = 0, int y= 0)
    {
        static int P_constructed_counter= 1 ;
        this-> x = x ;
        this-> y = y;
        cout<< "Point "  << P_constructed_counter << " Constructor "<< endl ;
        P_constructed_counter++;
    }
    ~Point()
    {
        static int P_destructed_counter= 1 ;
        cout<< "Point "  << P_destructed_counter << " Constructor "<< endl ;
        P_destructed_counter++;

    }
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
        return this-> y ;
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

#endif // POINT_H
