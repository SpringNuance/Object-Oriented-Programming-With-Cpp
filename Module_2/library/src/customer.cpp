#include "customer.hpp"
#include "book.hpp"

#include <iostream>
#include <string>

    /* Customer:
    * the constructor of the Customer class, takes the following parameters:
    * - the customer's name (reference to const string), 
    * - the customer number (reference to const string).
    */ 
    Customer::Customer(const std::string& name, const std::string& id){
        name_ = name;
        id_ = id;
    };

    Customer::Customer(const std::string& name, const std::string& id, std::vector<Book>& loaned_books){
        name_ = name;
        id_ = id;
        loaned_books_ = loaned_books;
    };

    /* GetName:
    * returns the Customer's name as a string, takes no parameters.
    * This function should not alter the Customer object's state, in other words the function should be const.
    */
    
    std::string Customer::GetName() const {
        return name_;
    };

    /* GetID:
    * returns the Customer's customer number as a string, takes no parameters. 
    * This function should not alter the Customer object's state, in other words the function should be const.
    */
   std::string Customer::GetID() const {
      return id_;
   };
    
    /* GetLoanAmount:
    * returns the Customer's number of loans as an int, takes no parameters.
    * This function should not alter the Customer object's state, in other words the function should be const.
    */
   int Customer::GetLoanAmount() const {
      return loaned_books_.size();
   };
    
    /* GetLoans:
    * returns the Customer's loans as a vector<Book>, takes no parameters.
    * This function should not alter the Customer object's state, in other words the function should be const.
    */
   std::vector<Book> Customer::GetLoans() const {
      return loaned_books_;
   };
    
    
    /* LoanBook:
    * loans a book for the customer
    * takes a reference to a book as a parameter and returns the result of loaning (from Book loan-function).
    */
   bool Customer::LoanBook(Book& book) {
      bool loaned = book.Loan();
      if (loaned){
          loaned_books_.push_back(book);
      }
      return loaned;
   };
    
    
    /* ReturnBook:
    * returns a book from the customer
    * takes a reference to a book as a parameter and returns nothing.
    */
   void Customer::ReturnBook(Book& book){
     unsigned int i = 0;
     while (i < loaned_books_.size()){
         if (loaned_books_[i].GetName() == book.GetName()) {
             loaned_books_.erase(loaned_books_.begin() + i);
             book.Restore();
             return;
         }
         i++;
     }
   };
    
    
    /* Print:
    * prints the customer's information to the standard output stream.
    * The function takes no parameters and returns nothing. 
    * The output format should be like the following (for 2 loans):
  Customer: <name>, <customer_id>, has <number_of_loans> books on loan:\n
- Book: <name>, author: <author>, ISBN: <isbn>, loaned <true/false>, due date: <day>.<month>.<year>\n
- Book: <name>, author: <author>, ISBN: <isbn>, loaned <true/false>, due date: <day>.<month>.<year>\n
    * This function should not alter the Customer object's state, in other words the function should be const.
    */
    void Customer::Print() const {
       std::cout << "Customer: "<< name_ <<", "<< id_ <<", has "<< GetLoanAmount() <<" books on loan:"<< std::endl;
       for (auto book : loaned_books_){
          std::cout << "- ";
          book.Print();
       }
    }
