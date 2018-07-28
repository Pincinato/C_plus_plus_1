#include "montecarlo.h"


bool simulateThrows(const long int &numberDarts ,vector<double> &positionDartsX,vector<double> &positionDartsY,long int &dartsInCicle){

    bool ack=false;
    random_device rd; // Create Random Device as seed
    mt19937 mt(rd ()); // Init Mersenne Twister Engine with that seed
    uniform_real_distribution < double > dist (0.0 , 1.0) ;
    dartsInCicle=0;
    try
    {
        for ( long int i =0; i <numberDarts; ++i)
        {
            positionDartsX.push_back(dist (mt)); //X
            positionDartsY.push_back(dist (mt)); //y
            if(checkInsideCircle(positionDartsX[i],positionDartsY[i])== uint8_t(1)){
                ++dartsInCicle;
            }
        }
        ack=true;
     }
    catch(...){
        cout<<"In the function simulateThrows"<<endl;
        cout<<"Argument n is not compatible with length of vector postionDarts"<<endl;
        ack=false;
    }
    return ack;
}

uint8_t checkInsideCircle(const double &coordinateX,const double &coordinateY,const double &radius){

    uint8_t ACK= uint8_t(0);
    try
    {
        double distace=sqrt((coordinateX*coordinateX)+(coordinateY*coordinateY)); // Calculation of Euclidean distance from the center to the Dart
        if(distace<=radius){
            ACK=1;
        }
        else{
            ACK=127;
        }
    }
    catch(...){
        cout<<"In the function checkInsideCircle"<<endl;
        cout<< "Invalid aguments "<<endl;
        ACK=0;
    }
    return ACK;
}

float piCalculation(const long int &numberDarts,const long int &dartsInCicle){

    return 4.0*(float(dartsInCicle)/float(numberDarts));
}
