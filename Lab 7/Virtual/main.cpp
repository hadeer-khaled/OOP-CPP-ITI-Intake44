#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <Point.h>
#include <Line.h>
#include <Shape.h>
#include <Circle.h>
#include <Rectangle.h>

using namespace std;

int main()
{
    int n = 0;
    int shape_type = 0;
    int raduis = 0;
    int color  = 15;

    Point P_center, line_start, line_end, rec_left, rec_right;

    cout << "NOTE Shapes Codes: 0 for Line, 1 for Circle, 2 for Rectangle" << endl;
    cout << "NOTE Colors Codes: Blue = 1 , Green = 2, Red = 4 , Yellow = 14" << endl<<endl;
    cout << "Enter the number of shapes: ";
    cin >> n;

    Shape * shapes_arrar[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Type of shape number (" << i + 1 << "): ";
        cin >> shape_type;
        switch (shape_type)
        {
        case 0:
            shapes_arrar[i] = new Line();
            cout << "Enter the Start point: " << endl;
            cin >> line_start;
            shapes_arrar[i]->set_p1(line_start.get_x(), line_start.get_y());

            cout << "Enter the End point: " << endl;
            cin >> line_end;
            shapes_arrar[i]->set_p2(line_end.get_x(), line_end.get_y());

            cout<< "Enter the color: ";
            cin >> color ;
            shapes_arrar[i]->setColor(color);
            break;

        case 1:
            shapes_arrar[i] = new Circle();
            cout << "Enter the center point: " << endl;
            cin >> P_center;
            shapes_arrar[i]->setCenter(P_center.get_x() , P_center.get_y());

            cout << "Enter the raduis: " << endl;
            cin >> raduis;
            shapes_arrar[i]->setRaduis(raduis);

            cout<< "Enter the color: ";
            cin >> color ;
            shapes_arrar[i]->setColor(color);
            break;

        case 2:
            shapes_arrar[i] = new Rectanglee();
            cout << "Enter the Top Left point: " << endl;
            cin >> rec_left;
            shapes_arrar[i]->set_p1(rec_left.get_x() , rec_left.get_y());

            cout << "Enter the Bottom Right point: " << endl;
            cin >> rec_right;
            shapes_arrar[i]->set_p2(rec_right.get_x() , rec_right.get_y());

            cout<< "Enter the color: ";
            cin >> color ;
            shapes_arrar[i]->setColor(color);

            break;
        }
    }

    initwindow(600, 400, "Shapes");

    // Draw all Shapes
    for (int i = 0; i < n; i++)
    {
        setcolor(shapes_arrar[i]->getColor());
        shapes_arrar[i]->Draw();
    }
     _getch();

    // Close the graphics window
    closegraph();

    return 0;
}
