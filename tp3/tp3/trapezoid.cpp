#include "trapezoid.hpp"
#include <iostream>

using namespace std;

Trapezoid::Trapezoid() : a(0.0), b(0.0), h(0.0) { counter++; }
Trapezoid::Trapezoid(float a, float b, float h) {
    this->a = a;
    this->b = b;
    this->h = h;
    counter++;
}
Trapezoid::Trapezoid(const Trapezoid& copy_trapezoid){
    a = copy_trapezoid.a;
    b = copy_trapezoid.b;
    h = copy_trapezoid.h;
}
Trapezoid::~Trapezoid(){
    counter--;
    delete this;
}
float Trapezoid::area() { return (a + b) * 0.5 * h; }

void Trapezoid::show() {
    cout << "Trapezoid:\n A = " << a << "\n B = " << b << "\n H = " << h << "\n Area = " << this->area() << endl;
}
void Trapezoid::edit() {
    float x;
    cout << "Enter A = " << endl;
    cin >> x;
    this->a = x;
    cout << "Enter B = " << endl;
    cin >> x;
    this->b = x;
    cout << "Enter H = " << endl;
    cin >> x;
    this->h = x;
    cout << "Editing is over. A = " << a << "B = " << b << "H = " << h << endl;
}
int Trapezoid::getid() { return 4; }

void Trapezoid::fprint(ofstream &path) {
    path << this->a << " " << this->b << " " << this->h << " ";
}
