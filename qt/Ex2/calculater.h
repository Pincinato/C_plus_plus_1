#ifndef CALCULATER_H
#define CALCULATER_H

#include <string>
#include <sstream>
#include <iostream>
using namespace std;


/**
 * @brief add
 * @param n1
 * @param n2
 * @return
 */
int add(const int &n1, const int &n2);

/**
 * @brief add
 * @param n1
 * @param n2
 * @param sum
 */
void add(const int &n1,const int &n2,int &sum);

/**
 * @brief addNumber
 * @param n1
 * @param n2
 * @param n3
 * @param n4
 * @param n5
 * @return
 */
int addNumber(const int &n1=0,const int &n2=0,const int &n3=0,const int &n4=0,const int &n5=0);

/**
 * @brief printType
 * @param intNumber
 */
void printType(const int intNumber);
/**
 * @brief printType
 * @param floatNumber
 */
void printType(const float floatNumber);

/**
 * @brief printType
 * @param doubleNumber
 */
void printType(const double doubleNumber);

/**
 * @brief printType
 * @param stringNumber
 */
void printType(const string stringNumber);
#endif // CALCULATER_H
