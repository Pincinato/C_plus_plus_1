#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

class square:public shape
{
public:
    square(float comp);
    ~square();
protected:
    virtual float getArea() override;
    virtual float getCircumference() override;
    float getComp();
private:
    float comp;
};

#endif // SQUARE_H
