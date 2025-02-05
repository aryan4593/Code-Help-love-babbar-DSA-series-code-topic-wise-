#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Hero {
private:
    int health;

public:
    char level;
    char *name;

    // Constructor
    Hero (){

    }
    Hero(int h, char l) {
        health = h;
        level = l;
        name = new char[1];  // Initialize name with minimal memory
        name[0] = '\0';
    }

    // Copy constructor (Deep Copy)
    Hero(const Hero &temp) {
        health = temp.health;
        level = temp.level;
        name = new char[strlen(temp.name) + 1];
        strcpy(name, temp.name);
    }

    // Getter for health
    int getHealth() {
        return health;
    }

    // Setter for health
    void setHealth(int h) {
        health = h;
    }

    // Method to set name
    void setName(const char name[]) {
        delete[] this->name;  // Free the existing memory
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    // Method to print Hero details
    void print() {
        cout << "Health is " << health << endl;
        cout << "Level is " << level << endl;
        cout << "Name is " << name << endl;
    }

    ~Hero (){
        cout<<"destructor is called\n";
    }
};

int main() {
Hero a;

//when life of object is about to end destructor is called to free memory
//for static objects, destructor is automatically called
//but not for dynamically made object


Hero *b =new Hero;
delete b;   //manually called destructor

    return 0;
}
