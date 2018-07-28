#ifndef STACK_H
#define STACK_H
#include <string>
using namespace std;

template <typename T>

class stack {

public:
    stack(){
        m_top=-1;
    }

    T pop(){
        T temp=data[m_top];
        data[m_top]=0;
        m_top--;
        return temp;
    }
    void push(T value){
        m_top++;
        data[m_top]=value;
    }
    T peek(){
        return data[m_top];
    }
    ~stack(){

    }
private:
    int m_top;
    T data[100];
};

template <>
string stack<string>::pop(){
    string temp=data[m_top];
    data[m_top]=" ";
    m_top--;
    return temp;
}
template <>
stack<string>::~stack(){
    m_top=10;
}
#endif // STACK_H
