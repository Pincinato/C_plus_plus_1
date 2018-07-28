#include "calculater.h"

int add(const int &n1,const int &n2){

    return n1+n2;

}

void add(const int &n1,const int &n2,int &sum){

    sum=n1+n2;
    return;
}

int addNumber(const int &n1,const int &n2,const int &n3,const int &n4,const int &n5){

    return n1+n2+n3+n4+n5;
}

void printType(const int intNumber){

    cout<<" int ";
}
void printType(const double doubleNumber){

    cout<<" double ";
}
void printType(const float floatNumber){

    cout<<" float ";
}
void printType(const string stringNumber){

    cout<<" string ";
}
