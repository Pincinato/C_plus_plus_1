#include <iostream>
#include "dynamic.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    char h='H';
    char e='E';
    char y ='y';
    char fim=0;
    const char * const test= &h;
    char * t = const_cast<char *> (test);
    *t='l';
    t=&e;
    std::cout<<*test<<std::endl;
    std::cout<<t<<std::endl;
    Fish *objBase= new Fish;
    Fish *objBase2= new Fish;
    Tuna *objDer = static_cast<Tuna *> (objBase);
    Tuna *objDerDynamic = dynamic_cast <Tuna *> (objBase2);
    objDer->becomeDinner();
    objDer->swim();
    objDerDynamic->becomeDinner();
    std::cout<<"New test"<<std::endl;
    Tuna *t1=new Tuna;
    Carp *c1= new Carp;
    //vector<Fish *> mylist{&t1,&c1};
    Fish * mylist[]= {t1,c1};
    mylist[0]->swim();
    mylist[1]->swim();
    delete objDer;
    delete objDerDynamic;
    delete t1;
    delete c1;
    delete [] mylist;
    delete [] test;
    return 0;
}
