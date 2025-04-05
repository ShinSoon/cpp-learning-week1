#include <iostream>
#include <string>

using namespace std;

class Box {

private:
    double length;
    double width;
    double height;

public:

    Box(double l, double w, double h):length(l),width(w),height(h){

        cout << " the box is born on the heap !" << endl;
    }

    //destructor

    ~Box()
    {

        cout << "the box object is being destroyed." << endl;
    }

    double getVolumn() const{
        return length*width*height;


    }



};


int main()
{


    Box* heapBox = new Box(10, 5, 2);

    if(heapBox != nullptr)
    {

        double BoxVolume = heapBox->getVolumn();

        cout << "The volumn of the box is " << BoxVolume << endl;
    }

    delete heapBox;
    heapBox = nullptr;
}
