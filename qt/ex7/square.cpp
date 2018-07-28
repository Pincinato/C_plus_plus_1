#include "square.h"

square::square(float comp):shape("Square")
{
    this->comp=comp;
}

square::~square(){

    cout<<"Square destructor called"<<endl;
}


float square::getArea() {


    return getComp()*getComp();
}

float square::getCircumference() {

    return 4*getComp();

}

float square::getComp(){

    return comp;
}
