#include "account.h"

account::account(double balance)
{
    this->balance=balance;
}

bool account::debit(double value){
    bool ACK= false;
     if(getBalance()>=value){
        setBalance(getBalance()-value);
        ACK=true;
    }
    else
        cout<<"value should be smaller than balance"<<endl;
    return ACK;
}
bool account::credit(double value){
    bool ACK= false;
    if (value >0){
        setBalance(getBalance()+value);
        ACK=true;
    }
    else
        cout<<"Value should be bigger than 0"<<endl;
    return ACK;
}
const double account::getBalance(){
    return balance;
}

void account::setBalance(const double &newBalance){
    balance=newBalance;
}
