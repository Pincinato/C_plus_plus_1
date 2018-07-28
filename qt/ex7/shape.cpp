#include "shape.h"

shape::shape(string type):type(type){

}

void shape::report(){

    cout<<type<<" has area "<<getArea()<<" and circumference: "<<getCircumference()<<endl;
}

shape::~shape(){
    cout<<"Shape destructor called"<<endl;
}
