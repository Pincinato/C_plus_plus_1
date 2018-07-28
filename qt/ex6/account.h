#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
using namespace std;

class account
{
public:
    account(double initialBalance=0);
    bool debit(double value);
    bool credit(double value);
protected:
    const double getBalance();
    void setBalance(const double &newBalance);
private:
    double balance=0;
};

#endif // ACCOUNT_H
