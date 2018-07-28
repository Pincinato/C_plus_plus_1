#include "vector.h"
#include <climits>

vector::vector()
{
    this->m_size=0;
    this->m_data=nullptr;
}
vector::~vector(){
        this->clear();
}

vector::vector(const int &size){
    try{
       this->m_data= new int [size];
        this->m_size=size;
       this->setInitialValueOfVector(0);
    }
    catch(...){
        cout <<"Impossible to call the constructor with this paramenter size: "<<size<<endl;
    }

}
vector::vector(const int &size,const int &initialValue){
    try{
        this->m_data= new int [size];
        this->m_size=size;
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
             this->m_size=copySource.m_size;
            copyData(m_data,copySource.m_data,m_size);
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
            this->m_size=moveSource.size();
            moveSource.m_data=nullptr;
            moveSource.m_size=0;
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
            this->m_size=size()+1;
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
               this->m_size=size()-1;
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
            this->m_size=0;
            ACK=true;
        }
        catch(...){
            cout <<"Impossible to clear vector"<<endl;
        }
    }
    return ACK;
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



vector::operator  const char * (){
    ostringstream temp;
    if(this->m_data!=nullptr && (this->m_size>4))
    {
        for(int i=0;i<5;i++){
            temp << m_data[i];
            temp <<" ";
        }
    }
    m_dataOutput=temp.str();
    return m_dataOutput.c_str();
}

vector vector::operator +(const vector &dataSource){

    if((this->m_data!=nullptr) && (dataSource.m_data!=nullptr) && (dataSource.m_size==this->m_size)){
        for(int i=0;i<m_size;i++){
           this->m_data[i]=this->m_data[i]+dataSource.m_data[i];
        }
   }
    return *this;
}

vector vector::operator *(const vector &dataSource){

    if((this->m_data!=nullptr) && (dataSource.m_data!=nullptr) && (dataSource.m_size==this->m_size)){
        for(int i=0;i<m_size;i++){
           this->m_data[i]=this->m_data[i]*dataSource.m_data[i];
        }
   }
    else cout<<" ";
    return *this;
}


vector& vector::operator = (const vector &dataSource){ //Copy assignment

    if((dataSource.m_data!= nullptr) && (*this != dataSource)){
        this->clear();
        this->m_data=new int [dataSource.m_size];
        this->m_size=dataSource.m_size;
        copyData(m_data,dataSource.m_data,this->m_size);
    }
    else cout<<" "<<endl;
    return *this;
}

vector& vector::operator = ( vector &&dataSource){


    if((dataSource.m_data!= nullptr) && (*this != dataSource)){
        this->clear();
        this->m_data=dataSource.m_data;
        this->m_size=dataSource.m_size;
        dataSource.m_data=nullptr;
        dataSource.m_size=0;
    }
    else cout<<" "<<endl;
    return *this;
}

bool vector::operator ==(const vector &dataSource){

    bool ACK=true;
    if((this->m_size==dataSource.m_size) && (this->m_data!=nullptr) && (dataSource.m_data!=nullptr)){
        for(int i=0;i<this->m_size;++i){
            if( this->m_data[i] != dataSource.m_data[i]){
                ACK= false;
                break;
            }
        }
    }
   else ACK=false;
   return ACK;
}

bool vector::operator !=(const vector &dataSource){

      return !(this->operator ==(dataSource));
}
