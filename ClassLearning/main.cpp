#include <iostream>
#include <string>
using namespace std;

class Dog{
private:

    string name;
    int age;

public:
    void setName(const string& newName)
    {

        name = newName;
    }

    string getName() const{
    return name;
    }

    // Public member function to set the age


     void setAge(int newAge) {
        if (newAge >= 0) {
            age = newAge; // We can add validation here
        } else {
            std::cerr << "Age cannot be negative." << std::endl;
        }
    }

    // Public member function to get the age
    int getAge() const {
        return age;
    }

    // Public member function to make the dog bark
    void bark() const {
        std::cout << "Woof!" << std::endl;
    }



    };


    int main() {
    Dog myDog;
    myDog.setName("Buddy"); // Accessing public member function
    myDog.setAge(3);      // Accessing public member function

    std::cout << "Dog's name: " << myDog.getName() << std::endl; // Accessing public member function
    std::cout << "Dog's age: " << myDog.getAge() << std::endl;   // Accessing public member function
    myDog.bark();          // Accessing public member function

    // The following would cause an error because 'name' and 'age' are private:
    // myDog.name = "Max";
    // std::cout << myDog.age << std::endl;

    return 0;
}



