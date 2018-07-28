#ifndef FIBONACCI_H
#define FIBONACCI_H

#define GOLDEN_RATIO_NUMBER ((1+sqrt(5))/2)

#include <cmath>
#include <iomanip>
#include <sstream>

int fibonacci(int f, int fprev);
bool golden_radio(int f, int fprev,double &ratio, double &variation);
#endif // FIBONACCI_H
