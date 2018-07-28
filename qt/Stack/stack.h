#ifndef STACK_H
#define STACK_H
#include <iostream>

template <typename T>
class Stack{

private:
    T array[100]=0;
    int m_top=0;
public:
    void push(const T& element){
        array[m_top]=element;
        m_top++;
    }

    T pop(){
      T temp=array[m_top];
      array[m_top]=0;
      m_top--;
      return temp;
    }

    T& peak(){
        return array[m_top];
    }

};

template<>
std::string Stack<std::string>::pop(){

    std::string temp=array[m_top];
    array[m_top]='0';
    m_top--;
    return temp;

}

#endif // STACK_H
