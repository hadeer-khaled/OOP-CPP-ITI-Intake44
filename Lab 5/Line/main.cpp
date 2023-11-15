#include <iostream>
#include <Point.h>
#include <Line.h>
#include <Circle.h>
#include <graphics.h>

using namespace std;

int main()
{

    //---------------------------- Rectangle ----------------------------------//
    // Composition
     Line L;
     L.set_p_left(5,5);
     L.set_p_right(10,10);
     L.Draw();

    // Associative
    /*
    Point p1_to_rec(1,2) ;
    Point p2_to_rec(9,20) ;

    Line L;
    L.Draw(p1_to_rec ,p2_to_rec ) ;
    */

    //---------------------------- Circle ----------------------------------//
    // Aggregation
    Point p_center ;
    p_center.set_xy(10,10);

    Circle c1 ;
    c1.set_center_pointer(&p_center);

    cout << "Before translate x" ;
    c1.Draw();

    cout << "After translate x" ;
    c1.translate_x(5);
    c1.Draw();



    return 0;
}
