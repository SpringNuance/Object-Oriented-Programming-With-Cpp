#include "book.hpp"

#include <ctime>
#include <iostream>
#include <string>

    /* Book:
    * the constructor of the Book class, takes the following parameters:
    *  - the book's name (reference to const string), 
    *  - the book's author (reference to const string), 
    *  - the book's ISBN number (reference to const string) 
    *  - the status of the book, loaned or not (bool), which is by default false
    *  - due date as a Date structure (Date), which is by default 0-0-0
    */ 

    Book::Book(const std::string& name, const std::string& author, const std::string& isbn){
        name_ = name;
        author_ = author;
        isbn_ = isbn;
        loaned_ = false;
        due_date_.day = 0;
        due_date_.month = 0;
        due_date_.year = 0;
    }

    Book::Book(const std::string& name, const std::string& author, const std::string& isbn, bool loaned, Date due_date){
        name_ = name;
        author_ = author;
        isbn_ = isbn;
        loaned_ = loaned;
        due_date_ = due_date;
    }

    /* GetName:
    * returns the Book's name as a string, takes no parameters.
    * This function should not alter the Book object's state, in other words the function should be const.
    */

   std::string Book::GetName() const {
     return name_;
   }
    

    /* GetAuthor:
    * returns the Book's author as a string, takes no parameters. 
    * This function should not alter the Book object's state, in other words the function should be const.
    */

   std::string  Book::GetAuthor() const {
     return author_;
   }
    

    /* GetISBN:
    * returns the Book's ISBN as a string, takes no parameters.
    * This function should not alter the Book object's state, in other words the function should be const.
    */
    
    std::string Book::GetISBN() const {
     return isbn_;
   }

    /* GetStatus:
    * returns the Book's status as a bool, takes no parameters.
    * This function should not alter the Book object's state, in other words the function should be const.
    */

    bool Book::GetStatus() const {
     return loaned_;
   }
    

    /* GetDueDate:
    * returns the Book's due date, takes no parameters.
    * This function should not alter the Book object's state, in other words the function should be const.
    */

    Date Book::GetDueDate() const {
     return due_date_;
   }
    

    /* Loan:
    * sets the due date to current date + 1 month, e.g. loaned on 1.9. => due date 1.10.
    * sets the status to true
    * returns true if loaning was succesful and false if it was not
    * Hint: there is a function Today in the Date struct that returns the current date
    */

   bool Book::Loan() {
       if (loaned_) return false;
    else {
        due_date_ = Date::Today();
        if (due_date_.month == 12){
            due_date_.month = 1;
        } else {
            due_date_.month += 1;
        }
        loaned_ = true;
        return true;
    }
   }

    /* Restore:
    * sets the due date to 0-0-0
    * sets the status to false
    * returns nothing
    */

   void  Book::Restore() {
       due_date_.day = 0;
       due_date_.month = 0;
       due_date_.year = 0;
       loaned_ = false;
   }
    
    /* Print:
    * prints the book's information to the standard output stream.
    * The function takes no parameters and returns nothing. 
    * The output format should be like the following:
Book: <name>, author: <author>, ISBN: <isbn>, loaned <true/false>, due date: <day>.<month>.<year>\n
    * This function should not alter the Book object's state, in other words the function should be const.
    */

   void Book::Print() const {
       if (loaned_){
            std::cout << "Book: " << name_<< ", author: "<< author_<<", ISBN: " << isbn_ << ", loaned true, due date: "<< due_date_.day <<"."<< due_date_.month <<"."<< due_date_.year <<"" << std::endl; 
       } else {
            std::cout << "Book: " << name_<< ", author: "<< author_<<", ISBN: " << isbn_ << ", loaned false, due date: "<< due_date_.day <<"."<< due_date_.month <<"."<< due_date_.year <<"" << std::endl; 
       }

   }
    


