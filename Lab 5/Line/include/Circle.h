#ifndef CIRCLE_H
#define CIRCLE_H
#define pi 3.14
#include<graphics.h>
#include <conio.h>

using namespace std;
class Circle
{
    Point* p ;
    int raduis ;
    int area ;
    int circum ;
    public:
        Circle()
        {
            p = NULL;
           cout << "Circle Constructor "<<endl ;
        }

        //For Aggregation
        void set_center_pointer(Point* center){
            p = center ;
        }
        void release_center_pointer(){
            p = NULL ;
        }
        // c1 = c2
        Circle( Circle& c){
            p = new Point( c.p->get_x() , c.p->get_y());
            raduis = c.raduis;
            int area ;
            int circum ;
        }
        int translate_x(int x)
        {
            if(p != NULL){
                p->set_x (p->get_x() + x) ;
            }
        }
        int translate_y(int y )
        {
            if(p != NULL){
                p->set_y(p->get_y() + y );
            }
        }
        void Draw(){
            if(p != NULL){
                p->Draw();
                initwindow( 600, 400 , "Circle");
                circle(p->get_x() , p->get_y() , 5);
                getch();

            }
        }
};
#endif // CIRCLE_H
