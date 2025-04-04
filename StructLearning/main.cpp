#include <iostream>

using namespace std;



struct Point2D
{

    double x;
    double y;
};

struct Point3D
{

    double x;
    double y;
    double z;
};



int main()
{

    Point2D origin2D;
    origin2D.x = 0.0;
    origin2D.y = 0.0;

    Point2D point1 = {5.2, 3.7}; // Another way to initialize

   std::cout << "Origin (2D): (" << origin2D.x << ", " << origin2D.y << ")" << std::endl;
    std::cout << "Point 1 (2D): (" << point1.x << ", " << point1.y << ")" << std::endl;

    // Create instances of Point3D
    Point3D origin3D = {0.0, 0.0, 0.0};
    Point3D point2;
    point2.x = 1.0;
    point2.y = 2.5;
    point2.z = -3.1;

    std::cout << "\nOrigin (3D): (" << origin3D.x << ", " << origin3D.y << ", " << origin3D.z << ")" << std::endl;
    std::cout << "Point 2 (3D): (" << point2.x << ", " << point2.y << ", " << point2.z << ")" << std::endl;

    return 0;
}
