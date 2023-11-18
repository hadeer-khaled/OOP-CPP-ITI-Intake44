#ifndef SHAPE_H
#define SHAPE_H


class Shape
{
    protected:
    int area = 0 , perm = 0 ,color = 0 , raduis = 10;
       Point p1 , p2;
    public:
       ~Shape(){}
       //Constructor 1
        Shape(): p1(0,0) , p2(10,10) {}

        // Constructor 2
         Shape(Point p_left_ , Point p_right_  ){
            p1 = p_left_;
            p2 = p_right_;
        }
        // Constructor 3
         Shape(int x_left ,int y_left ,int x_right ,int y_right){
            p1.set_xy(x_left , y_left);
            p2.set_xy(x_right , y_right);

        }
        void set_p1(int x , int y){
            p1.set_x(x);
            p1.set_y(y);
        }
        void set_p2(int x , int y){
            p2.set_x(x);
            p2.set_y(y);
        }
        Point get_p1(void){
            return p1;
        }
        Point get_p2(void){
            return p2;
        }
        virtual void setCenter(int x ,int y){};
        virtual void setRaduis(int raduis_){
           raduis = raduis_;
        }
        void setColor(int color_){
            color = color_;
        }
        int getColor(void){
            return color;
        }

        double get_area(int side1 ,int side2){}
        double get_perimeter(int side1 ,int side2){}
        virtual void Draw(){}

};

#endif // SHAPE_H
