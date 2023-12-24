#include "library.hpp"
#include "customer.hpp"
#include "book.hpp"

#include <iostream>
#include <string>



  /* Library:
    * the constructor of the Library class, takes following parameters:
    *  - the library's name (const reference to string)
    */
    Library::Library(const std::string& name){
        name_ = name;
    };

    Library::Library(const std::string& name, std::vector<Book>& books, std::vector<Customer>& customers){
        name_ = name;
        books_ = books;
        customers_ = customers;
    };

    /* GetName:
    * returns the library's name as a string, takes no parameters.
    * This function should not alter the Library object's state, in other words the function should be const.
    */
    std::string Library::GetName() const{
        return name_;
    };


    /* GetBooks:
    * returns the Library's books as a reference to a vector<Book>, takes no parameters.
    */
    std::vector<Book>& Library::GetBooks() {
        return books_;
    };

    /* GetCustomers:
    * returns the Library's customers as a reference to a vector<Customer>, takes no parameters.
    */
    std::vector<Customer>& Library::GetCustomers() {
        return customers_;
    };

    /* FindBookByName:
    * returns a Book, takes a const reference to a string as a parameter,
    * if a Book is not found, a new book with an empty strings as parameters 
    * for the name, author and isbn is returned.
    */
    Book Library::FindBookByName(const std::string& name){
       for (auto book: books_){
           if (book.GetName() == name){
               return book;
           }
       }
       return Book("","","");
    };

    /* FindBooksByAuthor:
    * returns a vector of Books, takes a const reference to a string as a parameter,
    * if no books are found, an empty vector is returned.
    */
    std::vector<Book> Library::FindBooksByAuthor(const std::string& name){
        std::vector<Book> authorBooks;
        for (auto book : books_){
            if (book.GetAuthor() == name){
                authorBooks.push_back(book);
            }
        }
        return authorBooks;
    };

    /* FindAllLoanedBooks():
    * returns a vector of Books, takes no parameters,
    * if no books are found, an empty vector is returned.
    */
    std::vector<Book> Library::FindAllLoanedBooks(){
        std::vector<Book> loanedBooks;
        for (auto book : books_){
            if (book.GetStatus()){
                loanedBooks.push_back(book);
            }
        }
        return loanedBooks;
    };

    /* FindCustomer:
    * returns a Customer, takes a const reference to a string representing the Customer's id as a parameter,
    * if a Customer is not found, a new Customer with empty strings are parameters 
    * for name and id is returned.
    */
    Customer Library::FindCustomer(const std::string& id){
        for (auto customer: customers_){
           if (customer.GetID() == id){
               return customer;
           }
       }
       return Customer("","");
    };



