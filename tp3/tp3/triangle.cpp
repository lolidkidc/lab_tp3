#include "triangle.hpp"
#include <iostream>

using namespace std;

Triangle::Triangle() : a(0.0), b(0.0) { counter++; }
Triangle::Triangle(float a, float b) {
    this->a = a;
    this->b = b;
    counter++;
}
Triangle::Triangle(const Triangle& copy_triangle){
    a = copy_triangle.a;
    b = copy_triangle.b;
}
Triangle::~Triangle() {
    counter--;
    delete this;
}
float Triangle::area() { return a * b / 2; }

void Triangle::show() {
    cout << "Right Triangle:\n Side =  " << a << "\n Height = " << b << "\n Area = " << this->area() << endl;
}

void Triangle::edit() {
    float x;
    cout << "Enter the value of the side" << endl;
    cin >> x;
    this->a = x;
    cout << "Enter the value of the height" << endl;
    cin >> x;
    this->b = x;
    cout << "Editing is over. Side = " << a << "Height = " << b << endl;
}
int Triangle::getid() { return 3; }

void Triangle::fprint(ofstream &path) {
    path << this->a << " " << this->b << " ";
}
