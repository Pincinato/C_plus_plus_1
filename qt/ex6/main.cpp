#include <iostream>
#include "checkingaccount.h"
#include "abc.h"
#include "ex2_4.h"

void printAnswer2_2();
void printAnswer2_3();
void printAnswer2_4();

int main()
{
    checkingaccount myAccount(1000, 0.5); // initial amount and fee
    myAccount.credit(250);    // ok
    myAccount.printBalance(); // -> 1250
    myAccount.debit(1000);    // ok
    myAccount.printBalance(); // -> 249.5
    myAccount.debit(249.5);   // Waring: Not enough funds
    myAccount.debit(249);     // ok
    myAccount.printBalance(); // -> 0
    printAnswer2_2();
    printAnswer2_3();
    printAnswer2_4();
    return 0;
}

void printAnswer2_2(){
    cout<<endl<<"Ex a"<<endl;
    cout<<"output:"<<endl;
    cout<<"Base()"<<endl;
    cout<<"Derived()"<<endl;
    cout<<"Base()"<<endl;
    cout<<"~Base()"<<endl;
    cout<<"~Derived()"<<endl;
    cout<<"~Base()"<<endl;
    cout<<"Explanation: "<<endl<<"The order of construction is first base class,second derived class."<<endl;
    cout<<"Concerning the order of destruction, the sequencie is the opposite. First the derived class, second the base class."<<endl;
    cout<<"Another important aspect is the order in which the classes are declared. ";
    cout<<"The objects are constructed by following the order of declaration. In this case, first object d and second object b. ";
    cout<<"However, the destruction follows the oppposite direction, so the fist object to be deleted will be the object b."<<endl;
    cout<<endl<<"Ex b"<<endl;
    cout<<"The code will not compile because the int m_x is private, which means that the class derivated could not acess m_x in the overrinden method print (method print of the derived clas)"<<endl;

}

void printAnswer2_3(){

    cout<<endl<<endl<<"Ex 2.3 , output: "<<endl;
    cout<<"The general rule: "<<endl;
    cout<<"First the base classes are constructed and after the derivated classe."<<endl;
    cout<<"The objects are constructed by following the order of declaration. "<<endl;
    cout<<"However, the destruction follows the oppposite order."<<endl;
    abc myABC;

}

void printAnswer2_4(){

    cout<<endl<<"Ex 2.4 :"<<endl;
    cout<<"To make sure that class C could not have acess to m_A, we should use the Private Inheritance, by Class B: private A"<<endl;
    cout<<"In the previous solution, the variable m_A could be protected or public ."<<endl;
    cout<<"Out of scope of inheritance, it is also possible to use friend relationship,by making the Class B friend of A and B having a private class member A, which cannot be used in the derivated class C"<<endl;
    cout<<"The best solution would be the first one, using Private Inheritance and a protected variable m_A"<<endl;
}
