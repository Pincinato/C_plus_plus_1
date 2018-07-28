#include "fibonacci.h"

int fibonacci(int f, int fprev){

    return (f+fprev);

}

bool golden_radio(int f, int fprev, double &ratio, double &variation ){

    bool ACK=true;
    if(fprev == 0 )
        ACK=false;
    else{
        ratio=(double) f/fprev;
        variation=((GOLDEN_RATIO_NUMBER-ratio)/GOLDEN_RATIO_NUMBER)*100;
    }
    return (ACK);
}
