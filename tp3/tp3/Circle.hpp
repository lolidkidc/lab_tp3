#pragma once
#include "figure.hpp"

class Circle final : public Figure {
private:
    float radius;
public:
    Circle();
    Circle(float radius);
    Circle(const Circle& copy_circle);
    virtual ~Circle();
    virtual float area() override;
    virtual void show() override;
    virtual void edit() override;
    virtual void fprint(std::ofstream &path) override;
    virtual int getid() override;
};
