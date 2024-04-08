#include <iostream>
#include <string>
using namespace std;
class DomesticAnimal {
protected:
    string name;
    string species;
    int age;
public:
    DomesticAnimal(string animalName, string animalSpecies, int animalAge) {
        name = animalName;
        species = animalSpecies;
        age = animalAge;
    }
    void displayInfo() {
        cout << "name: " << name << endl;
        cout << "age: " << species << endl;
        cout << "age: " << age << " age" << endl;
    }
};
class Dog : public DomesticAnimal {
public:
    Dog(string dogName, int dogAge) : DomesticAnimal(dogName, "Dog", dogAge) {}
};
class Cat : public DomesticAnimal {
public:
    Cat(string catName, int catAge) : DomesticAnimal(catName, "Cat", catAge) {}
};
class Parrot : public DomesticAnimal {
public:
    Parrot(string parrotName, int parrotAge) : DomesticAnimal(parrotName, "Parrot", parrotAge) {}
};
int main() {
    Dog myDog("Πεκρ", 3);
    Cat myCat("Murzik", 5);
    Parrot myParrot("Cash", 2);
    cout << "Information about my dog:" << endl;
    myDog.displayInfo();
    cout << endl;
    cout << "Information about my cat:" << endl;
    myCat.displayInfo();
    cout << endl;
    cout << "Information about my parrot:" << endl;
    myParrot.displayInfo();
    cout << endl;
    return 0;
}
