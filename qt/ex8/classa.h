#ifndef CLASSA_H
#define CLASSA_H
#include <iostream>
#include <stdio.h>

class A {

private:
    int *Ptr= nullptr;
    int m_size;

public:
    A(int value=0,int size=0):m_size(size){
        if(m_size>0){
            Ptr=new int [size];
            for(int i=0;i<size;++i)
                Ptr[i]=value;
        }
    }

    A(const A& source){
        if(this!=(&source) && (source.Ptr!=nullptr)){
                m_size=source.m_size;
                Ptr=new int [m_size];
                for(int i=0;i<m_size;++i)
                    Ptr[i]=source.Ptr[i];
        }
    }
    ~A(){
        if(Ptr!=nullptr)
            delete [] Ptr;
    }

    A& operator =(const A &source){
        if(this!=(&source) && (source.Ptr!=nullptr)){
            m_size=source.m_size;
            if(Ptr!=nullptr) delete Ptr;
            Ptr=new int [m_size];
            for(int i=0;i<m_size;++i)
                Ptr[i]=source.Ptr[i];
        }
        return *this;
    }

    A& operator ++(){
        Add1(*this);
        return *this;
    }

    A operator ++(int unused){

       A temp(*this);
       Add1(*this);
       return temp;
    }

    void Add1(A &source){
        for (int i=0;i<source.m_size;i++)
        ++source.Ptr[i];
    }
};
#endif // CLASSA_H
