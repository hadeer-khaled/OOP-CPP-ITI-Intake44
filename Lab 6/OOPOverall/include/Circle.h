#ifndef CIRCLE_H
#define CIRCLE_H
#include <Shape.h>

class Circle : public Shape{
    int raduis ;
    Point p_center ;
    public:
        Circle(int p_center_x = 0 ,int p_center_y = 0, int raduis_ = 10){
            p_center.set_x(p_center_x);
            p_center.set_y(p_center_y);
            raduis= raduis_;
        }

        // Deep Copy Constructor c1 = c2
        /*Circle( Circle& c){
            p_center = new Point( c.p_center->get_x() , c.p_center->get_y());
            raduis = c.raduis;
        }*/

        /*Circle( Circle& c){
            p_center = new Point( c.p_center.get_x() , c.p_center.get_y());
            raduis = c.raduis;
        }*/
        void setCenter(int p_center_x ,int p_center_y){
            p_center.set_x(p_center_x);
            p_center.set_y(p_center_y);
        }
        void setRaduis(int raduis_){
           raduis = raduis_;
        }
        int translate_x(int x)
        {
                p_center.set_x (p_center.get_x() + x) ;

        }
        int translate_y(int y )
        {
                p_center.set_y(p_center.get_y() + y );

        }
        void Draw(){
            //initwindow( 600, 400 , "Circle");
                circle(p_center.get_x() , p_center.get_y() , raduis);
                //getch();
        }
};

#endif // CIRCLE_H
