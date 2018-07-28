#include "circle.h"

circle::circle(float radius, float pi):shape("Circle")
{
    this->radius=radius;
    this->pi=pi;
}


circle::~circle(){

    cout<<"Circle destructor called"<<endl;

}

float circle::getArea() {

    return getPi()*getRadius()*getRadius();
}

float circle::getCircumference() {

    return 2*getPi()*getRadius();
}

float circle::getRadius(){
    return radius;
}
float circle::getPi(){
    return pi;
}
