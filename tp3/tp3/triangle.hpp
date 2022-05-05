#pragma once
#include "figure.hpp"

class Triangle final : public Figure {
private:
    float a;
    float b;
public:
    Triangle();
    Triangle(float a, float b);
    Triangle(const Triangle& copy_triangle);
    virtual ~Triangle();
    virtual float area() override;
    virtual void show() override;
    virtual void edit() override;
    virtual void fprint(std::ofstream &path) override;
    virtual int getid() override;
};
