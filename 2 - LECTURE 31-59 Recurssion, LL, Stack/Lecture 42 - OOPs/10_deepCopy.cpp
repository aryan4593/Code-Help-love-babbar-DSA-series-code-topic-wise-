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

};

int main() {
    Hero hero1(12, 'd');
    char name[6] = "aryan";
    hero1.setName(name);
    hero1.print();

    Hero hero2 = hero1;  // Copy assignment operator 
    hero2.print();

    hero1.name[0] = 'B';
    hero1.print();
    hero2.print();

    return 0;
}
