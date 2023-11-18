#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectanglee : public Shape{
    public:
        ~Rectanglee() {}
        Rectanglee() {}
        void Draw(){
            rectangle(p1.get_x() , p1.get_y() ,p2.get_x() , p2.get_y());
        }

};

#endif // RECTANGLE_H
