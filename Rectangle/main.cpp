#include <iostream>

using namespace std;

class Rectangle{
private:
    double width;
    double height;

public:

    // Add constructor to the Rectangle class:
    Rectangle(double w, double h) : width(w), height(h)
    {

        cout <<"Rectangle object created with width: " << width << " and height " << height << endl;
    }
    // Public member function to SetDimensions
    void setDimensions(double w, double h)
    {

        width = w;
        height = h;
    }

    double getHeight() const{// This is a method that return double which is the heigh 

        return height;
    }

    double getWidth() const{// This is another method that return double which is the width 

        return width;
    }

    double calculateArea() const
    {

        return width * height;
    }

};

int main()
{
     // Create a Rectangle object using the constructor
    Rectangle Rec(14.0, 15.0);

    cout << " Rectangle's Height: " << Rec.getHeight() << endl;
    cout << " Rectangle's Width: " << Rec.getWidth() << endl;
    cout << " Rectangle's Area: " << Rec.calculateArea() << endl;

    // You can still use setDimensions to change the dimensions later
    Rec.setDimensions(20.0, 10.0);
    cout << " Rectangle's Height after update: " << Rec.getHeight() << endl;
    cout << " Rectangle's Width after update: " << Rec.getWidth() << endl;
    cout << " Rectangle's Area after update: " << Rec.calculateArea() << endl;

    return 0;
}
