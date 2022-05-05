#pragma once
#include "figure.hpp"

class Rectangle final : public Figure {
private:
    float a;
    float b;
public:
    Rectangle();
    Rectangle(float a, float b );
    Rectangle(const Rectangle& copy_rectangle);
    virtual ~Rectangle();
    virtual float area() override;
    virtual void show() override;
    virtual void edit() override;
    virtual void fprint(std::ofstream &path) override;
    virtual int getid() override;
};
