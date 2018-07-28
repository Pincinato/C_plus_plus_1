#ifndef EX3_H
#define EX3_H

#include <string>
#include <vector>
#include <climits>
#include <memory>
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * @brief sumIndexAcess
 * @param vector
 * @param size
 * @return
 */
int sumIndexAcess(const int *const vector,const int &size);

/**
 * @brief sumPointerArithmetic
 * @param vector
 * @param size
 * @return
 */
int sumPointerArithmetic(const int *const vector,const int &size);

/**
 * @brief minIndexAcess
 * @param vector
 * @param size
 * @return
 */
int minIndexAcess(const int *const vector,const int &size);

/**
 * @brief minPointerArithmetic
 * @param vector
 * @param size
 * @return
 */
int minPointerArithmetic(const int *const vector,const int &size);

/**
 * @brief maxIndexAcess
 * @param vector
 * @param size
 * @return
 */
int maxIndexAcess(const int *const vector,const int &size);

/**
 * @brief maxPointerArithmetic
 * @param vector
 * @param size
 * @return
 */
int maxPointerArithmetic(const int *const vector,const int &size);

/**
 * @brief sumSmartPtr
 * @param SmartPtr
 * @param size
 * @return
 */
int sumSmartPtr(const unique_ptr < int []>&SmartPtr,const int &size);

/**
 * @brief minSmartPtr
 * @param SmartPtr
 * @param size
 * @return
 */
int minSmartPtr(const unique_ptr < int []>&SmartPtr,const int &size);

/**
 * @brief maxSmartPtr
 * @param SmartPtr
 * @param size
 * @return
 */
int maxSmartPtr(const unique_ptr < int []>&SmartPtr,const int &size);

/**
 * @brief sumStlVector
 * @param StlVector
 * @return
 */
int sumStlVector(const vector < int > &StlVector);

/**
 * @brief minStlVector
 * @param StlVector
 * @return
 */
int minStlVector(const vector < int > &StlVector);

/**
 * @brief maxStlVector
 * @param StlVector
 * @return
 */
int maxStlVector(const vector < int > &StlVector);

/**
 * @brief getUserInput
 * @param number
 * @return
 */
bool getUserInput(int &number);

/**
 * @brief printFinalResult
 * @param text
 * @param sum
 * @param min
 * @param max
 */
void printFinalResult(const string &text,const int &sum, const int &min, const int &max);


#endif // EX3_H
