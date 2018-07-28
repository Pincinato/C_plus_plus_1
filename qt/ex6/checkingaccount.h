#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "account.h"

class checkingaccount:public account
{
public:
    checkingaccount(double intialBalance,double  fee);
    bool debit(double value);
    void printBalance();
protected:
    const double getFee();
    bool setFee (const double &newFee);
private:
    double fee;
};

#endif // CHECKINGACCOUNT_H
