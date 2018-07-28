#include "book.h"

Book::Book(string title,string author, string ISBNnumber):title(title),author(author),ISBNnumber(ISBNnumber)
{

    isValid = checkStringExistence(this->title) && checkStringExistence(this->author) && checkISBNnumber(this->ISBNnumber);

}

bool Book::checkStringExistence(const string &toBeTested){

    bool ACK=true;
    if(!toBeTested.compare(""))
        ACK=false;
    return ACK;

}

bool Book::checkISBNnumber(string isbn){

    bool ACK=false;
    isbn.erase(remove(isbn.begin(), isbn.end(),'-'),isbn.end()); //Removing '-'
    isbn.erase(remove(isbn.begin(), isbn.end(),' '),isbn.end()); //Removing ' '
    int sum=0;
    int a=0;
    int i=0;
    if(isbn.size()==10){
        for(i=0;i<isbn.size()-1;++i){
            a =stoi(isbn.substr(i,1));
            sum =sum+a*(i+1);
        }
        if((sum%11 -stoi(isbn.substr(i,1)))==0)
            ACK=true;
    }
    return ACK;
}

const bool Book::getIsValid(){
    return isValid;
}

void Book::printOutInformation(){

    cout<<"Book information"<<endl;
    cout<<"title: "<<title<<endl<<"author: "<<author<<endl<<"ISBN: "<<ISBNnumber<<endl<<"validy state: "<<isValid<<endl<<endl;
}

const string Book::getTitle(){
    return title;
}
const string Book::getAuthor(){
    return author;
}
const string Book::getISBNnumber(){
    return ISBNnumber;
}

bool Book::operator ==(Book bookToCompare){

    if(!(this->getAuthor().compare(bookToCompare.getAuthor())) && !(this->getTitle().compare(bookToCompare.getTitle())) && !(this->getISBNnumber().compare(bookToCompare.getISBNnumber())))
        return true;
    else
        return false;

}
