#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
#include <iostream>
using namespace std;

class vector
{
public:
    vector();
    ~vector();
    vector(const int &size);
    vector(const int &size,const int &initialValue);

    /**
     * @brief vector
     * @param copySource
     */
    vector(const vector &copySource); // copy constructor

    /**
     * @brief vector
     * @param moveSource
     */
    vector (vector &&moveSource); //move constructor using Rvalue

    /**
     * @brief size
     * @return size
     */
    const int size();

    /**
     * @brief at
     * @param index
     * @return value in the index position of the m_data
     */
    const int at(int index);

    /**
     * @brief push_back
     * @param element
     * @return true if it works
     */
    bool push_back(const int &element);

    /**
     * @brief pop_back
     * @return true if it works
     */
    bool pop_back();

    /**
     * @brief clear
     * @return true if it works
     */
    bool clear();

    /**
     * @brief operator =
     * @param dataToReceive
     * @return true if it works
     */
    bool operator =(const vector &dataSource);

private:
    int* m_data=nullptr;
    int m_size;

    /**
     * @brief setSize
     * @param newSize
     */
    void setSize(const int &newSize);

    /**
     * @brief setInitialValueOfVector
     * @param value
     * @return true if it works
     */
    bool setInitialValueOfVector(const int &value);

    /**
     * @brief copyData
     * @param vectorToReceive
     * @param vectorSource
     * @param quantityOfDataToCopy
     * @return true if it works
     */
    bool copyData(int * vectorToReceive,const int * const  vectorSource, const int &quantityOfDataToCopy);

};

#endif // VECTOR_H
