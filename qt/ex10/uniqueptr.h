#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H
#include <iostream>
using namespace std;

template <typename T>
class uniquePtr {
     T* ptr;
public:
     uniquePtr(T* ptr=nullptr):ptr(ptr){if (this->ptr!=nullptr) cout<< "poiter "<<this->operator *()<<" constructor"<<endl;}
     ~uniquePtr(){ if (this->ptr!=nullptr) delete ptr; }
     T& operator* () const {return *ptr; }
     T* operator-> () const { return ptr;}
     uniquePtr(const uniquePtr&) = delete;
     uniquePtr& operator=(const uniquePtr&) = delete;

     uniquePtr(uniquePtr &&MoveSource){
         if(MoveSource.ptr!=nullptr){
             this->ptr=MoveSource.ptr;
             MoveSource.ptr=nullptr;
         }
     }

     uniquePtr& operator=(uniquePtr &&MoveSource){
         if((MoveSource.ptr!=nullptr)&(this->ptr != MoveSource.ptr)){
             this->clear();
             this->ptr=MoveSource.ptr;
             MoveSource.ptr=nullptr;
         }
         return *this;
     }

     void clear(){
        if(this->ptr!=nullptr){
            delete ptr;
            ptr=nullptr;
        }
     }

};

template <typename T>
class uniquePtr<T[]> {
     T* ptr;
public:
     uniquePtr(T* ptr=nullptr):ptr(ptr){ }
     ~uniquePtr(){if (ptr!=nullptr)  delete [] ptr;}
     T& operator* () const { return *ptr;}
     T* operator-> () const {return ptr;}
     T& operator[](int i) const {return *(ptr+i);}
     uniquePtr& operator=(const uniquePtr&) = delete;
     uniquePtr(const uniquePtr&) = delete;

     uniquePtr(uniquePtr &&MoveSource){
         if(MoveSource.ptr!=nullptr){
             this->ptr=MoveSource.ptr;
             MoveSource.ptr=nullptr;
         }
     }

     uniquePtr& operator=(uniquePtr &&MoveSource){
         if((MoveSource.ptr!=nullptr)&(this->ptr != MoveSource.ptr)){
             this->clear();
             this->ptr=MoveSource.ptr;
             MoveSource.ptr=nullptr;
         }
         return *this;
     }

     void clear(){
        if(this->ptr!=nullptr){
            delete [] ptr;
            ptr=nullptr;
        }
     }

};

#endif // UNIQUEPTR_H
