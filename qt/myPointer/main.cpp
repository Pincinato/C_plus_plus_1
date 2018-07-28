#include <iostream>
#include "pointers.h"

using namespace std;


unique_ptr<double> checkMove(unique_ptr<double> UP)
{
    *UP += 1;
    return UP;
}

//unique_ptr<int[]> checkMove(unique_ptr<int[]> UP)
//{
//    //cout<<endl<<*UP<<endl;
//    return UP;
//}

int main()
{
    cout << "*** Test Unique Pointer ***" << endl << endl;cout << "*** Test Unique Pointer ***" << endl << endl;cout << "*** Test Unique Pointer ***" << endl << endl;cout << "*** Test Unique Pointer ***" << endl << endl;
    cout << "*** Test Unique Pointer ***" << endl << endl;
    unique_ptr<double> up1(new double(3.1415));
    cout << "Value of up1: " << *up1 << endl << endl;

    {   cout<< "Create scope to check move-assign"<<endl;
        unique_ptr<double> up2(new double(23));
        cout << "Value of up2: " << *up2 << endl << endl;
        up1 = std::move(up2);
        unique_ptr<int> up9;
    }
    cout << "Value of up1 after move: " << *up1 << endl << endl;
    unique_ptr<double> up2 = checkMove(std::move(up1));
    cout << "Value of up2 after check move: " << *up2 << endl << endl;

    ////////////////////////////////////////////////////////
    cout<<"-------------------------------------"<<endl;
    cout << "*** Test SharedPointer ***" << endl << endl;
    shared_ptr<int> sp1(new int(10));
    cout << "UseCount of sp1: " << sp1.useCount() << endl ;
    shared_ptr<int> sp2(new int(42));
    cout << "UseCount of sp2: " << sp2.useCount() << endl;
    cout << "Value of sp2 is: " << *sp2 << endl;
    {  cout<< endl<< "Create scope to check copy constructor" <<endl;
        shared_ptr<int> sp3(sp2);
        cout << "UseCount after copy: sp2: " << sp2.useCount() << " sp3: " << sp3.useCount() << endl;
        cout << "Values after copy: sp2: " << *sp2 << " sp3: " << *sp3  << endl;
        cout<<"End scope to check copy constructor" <<endl;
    }

    {   cout<< "Create scope to check assignment operator call "<<endl;
        shared_ptr<int> sp3(new int(10));
        shared_ptr<int> sp4;
        shared_ptr<int> sp5(new int(14));
        shared_ptr<int> sp6(sp5);
        shared_ptr<int> sp7(new int (111));
        shared_ptr<int> sp8;
        cout << "UseCount of sp2: " << sp2.useCount() << endl<< endl;
        sp8 = sp2;
        sp5=sp3;
        sp4=sp5;
        sp7=sp5;
        cout << "UseCount after copy assign: sp2: " << sp3.useCount()<< " sp3: " << sp3.useCount() << " sp4: " << sp4.useCount() << " sp5: " << sp5.useCount()<< " sp6: " << sp6.useCount()<< " sp7: " << sp7.useCount()<< " sp8: " << sp8.useCount() << endl;
        cout << "Values after copy assign: sp2: " << *sp2<< " sp3: " << *sp3 << " sp4: " << *sp4 << " sp5: " << *sp5<< " sp6: " << *sp6<<" sp7: " << *sp7<<" sp8: " << *sp8<< endl << endl;
        cout<< endl<<"End check assignment operator call scope"<<endl << endl;
    }
    cout <<endl<< "UseCount of sp2: " << sp2.useCount() << endl;
    sp2=sp1;
    cout << "UseCount of sp2: " << sp2.useCount() << endl << "UseCount of sp1: " << sp1.useCount()<<endl ;
    cout << "Values: sp2: " << *sp2 << " sp1: " << *sp1 << endl << endl;
    return 0;
}
