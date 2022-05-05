#pragma once
#include "figure.hpp"

class Trapezoid final : public Figure {
private:
    float a;
    float b;
    float h;
public:
    Trapezoid();
    Trapezoid(float a, float b, float h);
    Trapezoid(const Trapezoid& copy_trapezoid);
    virtual ~Trapezoid();
    virtual float area() override;
    virtual void show() override;
    virtual void edit() override;
    virtual void fprint(std::ofstream &path) override;
    virtual int getid() override;
};
