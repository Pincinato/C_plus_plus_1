#include "calculater.h"


void ex2_1();
void ex2_1_1();
void ex2_1_2();
void ex2_1_3();
void ex2_2();
void ex2_3();
bool getUserInput(int &n1, int &n2);

int main()
{
    ex2_1();
    ex2_2();
    ex2_3();
    return 0;
}

void ex2_1(){

    ex2_1_1();
    ex2_1_2();
    ex2_1_3();

}

void ex2_2(){
    cout<<endl<<"Exercise 2_2"<<endl;
    cout<<"addNumber(1,2,3,4) =  " << addNumber(1,2,3,4) << endl;
    cout<<"addNumber(1,2,3) =  " <<addNumber(1,2,3)<< endl;
    cout<<"addNumber(1,2) =  " <<addNumber(1,2)<< endl;
    cout<<"addNumber(1) =  " <<addNumber(1)<< endl;
    cout<<"addNumber() =  " <<addNumber()<< endl;

}


void ex2_3(){

    cout<<endl<<"Exercise 2_3"<<endl;
    int intNumber =42;
    double doubleNumber=1.3;
    float floatNumber=1.456;
    string stringNumber= "exercises";
    cout<<" variable intNumber is ";
    printType(intNumber);
    cout<<endl<<" variable doubleNumber is";
    printType(doubleNumber);
    cout<<endl<<" variable floatNumber is";
    printType(floatNumber);
    cout<<endl<<" variable stringNumber is";
    printType(stringNumber);
    cout<<endl;
    cout<<endl<<" We could set the parameter of the funtion printType as const  ";
    cout<<"In this case const int, const double, const float and const string "<<endl;
}

void ex2_1_1(){

    cout<<endl<<"Exercise 2_1_1"<<endl;
    int n1=0;
    int n2=0;
    if(getUserInput(n1,n2)){
        cout<< "The sum is "<<add(n1,n2)<<endl;
    }
}

void ex2_1_2(){

    cout<<endl<<"Exercise 2_1_2"<<endl;
    int n1=0;
    int n2=0;
    int sum=0;
    if(getUserInput(n1,n2)){
        add(n1,n2,sum);
        cout<< "The sum is "<<sum<< endl;
    }
}

void ex2_1_3(){

    cout<<endl<<"Exercise 2_1_3"<<endl;
    cout<<"The operation works only in the copy of num (in the function context).";
    cout<<"It happens because the argument num is being copied."<<endl;
    cout<<" An solution could be change the argument by &num (address of variable num)."<<endl;

}

bool getUserInput(int &n1,int &n2){
    bool ack=false;
    string digitsInString;
    digitsInString.clear();
    char stringSpliter[15]=" ";
    cout<< "Enter two number ";
    try
    {
        getline(cin, digitsInString);//digitsInString.find(' ',0)
        digitsInString.append("\n");
        digitsInString.copy(stringSpliter,digitsInString.find(' ',0),0);
        n1=stoi(stringSpliter);
        digitsInString.copy(stringSpliter,digitsInString.find('\n',0),digitsInString.find(' ',0));
        n2=stoi(stringSpliter);
        ack=true;
    }
    catch (...){
        cout<<endl<<" Inputs are not valid "<<endl;
        n1=0;
        n2=0;
        ack=false;
    }
    return ack;
}
