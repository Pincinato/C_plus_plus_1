#ifndef EX2_4_H
#define EX2_4_H
#include <iostream>
using namespace std;


class a2
{
   /// friend class b2; ///-represent another solution
public:
    a2(){
        m_A=6;
    }
    void printM_A(){
        cout<<endl<<m_A;
    }
protected: //could be protected or private, however protected is more consistent regarding object orientation. ///private
    int m_A;
};

class b2: protected a2//private a2
{

public:
    void printM_A_b(){
        cout<<endl<<m_A;
    ///   A.printM_A();
    }
private:
    ///a2 A;
};


class c2: public b2 //could be protected or private
{
public:

    void printM_A_c(){
       cout<<"In c: "<<m_A<<endl;
    }
    void printM_A_c_a(){
        cout<<"In c, using print of a :";
        printM_A();
    }
};

#endif // EX2_4_H
