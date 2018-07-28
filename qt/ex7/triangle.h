#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"
#include<cmath>

class triangle final: public shape
{
public:
    triangle(float base, float height);
    ~triangle();
protected:
     float getArea() override;
     float getCircumference() override;
     float getBase();
     float getHeight();
private:
     float base;
     float height;
};

#endif // TRIANGLE_H
