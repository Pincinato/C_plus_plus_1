#include <iostream>
#define SQUARE(x) ((x)*(x))
#define Area(r) ((2)*(r)*(r))
#define AreaWrong(r) ((2)*r*r)

template<typename T>
const T& getmax(const T&T1,const T&T2){
    T* a =const_cast<T*>(&T2);
    (*a)+=2;
    return (T1 > T2) ? T1 : T2;
}

int& f (int &a){
        a*=2;
        return a;
}
int main()
{
    int testReference=1;
    int testreturnReferece=f(testReference);
    std::cout<<"testReference ="<<testReference<<std::endl;
    testreturnReferece++;
    std::cout<<"testReference ="<<testReference<<std::endl;
    std::cout<<"testreturnReferece ="<<testreturnReferece<<std::endl;
    std::cout << "Hello World!" << std::endl;
    int a= SQUARE(5);
    double b= SQUARE(5.05);
    std::cout<<"  a = "<<a<<"  b = "<<b<<std::endl;
    int area= Area(1+1);
    int areaW= AreaWrong(1+1);
    std::cout<<"  area = "<<area<<"  areaW = "<<areaW<<std::endl;
    int a1=10;
    int b1=15;
    int c=getmax(a1,b1);
    c=c+100;
    std::cout<<"C ="<<c<<" b1 ="<<b1<<std::endl;
    double a2=1.80;
    double b2=1.5;
    std::cout<<"Max ="<<getmax(a2,b2)<<std::endl;
    char a3='a';
    char b3='b';
    std::cout<<"Max ="<<getmax(a3,b3)<<std::endl;

    return 0;
}
