#ifndef CIRCLE_H
#define CIRCLE_H
#include <Shape.h>

class Circle : public Shape{
    Point p_center ;
    public:
        Circle(int p_center_x = 0 ,int p_center_y = 0, int raduis_ = 10){
            p_center.set_x(p_center_x);
            p_center.set_y(p_center_y);
            raduis= raduis_;
        }

        void setCenter(int p_center_x ,int p_center_y){
            p_center.set_x(p_center_x);
            p_center.set_y(p_center_y);
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
                circle(p_center.get_x() , p_center.get_y() , raduis);
        }
};

#endif // CIRCLE_H
