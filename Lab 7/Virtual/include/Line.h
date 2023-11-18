#ifndef LINE_H
#define LINE_H
#include <Shape.h>
#include <conio.h>

class Line : public Shape{
    public:
        ~Line() {};
        void Draw(){
            line(p1.get_x() , p1.get_y() ,p2.get_x() , p2.get_y() );
        }

};

#endif // LINE_H
