#include <iostream>

using namespace std;

class complex_{
    int real ;
    int img ;

    public:
        int getReal(){
            return real;
        };
        void setReal(int real_){
            real = real_;
        };
        int getImg(){
            return img;
        };
        void setImg(int img_){
            img = img_;
        };
        friend ostream & operator << (ostream &out, const complex_ &c);
        friend istream & operator >> (istream &in,  complex_ &c);

        complex_ (int real =0  , int img = 0 ){
            this->real = real ;
            this->img = img;
        }

        void setComplex(int real , int img ){
            this->real = real ;
            this->img = img;
        };

        //  Operator Overloading
        complex_ operator + (complex_ & c){
            complex_ res( this->real + c.real , this->img + c.img ) ;
            return res;
        }

        complex_ operator + (int integer){
            complex_ res( this->real + integer, this->img ) ;
            return res;
        }
        complex_ operator += (complex_ & c){
           this->real = this->real + c.real;
            this->img = this->img  + c.img  ;
            return *this;
        }
        complex_ operator ++ (){ //prefix
           this->real = this->real +1;
            return *this;
        }
        complex_ operator ++ (int){ //postfix
           complex_ temp = *this ;
           this->real = this->real +1;
            return temp;
        }

        complex_ operator - (complex_ & c){
            complex_ res( this->real - c.real , this->img - c.img ) ;
            return res;
        }

        complex_ operator - (int integer){
            complex_ res( this->real - integer, this->img ) ;
            return res;
        }
        complex_ operator -- (){ //prefix
           this->real = this->real -1;
            return *this;
        }
        complex_ operator -- (int){ //postfix
           complex_ temp = *this ;
           this->real = this->real -1;
            return temp;
        }
        complex_ operator -= (complex_ & c){
           this->real = this->real - c.real;
            this->img = this->img  - c.img  ;
            return *this;
        }
         int operator == (complex_  c){
            return (this->real == c.real && this->img == c.img);
        }

        operator float(){
            return  real;
        }
        int operator[](int index) {
                if (index < 0 || index > 1) {
                    cout<< "Index Out of range" ;
                    return 00000 ;
                }
                switch(index){
                    case 0:
                        return this->real ;
                    case 1:
                        return this->img ;
                }
        }
    int operator[](const string& key) {
            if (key == "real")
            {
                return this->real;
            } else if (key == "imag")
            {
                return this->img;
            } else
            {
                cout << "Invalid Key\n";
                return 00000;
            }
        }


        void printIn(){
            //cout<<"Print with In class definition:  ";
            cout << real;
            if(img > 0){
                cout << " + " << img << "j" << endl;
            }
            else if(img < 0){
                cout << img << "j"<<endl;
            }
            else{}
        }
}; // End Class
        ostream & operator << (ostream &out, const complex_ &c)
        {
            out << c.real;
            if(c.img > 0){
                out << " + " << c.img << "j" << endl;
            }
            else if(c.img < 0){
                out << c.img << "j"<<endl;
            }
            else{}
            return out;
        }

        istream & operator >> (istream &in,  complex_ &c)
        {
            cout << "Enter Real Part ";
            in >> c.real;
            cout << "Enter Imaginary Part ";
            in >> c.img;
            return in;
        }

// Stand Alone Functions
complex_ operator + (int integer ,complex_ & c ){
            complex_ res;
            res.setComplex( integer + c.getReal(), c.getImg()) ;
            return res;
        }

complex_ operator - (int integer ,complex_ & c ){
            complex_ res;
            res.setComplex( integer - c.getReal(), c.getImg()) ;
            return res;
        }
int main()
{
    complex_ c1 ;
    complex_ c2 ;
    complex_ c3 ;

    c1.setComplex(10 ,16);
    //c1.printIn();

    c2.setComplex(10 ,10);
    //c2.printIn();


    //c3 = c1 + c2;
    //c3 = c1 + 5 ;
    //c3 = 5 + c1 ;
    //c3 = c2 - c1;
    //c3 = c1 - 5 ;
    //c3.printIn();

    // Comparison
    /*int res = c1==c2;
    cout << res ;*/

    // --------------- Prefix ---------------
    /*c3 = ++c1 ;
    c1.printIn();
    c3.printIn();*/

    // --------------- Postfix ---------------
    /*c3 = c1-- ;
    c1.printIn();
    c3.printIn();*/

    // ----------------- [index] ------------------
    cout << c1[0] <<endl ; // ==> 10
    cout << c1[1] <<endl ; // ==> 16

    // ----------------- [index] ------------------
    cout << c1["real"] <<endl ; // ==> 10
    cout << c1["imag"] <<endl ; // ==> 16

    return 0;
}

