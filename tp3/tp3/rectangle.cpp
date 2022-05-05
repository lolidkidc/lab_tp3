#include "rectangle.hpp"
#include <iostream>

using namespace std;

Rectangle::Rectangle() : a(0.0), b(0.0) { counter ++; }
Rectangle::Rectangle(float a, float b ) {
    this->a = a;
    this->b = b;
    counter++;
}
Rectangle::Rectangle(const Rectangle& copy_rectangle){
    a = copy_rectangle.a;
    b = copy_rectangle.b;
}
Rectangle::~Rectangle() {
    counter --;
    delete this;
}

float Rectangle::area() { return a * b; }

void Rectangle::show() {
    cout << "Rectangle:\n Width = "<< a <<"\n Height = "<< b << "\n Area = "<< this->area() << endl;
}

void Rectangle::edit() {
    float x;
    cout << "Enter Width" << endl;
    cin >> x;
    this->a = x;
    cout << "Enter Height" << endl;
    cin >> x;
    this->b = x;
    cout << "Editing is over. Width = " << a <<" Height = " << b << endl;
}
int Rectangle::getid() { return 1; }

void Rectangle::fprint(ofstream &path) {
    path << this->a << " " << this->b << " ";
}
