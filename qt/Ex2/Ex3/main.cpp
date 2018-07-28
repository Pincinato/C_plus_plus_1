#include "montecarlo.h"

void ex3();

int main()
{
    ex3();
    return 0;
}

void ex3(){

    const long int numberDarts=5000000;
    long int dartsInCicle=0;
    vector<double> positionsX;
    positionsX.clear();
    vector<double> positionsY;
    positionsY.clear();
    if(simulateThrows(numberDarts,positionsX,positionsY,dartsInCicle)){
        cout<<" pi = ";
        cout<< fixed<<setprecision(25)<<piCalculation(numberDarts,dartsInCicle) <<endl;
    }

}
