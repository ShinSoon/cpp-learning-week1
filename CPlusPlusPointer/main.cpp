#include <iostream>

using namespace std;

void modifyByReference(int &x)
{
    x = x*2;

}


int main()
{

    int number = 10;
    std::cout << "Before " << number << std::endl;

    modifyByReference(number);

    std::cout << "After : " << number << std::endl;
}
