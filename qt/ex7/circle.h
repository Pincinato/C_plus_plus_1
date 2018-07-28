#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

class circle: public shape
{
public:
    circle(float radius,float pi=3.14);
    ~circle();
protected:
    virtual float getArea() override;
    virtual float getCircumference() override;
    float getRadius();
    float getPi();

private:
    float radius;
    float pi;
};

#endif // CIRCLE_H
