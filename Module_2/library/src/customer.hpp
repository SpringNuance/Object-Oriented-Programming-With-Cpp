#ifndef ELEC_AS_CPP_CUSTOMER
#define ELEC_AS_CPP_CUSTOMER

#include <string>
#include <vector>
#include "book.hpp"

class Customer {
public:
    /* Customer:
    * the constructor of the Customer class, takes the following parameters:
    * - the customer's name (reference to const string), 
    * - the customer number (reference to const string).
    */ 
    Customer(const std::string& name, const std::string& id);
    Customer(const std::string& name, const std::string& id, std::vector<Book>& loaned_books);

    /* GetName:
    * returns the Customer's name as a string, takes no parameters.
    * This function should not alter the Customer object's state, in other words the function should be const.
    */
    
    std::string GetName() const;

    /* GetID:
    * returns the Customer's customer number as a string, takes no parameters. 
    * This function should not alter the Customer object's state, in other words the function should be const.
    */
    std::string GetID() const;
    
    /* GetLoanAmount:
    * returns the Customer's number of loans as an int, takes no parameters.
    * This function should not alter the Customer object's state, in other words the function should be const.
    */
   int GetLoanAmount() const;
    
    /* GetLoans:
    * returns the Customer's loans as a vector<Book>, takes no parameters.
    * This function should not alter the Customer object's state, in other words the function should be const.
    */
   std::vector<Book> GetLoans() const;
    
    
    /* LoanBook:
    * loans a book for the customer
    * takes a reference to a book as a parameter and returns the result of loaning (from Book loan-function).
    */
   bool LoanBook(Book& book);
    
    
    /* ReturnBook:
    * returns a book from the customer
    * takes a reference to a book as a parameter and returns nothing.
    */
   void ReturnBook(Book& book);
    
    
    /* Print:
    * prints the customer's information to the standard output stream.
    * The function takes no parameters and returns nothing. 
    * The output format should be like the following (for 2 loans):
  Customer: <name>, <customer_id>, has <number_of_loans> books on loan:\n
- Book: <name>, author: <author>, ISBN: <isbn>, loaned <true/false>, due date: <day>.<month>.<year>\n
- Book: <name>, author: <author>, ISBN: <isbn>, loaned <true/false>, due date: <day>.<month>.<year>\n
    * This function should not alter the Customer object's state, in other words the function should be const.
    */
    void Print() const ;

private:
    /* Make variables for:
    * name (string)
    * customer id (string)
    * vector of loaned books (vector<Book>)
    */
    std::string name_;
    std::string id_;
    std::vector<Book> loaned_books_;

};

#endif
