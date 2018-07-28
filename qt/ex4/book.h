#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Book
{
private:
     string title;
     string author;
     string ISBNnumber;
     bool isValid=false;
     /**
      * @brief checkStringExistence
      * @param toBeTested
      * @return true if the string exist
      */
     bool checkStringExistence(const string &toBeTested);
     /**
      * @brief checkISBNnumber
      * @param isbn
      * @return  true if  ISBN is a valid number
      */
     bool checkISBNnumber(string isbn);     
     /**
      * @brief printOutInformation
      */
     void printOutInformation();

public:
    Book(string title,string author, string ISBNnumber);
    //~Book();

    /**
     * @brief getIsValid
     * @return isValid
     */
    const bool getIsValid();

    /**
     * @brief getTitle
     * @return Title
     */
    const string getTitle();

    /**
     * @brief getAuthor
     * @return author
     */
    const string getAuthor();

    /**
     * @brief getISBNnumber
     * @return ISBNnumber
     */
    const string getISBNnumber();

    /**
     * @brief operator ==
     * @param bookToCompare
     * @return true if books have the same attribute values
     */
    bool operator ==(Book bookToCompare);
};

#endif // BOOK_H
