#include<iostream>
#include<string.h>
using namespace std;

class hero {
    private:
        int health;

    public:
        char level;
        char *name;

        hero(int health, char level) {
            this->level = level;
            this->health = health;
            // Allocate memory for name
            name = new char[100];
        }

        // Destructor to free allocated memory

        int getHealth() {
            return health;
        }

        void setHealth(int h) {
            health = h;
        }

        void print() {
            cout << "Health is " << health << endl;
            cout << "Level is " << level << endl;
            cout << "Name is " << this->name << endl;
        }

        void setName(char name[]) {
            strcpy(this->name, name);
        }
};

int main() {
    hero hero1(12, 'd');
    char name[6] = "aryan";
    hero1.setName(name);
    hero1.print();

    hero hero2 = hero1;  //default copyconstructor is called
    hero2.print();

    hero1.name[0]='B';
    hero1.print();
    hero2.print();      //hero 2; name changes too

    //this is called shalow copy
    // default copy constructor makes  shallow copy //means it copies addresses of hero 1 to hero 2
    return 0;
}
