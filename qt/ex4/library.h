#ifndef LIBRARY_H
#define LIBRARY_H
#include "book.h"
#include <vector>

class Library
{
private:
    vector <Book> bookList;
    /**
     * @brief deleteBook
     * @param bookToRemove
     * @return true if book was successfully deleted
     */
    bool deleteBook(const Book &bookToRemove);
public:
    Library();
    /**
     * @brief addBook
     * @param newbook
     * @return true if book was successfully added
     */
    bool addBook(const Book &newbook);

    /**
     * @brief cleanup
     * @return true if library was successfully cleanup
     */
    bool cleanup();

    /**
     * @brief printInventary
     */
    void printInventary();
    ~Library(){}

};

#endif // LIBRARY_H
