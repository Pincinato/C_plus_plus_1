#include "triangle.h"


triangle::triangle(float base,float height):shape("Triangle")
{
    this->base=base;
    this->height=height;

}

triangle::~triangle(){

    cout<<"Triangle destructor called"<<endl;

}


float triangle::getArea() {

    return getBase()*getHeight()/2;
}
float triangle::getCircumference() {

    return getBase()+sqrt(getBase()*getBase()+getHeight()*getHeight());
}

float triangle::getBase(){
    return base;
}

float triangle::getHeight(){
    return height;
}
