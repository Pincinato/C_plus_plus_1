#include "checkingaccount.h"

checkingaccount::checkingaccount(double initialBalance,double fee):account(initialBalance)
{
 this->fee=fee;

}

bool checkingaccount::debit(double value){
    bool ACK= false;
    if (getBalance()>= (value + this->getFee())){
       setBalance(getBalance()- value - this->getFee());
        ACK=true;
    }
    else
        cout<<"value should be smaller or equal than "<<getBalance()- this->getFee()<<" (Balance +fee)"<<endl;
    return ACK;
}

void checkingaccount::printBalance(){
    cout<<"Balance: "<<getBalance()<<endl;
}

const double checkingaccount::getFee(){
    return fee;
}
