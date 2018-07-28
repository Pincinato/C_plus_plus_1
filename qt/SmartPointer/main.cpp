#include <iostream>
#include <memory>
#include "auto_ptr.h"

using namespace std;

class Resource
 {
 public:
 Resource() { std::cout << "Resource acquired\n"; }
 ~Resource() { std::cout << "Resource destroyed\n"; }
 void print(){std::cout << "Print\n";}
 };

int main()
 {
 //auto_ptr<Resource> res(new Resource);
 //res.operator ->()->print();
 int *b = new int(100);
 std::unique_ptr<int> intPtr(b);
 int a =10;
 intPtr.reset(&a);
 std::cout<<*intPtr.release()<<std::endl;
 std::cout<<*b;
 ///////////////////////////////////////
 std::shared_ptr<char> charPtrShared (new char('a'));
 (charPtrShared.operator *())='b';
 std::cout<<charPtrShared <<std::endl;
 std::cout<<*b;
 return 0;
 }
