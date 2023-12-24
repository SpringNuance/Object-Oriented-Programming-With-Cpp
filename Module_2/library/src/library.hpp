#ifndef ELEC_AS_CPP_LIBRARY
#define ELEC_AS_CPP_LIBRARY

#include <string>
#include <vector>
#include "book.hpp"
#include "customer.hpp"

class Library {
public:
    /* Library:
    * the constructor of the Library class, takes following parameters:
    *  - the library's name (const reference to string)
    */
    Library(const std::string& name);
    Library(const std::string& name, std::vector<Book>& books, std::vector<Customer>& customers);
    /* GetName:
    * returns the library's name as a string, takes no parameters.
    * This function should not alter the Library object's state, in other words the function should be const.
    */
    std::string GetName() const;


    /* GetBooks:
    * returns the Library's books as a reference to a vector<Book>, takes no parameters.
    */
    std::vector<Book>& GetBooks() ;

    /* GetCustomers:
    * returns the Library's customers as a reference to a vector<Customer>, takes no parameters.
    */
    std::vector<Customer>& GetCustomers();

    /* FindBookByName:
    * returns a Book, takes a const reference to a string as a parameter,
    * if a Book is not found, a new book with an empty strings as parameters 
    * for the name, author and isbn is returned.
    */
    Book FindBookByName(const std::string& name);

    /* FindBooksByAuthor:
    * returns a vector of Books, takes a const reference to a string as a parameter,
    * if no books are found, an empty vector is returned.
    */
    std::vector<Book> FindBooksByAuthor(const std::string& name);

    /* FindAllLoanedBooks():
    * returns a vector of Books, takes no parameters,
    * if no books are found, an empty vector is returned.
    */
    std::vector<Book> FindAllLoanedBooks();

    /* FindCustomer:
    * returns a Customer, takes a const reference to a string representing the Customer's id as a parameter,
    * if a Customer is not found, a new Customer with empty strings are parameters 
    * for name and id is returned.
    */
    Customer FindCustomer(const std::string& id);
    

private:
    /* Make variables for:
    * name (string)
    * books (vector<Book>)
    * customers (vector<Customer>)
    */
   std::string name_;
   std::vector<Book> books_;
   std::vector<Customer> customers_;
    
};

#endif
