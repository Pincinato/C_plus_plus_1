#ifndef DYNAMIC_H
#define DYNAMIC_H

#include <iostream>
 using namespace std;

 class Fish
 {
 public:
 virtual void swim(){cout << "Fish swims" << endl;}
 virtual ~Fish(){} // must be v i r t u a l
 };

 class Tuna: public Fish
 {
 public:
 void swim(){cout << "Tuna swims real fast" << endl;}

 void becomeDinner(){cout << "Tuna became Sushi" << endl;}
 };

 class Carp: public Fish
 {
 public:
 void swim(){cout << "Carp swims real slow" << endl;}

 void talk(){cout << "Carp talked carp!" << endl;}
};
#endif // DYNAMIC_H
