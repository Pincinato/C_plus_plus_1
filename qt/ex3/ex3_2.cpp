#include "ex3_2.h"

void ex3_2_AllocatingFreeingMemory(){
    cout<<"How many values do you want to enter?:  ";
    int quantityOfValues=0;
    int value=0;
    if(getUserInput(quantityOfValues)){
        if(quantityOfValues<1){
            cout<<"Input Invalid"<<endl;
            return;
        }
        int *arrayValues_ex1=new int[quantityOfValues];
        unique_ptr < int []> smartPtr ( new int [ quantityOfValues ]);
        vector <int> StlVector;
        StlVector.clear();
        int i=0;
        for(i; i<quantityOfValues;++i){
            cout<<i+1<<". Value ";
            if(getUserInput(value)){
                arrayValues_ex1[i]=value; // or *(arrayValues_ex1+i)
                smartPtr[i]=value;
                StlVector.push_back(value);
            }
            else{
                break;
            }
        }
        if(i==quantityOfValues){
            printFinalResult(" index acess",sumIndexAcess(&arrayValues_ex1[0],quantityOfValues),minIndexAcess(arrayValues_ex1,quantityOfValues),maxIndexAcess(&arrayValues_ex1[0],quantityOfValues));
            printFinalResult(" pointer arithmetic",sumIndexAcess(arrayValues_ex1,quantityOfValues),minIndexAcess(&arrayValues_ex1[0],quantityOfValues),maxIndexAcess(arrayValues_ex1,quantityOfValues));
            printFinalResult(" Smart pointer",sumSmartPtr(smartPtr,quantityOfValues),minSmartPtr(smartPtr,quantityOfValues),maxSmartPtr(smartPtr,quantityOfValues));
            printFinalResult(" STL Vector ",sumStlVector(StlVector),minStlVector(StlVector),maxStlVector(StlVector));
        }
        delete[] arrayValues_ex1;
    }

}

void ex3_2_Pitfalls(){

    cout<<endl<<" What is wrong here? "<<endl;
    cout<<" In the line: pointToAnInt = 9; there is an attribution to the pointer pointToAnInt "<<endl;
    cout<<"and it should be to the value indicates by the pointer (*pointtoAnInt=9)  "<<endl;
    whatIsWrongHere();
    cout<<endl<<"Why and where does the program crash ?"<<endl;
    cout<<" In the line: int pointToAnInt = new int ; there is an impossible conversion between an int and an poiter to an int "<<endl;
    cout<<"pointToAnInt should be a pointer ( int *pointtoAnInt)  "<<endl;
    whyAndWhereCrash();
    cout<<endl<<"Fix the function"<<endl;
    cout<<"allocateArray can not retunr a int * of an automatic varible,"<<endl;
    cout<<"int * temp= new int[length]"<<endl<<"return temp "<<endl;
    int * a= allocateArray(50000000);
    delete[] a;
    cout<<endl<<"Hoppla"<<endl;
    cout<<"1 st, the array has 5 position, so the for should stop at value 4 and not 5 (0-4)."<<endl;
    cout<<"2 nd, the last position of the array has no attribution"<<endl;
    cout<<"3 rd, As the remarks 1 and 2 are not respected, the program acess addresses (5,6), where we cannot know which values are storaged"<<endl;
    hoppla();

}


int * allocateArray(const int length){

    int * temp= new int[length];
    return temp;
}

void whatIsWrongHere(){
    cout <<"Solution output"<<endl;
    int * pointToAnInt = new int ;
    * pointToAnInt = 9;
    cout << " The value at pointToAnInt : " << * pointToAnInt <<endl;;
    delete pointToAnInt ;
}

void whyAndWhereCrash(){
    cout <<"Solution output"<<endl;
    int *pointToAnInt = new int ;
    int * pNumberCopy = pointToAnInt ;
    * pNumberCopy = 30;
    cout << * pointToAnInt<<endl;
    delete pNumberCopy ;
    delete pointToAnInt ;
}

void hoppla(){
    cout <<"Solution output"<<endl;
    int array [5] { 0, 1, 2, 3,0 };
    for ( int count = 0; count <= 4; ++ count )
        cout << array [ count ] << " ";
    cout <<endl;

}
