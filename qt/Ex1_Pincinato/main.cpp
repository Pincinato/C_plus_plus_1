#include <iostream>
#include <limits>
#include "fibonacci.h"

//using namespace std;

#define GOLDEN_RATIO_OPTION 1

int main()
{
  int max_value =int(std::numeric_limits<int>::max()); // same as INT_MAX;
  std:: cout<< "Max representation using int: " << max_value<< std::endl;
  int f = 1; int fprev = 0;
  std :: cout << std::endl<< fprev << " ";
  std::string result_golden_radio;
  std::stringstream info;
  result_golden_radio.clear();
  do {
    std :: cout << f << " " ;//<< std :: endl ;
    int tmp = fibonacci (f, fprev );
    fprev = f;
      f = tmp ;
      //Golden Ratio part
      if(GOLDEN_RATIO_OPTION && f>0){
        double ratio=0.0;
        double variation=0.0;        ;
          if(golden_radio(f,fprev,ratio,variation)){
            info<<"Ratio: "<<std::fixed<<std::setprecision(17)<<ratio;
            info<<" -Dev[%]: "<<std::fixed<<std::setprecision(17)<<variation<<std::endl;
            }
          else{
            std::cout<<"Error in golden_radio function"<< std::endl;
            }
      }
     // End of Golden Ratio part
    } while (f>0); // if f became bigger than max_value, it becomes negative (overflow effect).
  std::cout<<std::endl<<"What could you do to compute larger Fibonacci numbers?"<< std::endl << "We could use (un)signed long long int, with 64 bits for representation or just long (32 bits) "<<std::endl;
  if(GOLDEN_RATIO_OPTION){
    std::cout<<std::endl<< info.str() <<std::endl;
  }
  return 0;
 }

