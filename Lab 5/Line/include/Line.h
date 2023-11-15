
#ifndef LINE_H
#define LINE_H
#include<graphics.h>
#include <conio.h>
class Line {
    // For Composition
    Point p_left , p_right ;
    public:
        ~Line() {};
        // Constructor 1
         Line():p_left(15,15),p_right(50,50){};

         // Constructor 2
         Line(Point p_left_ , Point p_right_  ){
            p_left = p_left_;
            p_right = p_right_;
        }
        // Constructor 3
         Line(int x_left ,int y_left ,int x_right ,int y_right){
            p_left.set_xy(x_left , y_left);
            p_right.set_xy(x_right , y_right);

        }
        void set_p_left(int x , int y){
            p_left.set_x(x);
            p_left.set_y(y);
        }
        void set_p_right(int x , int y){
            p_right.set_x(x);
            p_right.set_y(y);
        }
        void Draw(){
            initwindow( 600, 400 , "Line");
            line(p_left.get_x() , p_left.get_y() ,p_right.get_x() , p_right.get_y() );
            getch();
        }

        // For Association
        void Draw( Point P1 , Point P2){
            initwindow( 600, 400 , "Line");
            line( P1.get_x() ,  P1.get_y() ,P2.get_x() , P2.get_y() );
            getch();
        }
};

#endif // LINE_H
