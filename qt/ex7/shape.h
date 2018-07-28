#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <iostream>
using namespace std;

class shape
{
public:
    shape(string type);
    void report();
    virtual ~shape();

protected:
    virtual float getArea()=0;
    virtual float getCircumference()=0;
private:
    string  type;

};

#endif // SHAPE_H
