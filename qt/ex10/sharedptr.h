#ifndef SHAREDPTR_H
#define SHAREDPTR_H
#include <iostream>
using namespace std;

template <typename T>
class sharedPtr {
     T* ptr;
     int* count=new int ;
public:
     sharedPtr(T* ptr=nullptr):ptr(ptr){
         *count=1;
         //cout<<"Constructor count "<<*count<<endl;
     }

     ~sharedPtr(){
         if(*count>0){
             (*count)--;
         }
         cout<<" Destructor count "<<*count<<endl;
         if(*count==0){
             cout<<"deleting raw pointers"<<endl;
             delete count;
             delete ptr;
         }
     }

     T& operator* () const {return *ptr; }

     T* operator-> () const { return ptr;}

     sharedPtr(const sharedPtr<T>& CopySource){
         (*CopySource.count)++;
         this->ptr=CopySource.ptr;
         this->count=CopySource.count;
         //cout<<"Copy constructor, count "<<*count<<endl;
     }

     sharedPtr& operator=(const sharedPtr<T> & CopySource) {
         checkDelete();
         (*CopySource.count)++;
         this->ptr=CopySource.ptr;
         this->count=CopySource.count;
         //cout<<"Copy assign, count "<<*count<<endl;
     }

     int useCount(){
         return *count;
     }
     void checkDelete(){
         if(this->ptr!=nullptr)
         {
             (*count)--;
             if(*count==0){
                 delete ptr;
                 delete count;
                 ptr=nullptr;
                 count=nullptr;
                 cout<<"deleting old allocations before copy assign"<<endl;
             }
         }
     }

};

#endif // SHAREDPTR_H
