#include <iostream>
#include "uniqueptr.h"
#include "sharedptr.h"

using namespace std;


uniquePtr<double> checkMove(uniquePtr<double> UP)
{
    *UP += 1;
    return UP;
}

uniquePtr<int[]> checkMove(uniquePtr<int[]> UP)
{
    //cout<<endl<<*UP<<endl;
    return UP;
}

int main()
{
    cout << "*** Test Unique Pointer ***" << endl << endl;
    uniquePtr<double> up1(new double(3.1415));
    cout << "Value of up1: " << *up1 << endl << endl;

    {   cout<< "Create scope to check move-assign"<<endl;
        uniquePtr<double> up2(new double(23));
        cout << "Value of up2: " << *up2 << endl << endl;
        up1 = std::move(up2);
        uniquePtr<int> up9;
    }
    cout << "Value of up1 after move: " << *up1 << endl << endl;
    uniquePtr<double> up2 = checkMove(std::move(up1));
    cout << "Value of up2 after check move: " << *up2 << endl << endl;

    ////////////////////////////////////////////////////////
    cout<<"-------------------------------------"<<endl;
    cout << "*** Test Unique Pointer []***" << endl << endl;
    uniquePtr<int []> up31(new int[3]);
    up31[0]=1;
    up31[1]=2;
    up31[2]=3;
    cout << "Value of up31 before move-assign: ";
    for (int i=0;i<3;i++){cout<<" "<<up31[i];}
    cout<< endl << endl;
    {   cout<<"Create scope to check move-assign"<<endl;
        uniquePtr<int []> up41(new int[3]);
        up41[0]=4;
        up41[1]=5;
        up41[2]=6;
        cout << "Value of up41: " ;
        for (int i=0;i<3;i++){cout<<" "<<up41[i];}
        cout<< endl;
        up31 = std::move(up41);
    }
    cout << "Value of up31 after move-assign: ";
    for (int i=0;i<3;i++){cout<<" "<<up31[i];}
    cout<< endl;
    uniquePtr<int []> up41 = checkMove(std::move(up31));
    cout << "Value of up41 after checkMove move ";
    for (int i=0;i<3;i++){cout<<" "<<up41[i];}
    cout<< endl;
   ////////////////////////////////////////////////////////////////////////
    cout<<"-------------------------------------------------------"<<endl;
    cout << "*** Test SharedPointer ***" << endl << endl;
    sharedPtr<int> sp1(new int(10));
    cout << "UseCount of sp1: " << sp1.useCount() << endl ;
    sharedPtr<int> sp2(new int(42));
    cout << "UseCount of sp2: " << sp2.useCount() << endl;
    cout << "Value of sp2 is: " << *sp2 << endl;
    {  cout<< endl<< "Create scope to check copy constructor" <<endl;
        sharedPtr<int> sp3(sp2);
        cout << "UseCount after copy: sp2: " << sp2.useCount() << " sp3: " << sp3.useCount() << endl;
        cout << "Values after copy: sp2: " << *sp2 << " sp3: " << *sp3  << endl;
        cout<<"End scope to check copy constructor" <<endl;
    }

    {   cout<< "Create scope to check assignment operator call "<<endl;
        sharedPtr<int> sp3(new int(10));
        sharedPtr<int> sp4;
        sharedPtr<int> sp5(new int(14));
        sharedPtr<int> sp6(sp5);
        sharedPtr<int> sp7(new int (111));
        sharedPtr<int> sp8;
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
