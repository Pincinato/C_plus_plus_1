#include <iostream>
#include <vector>
#include "triangle.h"
#include "square.h"
#include "circle.h"

int main()
{
    triangle t1(1,2);
    triangle t2(3,4);
    triangle t3(5,6);
    square s1(1);
    square s2(2);
    square s3(3);
    circle c1(1);
    circle c2(2);
    circle c3(3);

    std::vector<shape*> shapeVec{&t1, &t2, &t3, &s1, &s2, &s3, &c1, &c2, &c3};

    // Range-based for loop (C++11)
    for(auto element : shapeVec)
    {
        element->report();
    }
    int i =0;
    i=++i;
    cout<<endl<<i<<endl;
    i=i++;
    cout<<endl<<i<<endl;
    i++;
    cout<<endl<<i<<endl;
    return 0;
}
