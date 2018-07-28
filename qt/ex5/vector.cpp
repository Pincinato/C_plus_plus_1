#include "vector.h"
#include <climits>

vector::vector()
{
    this->m_size=0;
    this->m_data=nullptr;
}
vector::~vector(){

    if (this->m_data!=nullptr){
        this->clear();
    }
}

vector::vector(const int &size){
    try{
       this->m_data= new int [size];
       this->setSize(size);
       this->setInitialValueOfVector(0);
    }
    catch(...){
        cout <<"Impossible to call the constructor with this paramenter size: "<<size<<endl;
    }

}
vector::vector(const int &size,const int &initialValue){
    try{
        this->m_data= new int [size];
        this->setSize(size);
        this->setInitialValueOfVector(initialValue);
    }
    catch(...){
        cout <<"Impossible to call the constructor with those parametes; sze: "<<size<<endl<<"Initial value:"<<initialValue<<endl;
    }

}

vector::vector(const vector &copySource){

    try{
        this->m_data=nullptr;
        if(copySource.m_data!=nullptr){
            m_data= new int [copySource.m_size];
            this->setSize(copySource.m_size);
            copyData(m_data,copySource.m_data,m_size);//Correction made here, now deep copy.
        }
    }
    catch(...){
        cout <<"Impossible to call copy constructor"<<endl;
    }

} // copy constructor

vector::vector (vector &&moveSource){
    if(moveSource.m_data!=nullptr){
        try{
            this->m_data=moveSource.m_data;            
            this->setSize(moveSource.size());
            moveSource.m_data=nullptr;
            moveSource.setSize(0);
        }
        catch(...){
        cout <<"Impossible to call &moveSource contructor"<<endl;
        }
    }
    else cout<<"source has no allocated memory"<<endl;
}  //move constructor using Rvalue

const int vector::size() {
    return m_size;
}

const int vector::at(int index){
    int ACK=INT_MIN;
    if ((index < this->size()) && (index > -1) ){
        try{
           ACK=this->m_data[index];
        }
        catch(...){
            cout <<"Impossible to use method at with index "<<index<<endl;
        }
    }
    else{
        cout <<"Warning: out-of-range access is not possible"<<endl;
    }
    return ACK;
}

bool vector::push_back(const int &element){
    bool ACK=false;
    try{
        int * newSmartPtr = new int [this->size()+1];
        if(this->copyData(newSmartPtr,m_data,this->size())){
            newSmartPtr[this->size()]=element;
            this->setSize(this->size()+1);
            delete [] m_data;
            this->m_data = new int [this->size()];
            ACK=this->copyData(m_data,newSmartPtr,this->size());
        }
        delete [] newSmartPtr;
    }
    catch(...){
        cout <<"Impossible to push back"<<endl;
    }
    return ACK;
}

bool vector::pop_back(){
    bool ACK=false;
    if (this->size() >0){
        try{
            int * newPtr = new int [this->size()-1];
            if(this->copyData(newPtr,m_data,this->size()-1)){
                this->setSize(this->size()-1);
                delete [] m_data;
                this->m_data = new int [this->size()];
                ACK=this->copyData(m_data,newPtr,this->size());
            }
            delete [] newPtr;
        }
        catch(...){
        cout <<"Impossible to pop back"<<endl;
        }
    }
    else{
        cout<<"Impossible to pop back, not enough elements"<<endl;
    }
    return ACK;
}

bool vector::clear(){
    bool ACK=false;
    if (this->m_data!=nullptr){
        try{
            delete[] this->m_data;
            m_data=nullptr;
            this->setSize(0);
            ACK=true;
        }
        catch(...){
            cout <<"Impossible to clear vector"<<endl;
        }
    }
    return ACK;
}

bool vector::operator =(const vector &dataToReceive){

    bool ACK=false;
    if (this->size()>=dataToReceive.m_size){
        try{
            for (int i=0;i<this->size();i++){
                this->m_data[i]=dataToReceive.m_data[i];
            }
            ACK=true;
        }
        catch(...){
            cout <<"Impossible to realize the operator = "<<endl;
        }
    }
    else cout<<"Vector must have the same size"<<endl;
    return ACK;

}

void vector::setSize(const int &newSize){

    this->m_size=newSize;
}

bool vector::setInitialValueOfVector(const int &value){
    bool ACK=false;
    try{
        for (int i=0;i<this->size();i++){
            this->m_data[i]= value;
        }
        ACK=true;
    }
    catch(...){
        cout<<"Impossible to set initial values of the vector"<<endl;
    }
    return ACK;
}

bool vector::copyData(int *vectorToReceive, const int *vectorSource, const int &quantityOfDataToCopy){

    bool ACK=false;
    try{
        for(int i=0;i<quantityOfDataToCopy;++i){
            vectorToReceive[i]=vectorSource[i];
        }
        ACK=true;
    }
    catch(...){
       cout<<"Impossible to copy Data "<<endl;
    }
    return ACK;
}
