#include "library.h"

Library::Library()
{
     bookList.clear();
}

bool Library::addBook(const Book &newbook){
    bool ACK =false;
    try{
        bookList.push_back(newbook);
        ACK = true;
    }
    catch(...){
        cout<<"Impossible to add new book"<<endl;
        ACK = false;
    }
    return ACK;
}
bool Library::cleanup(){
    bool ACK =false;
    vector <Book> newBookList;
    newBookList.clear();
    newBookList=bookList;
    try{
        for(int i=0;i<newBookList.size();++i){
            if(!newBookList.at(i).getIsValid())
                this->deleteBook(newBookList.at(i));
        }
        ACK = true;
    }
    catch(...){
        cout<<"Impossible to cleanup library"<<endl;
        ACK = false;
    }
    return ACK;

}
void Library::printInventary(){
    cout<<"Printing Inventary"<<endl<<endl;
    int validBook=0;
    for(int i =0;i<bookList.size();++i){
        cout<<"Book information"<<endl;
        cout<<"title: "<<bookList.at(i).getTitle()<<endl<<"author: "<<bookList.at(i).getAuthor()<<endl<<"ISBN: "<<bookList.at(i).getISBNnumber()<<endl<<"validy state: "<<bookList.at(i).getIsValid()<<endl<<endl;
        if(bookList.at(i).getIsValid())
            validBook=validBook+1;
    }
    cout<<"Total number of books: "<<bookList.size()<<endl;
    cout<<"Number valid books: "<<validBook<<endl;
    cout<<"Number of invalid books: "<<bookList.size()-validBook<<endl;
}

bool Library::deleteBook(const Book &bookToRemove){
    bool ACK =false;
    try{
        for(int i=0;i<bookList.size();++i){
            if(bookList.at(i)==bookToRemove)
                bookList.erase(bookList.begin()+i);
        }
        ACK = true;
    }
    catch(...){
        cout<<"Impossible to delete book"<<endl;
        ACK = false;
    }
    return ACK;
}
