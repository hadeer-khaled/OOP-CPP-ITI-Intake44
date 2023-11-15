#ifndef LINE_H
#define LINE_H
#include <Shape.h>
#include <conio.h>

class Line : public Shape{
    //Point p_left , p_right ;
    public:
        ~Line() {};
        // Constructor 1
        // Line():p1(15,15),p2(50,50){}; //CANNOT DO THIS COZ P1,P2 ARE PRIVATE

         // Constructor 2
         /*Line(Point p_left_ , Point p_right_  ){ // Need Copy Constructor
            p1 = p_left_;
            p2 = p_right_;
        }*/
        // Constructor 3
        //Line(){}
         /*Line(int x_left ,int y_left ,int x_right ,int y_right){

            p1.set_p1(x_left , y_left);
            p2.set_p2(x_right , y_right);

        }*/
        Point get_p1(void){
            return p1;
        }
        Point get_p2(void){
            return p2 ;
        }

        void Draw(){
            line(p1.get_x() , p1.get_y() ,p2.get_x() , p2.get_y() );
        }

};

#endif // LINE_H
