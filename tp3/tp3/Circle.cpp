#include "Circle.hpp"
#include <iostream>
#include <cmath>

using namespace std;

Circle::Circle() : radius(0.0) { counter ++; }
Circle::Circle(float radius) {
    this->radius = radius;
    counter++;
}
Circle::Circle(const Circle& copy_circle){
    radius = copy_circle.radius;
    
}
Circle::~Circle() {
    counter--;
    delete this;
}

float Circle::area() { return M_PI * radius * radius; }

void Circle::show() {
    cout << "Circle:\n Radius = " << radius << "\n Area = " << this->area() << endl;
}

void Circle::edit() {
    float x;
    cout << " Enter radius " << endl;
    cin >> x;
    this->radius = x;
    cout << "Editing is over. Radius = " << radius << endl;
}
int Circle::getid() { return 2; }

void Circle::fprint(ofstream &path) {
    path << this->radius << " ";
}

