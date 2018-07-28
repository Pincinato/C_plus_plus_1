#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    stack <int> intStack;
    stack <double> doubleStack;
    stack <string> stringStack;
    //Testing intStack
    cout<<endl<<"Stack with int :"<<endl;
    intStack.push(100);
    cout<<intStack.peek()<<endl; //100
    intStack.push(50);
    cout<<intStack.peek()<<endl; // 50
    intStack.push(200);
    cout<<intStack.peek()<<endl; // 200
    intStack.pop();
    cout<<intStack.peek()<<endl; //50
    intStack.pop();
    cout<<intStack.peek()<<endl; //100
    //Testing doubleStasck
    cout<<endl<<"Stack with double :"<<endl;
    doubleStack.push(10.75);
    cout<<doubleStack.peek()<<endl; //10.75
    doubleStack.push(0.45);
    cout<<doubleStack.peek()<<endl; //0.45
    doubleStack.push(2.223);
    cout<<doubleStack.peek()<<endl; //2.223
    doubleStack.pop();
    cout<<doubleStack.peek()<<endl; //0.45
    doubleStack.pop();
    cout<<doubleStack.peek()<<endl; //
    //Testing stringStack
    cout<<endl<<"Stack with double :"<<endl;
    stringStack.push("10.75");
    cout<<stringStack.peek()<<endl; //10.75
    stringStack.push("Test");
    cout<<stringStack.peek()<<endl; //Test
    stringStack.push("Testing stringStack");
    cout<<stringStack.peek()<<endl; // Testing stringStack
    stringStack.pop();
    cout<<stringStack.peek()<<endl; //test
    stringStack.pop();
    cout<<stringStack.peek()<<endl; //10.75
    return 0;
}
