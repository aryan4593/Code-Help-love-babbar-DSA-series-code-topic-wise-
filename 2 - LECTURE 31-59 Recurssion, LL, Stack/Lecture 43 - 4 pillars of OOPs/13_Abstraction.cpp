// Abstraction means showing only essential infoo and hiding implementation

#include <iostream>
using namespace std;

// Abstract base class
class Shape {
public:
    // Pure virtual function providing interface framework.
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
private:
    int radius;

public:
    Circle(int r) : radius(r) {}

    void draw() {
        cout << "Drawing a Circle with radius: " << radius << endl;
    }
};

class Rectangle : public Shape {
private:
    int width, height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    void draw() {
        cout << "Drawing a Rectangle with width: " << width << " and height: " << height << endl;
    }
};

int main() {
    Shape *shape1 = new Circle(5);
    Shape *shape2 = new Rectangle(4, 6);

    shape1->draw();
    shape2->draw();

    delete shape1;
    delete shape2;

    return 0;
}
