#ifndef MONTECARLO_H
#define MONTECARLO_H
#include <iostream>
#include <random>
#include <cmath>
#include <vector>
#include <cstdint>
#include <iomanip>

using namespace std;

/**
 * @brief simulateThrows
 * @param numberDarts
 * @param positionDartsX
 * @param positionDartsY
 * @param dartInCicle
 * @return
 */
bool simulateThrows(const long int &numberDarts, vector<double> &positionDartsX,vector<double> &positionDartsY,long int &dartsInCicle);

/**
 * @brief checkInsideCircle
 * @param coordinateX
 * @param coordinateY
 * @param radius
 * @return
 */
 uint8_t checkInsideCircle(const double &coordinateX,const double &coordinateY,const double &radius = 1.0 );

 /**
  * @brief piCalculation
  * @param numberDarts
  * @param dartsInCicle
  * @return
  */
 float piCalculation(const long int &numberDarts,const int long &dartsInCicle);

#endif // MONTECARLO_H
