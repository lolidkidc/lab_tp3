#pragma once
#include <fstream>

class Figure {
public:
    Figure() {};
    virtual ~Figure() {};
    virtual float area() = 0;
    virtual void show() = 0;
    virtual void edit() = 0;
    virtual void fprint(std::ofstream &path) = 0;
    virtual int getid() = 0;
    static int counter;
};
