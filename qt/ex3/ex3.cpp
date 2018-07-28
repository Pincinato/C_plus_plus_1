#include "ex3.h"


int sumIndexAcess(const int *const vector,const int &size){

    int sum =0;
    for(int i=0;i<size;++i){
        sum=sum+vector[i];
    }
    return sum;
}

int sumPointerArithmetic(const int *const vector,const int &size){

    int sum =0;
    for(int i=0;i<size;++i){
        sum=sum+ *(vector+i);
    }
    return sum;
}


int minIndexAcess(const int *const vector,const int &size){

    int min =INT_MAX;
    for(int i=0;i<size;++i){
        if(vector[i]<min)
            min=vector[i];
    }
    return min;
}

int minPointerArithmetic(const int *const vector,const int &size){

    int min = INT_MAX;
    for(int i=0;i<size;++i){
        if(*(vector+i)<min)
             min=*(vector+i);
    }
    return min;
}


int maxIndexAcess(const int *const vector,const int &size){

    int max = INT_MIN;
    for(int i=0;i<size;++i){
        if(vector[i]>max)
            max=vector[i];
    }
    return max;

}


int maxPointerArithmetic(const int *const vector,const int &size){

    int max = INT_MIN;
    for(int i=0;i<size;++i){
        if(*(vector+i)>max)
        max= *(vector+i);
    }
    return max;
}

int sumSmartPtr(const unique_ptr <int []> &SmartPtr,const int &size){

    int sum =0;
    for(int i=0;i<size;++i){
        sum=sum+SmartPtr[i];
    }
    return sum;
}
int minSmartPtr(const unique_ptr < int []> &SmartPtr,const int &size){

    int min =INT_MAX;
    for(int i=0;i<size;++i){
        if(SmartPtr[i]<min)
            min=SmartPtr[i];
    }
    return min;
}
int maxSmartPtr(const unique_ptr < int []> &SmartPtr,const int &size){

    int max = INT_MIN;
    for(int i=0;i<size;++i){
        if(SmartPtr[i]>max)
            max=SmartPtr[i];
    }
    return max;
}

int sumStlVector(const vector < int > &StlVector){

    return accumulate(StlVector.begin(), StlVector.end(), 0);
}
int minStlVector(const vector < int > &StlVector){

  return *min_element(StlVector.begin(),StlVector.end());
}
    int maxStlVector(const vector < int > &StlVector){
    return *max_element(StlVector.begin(),StlVector.end());
}

void printFinalResult(const string &text,const int &sum, const int &min, const int &max){

    cout<<"----------"<<endl;
    cout<<endl<<"Results of "<<text<<" :"<<endl;
    cout<<"Sum: "<<sum<<endl;
    cout<<"Min: "<<min<<endl;
    cout<<"Max: "<<max<<endl;
}

bool getUserInput(int &number){
    bool ACK = false;
    bool ack=false;
    string digitsInString;
    digitsInString.clear();
    try
    {
        getline(cin, digitsInString);//digitsInString.find(' ',0)
        digitsInString.append("\n");
        number=stoi(digitsInString);
        ack=true;
    }
    catch (...){
        cout<<endl<<" Inputs are invalid "<<endl;
        number=0;
        ack=false;
    }
    return ack;
}

