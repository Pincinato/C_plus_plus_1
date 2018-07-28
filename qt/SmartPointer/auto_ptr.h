#ifndef AUTO_PTR_H
#define AUTO_PTR_H
#include <iostream>

 template<class T>
 class auto_ptr
 {
 T* m_ptr;
 public:
auto_ptr(T* ptr=nullptr) : m_ptr(ptr)
 {
 }
 ~auto_ptr()
 {
 delete m_ptr;
 }


 T& operator *() const { return *m_ptr; }
 T* operator ->() const { return m_ptr; }
 };

#endif // AUTO_PTR_H
