#ifndef POINTERS_H
#define POINTERS_H
#include <iostream>

template <typename T>
class unique_ptr{
private:
    T* ptr;
public:
    unique_ptr(T* pointer=nullptr):ptr(pointer){ }
    ~unique_ptr(){
        if (ptr!=nullptr){
            delete ptr;
            ptr=nullptr;
        }
    }
    unique_ptr(const unique_ptr &copySource)=delete;
    T& operator = (const unique_ptr &copySorce)=delete;

    unique_ptr(unique_ptr && moveSource){
        if(moveSource.ptr!=nullptr){
            ptr=moveSource.ptr;
            moveSource.ptr=nullptr;
        }
    }

    unique_ptr& operator = (unique_ptr&& moveSource){
      if((moveSource.ptr!=ptr) && (moveSource.ptr!=nullptr)){
            if(ptr!=nullptr) delete ptr;
            ptr=moveSource.ptr;
            moveSource.ptr=nullptr;
        }
      return (*this);
    }
    T& operator * () const { return *ptr; }
    T* operator -> () const {return ptr;}
    T& operator [] (int at) const;

};

template <typename T>
class shared_ptr{
private:
    T* ptr;
    int *count=new int;
public:
    shared_ptr(T* ptr=nullptr):ptr(ptr){
        if(ptr==nullptr) (*count)=0;
        else (*count) =1;
    }
    ~shared_ptr(){
        --(*count);
        if((count==0) && (ptr!=nullptr)){
            delete ptr;
            delete count;
            ptr=nullptr;
            count =nullptr;
        }
    }
    shared_ptr(const shared_ptr &copySource){
        if(copySource.ptr!=nullptr) {
            ptr=copySource.ptr;
            count=copySource.count;
            (*count)++;
        }
    }
    shared_ptr& operator = (const shared_ptr &copySource){
        if((copySource.ptr!=ptr) &&(copySource.ptr!=nullptr)){
            (*count)--;
            checkMemory();
            ptr=copySource.ptr;
            count=copySource.count;
            (*count)++;
        }
        return (*this);
    }
    void checkMemory(){
        if((count==0) && (ptr!=nullptr)){
            delete ptr;
            delete count;
            ptr=nullptr;
            count =nullptr;
        }
    }

    T& operator * () const { return *ptr; }
    T* operator -> () const {return ptr;}
    T& operator [] (int at) const;
    const int& useCount(){return (*count);}
};
#endif // POINTERS_H
