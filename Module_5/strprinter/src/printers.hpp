#include <iostream>
#include "string_printer.hpp"
#include <vector>
#include <exception>
#include <map>

/* Add include guards here */

/* TODO: class Printers
 * ------------
 * Description:
 * A storage for StringPrinter pointers associated with a name. The class has 
 * ownership of the objects.
 * ------------
 * Functions:

 * ------------
 * Members:
 * Whatever you deem necessary.
 * ------------
 * Other:
 * Copying means copying the contained StringPrinters as well.
 * Remember to also implement the destructor.
 */

class Printers {
    public:
    // A default constructor that initializes the object with zero printers.
    Printers(){};
    ~Printers(){
        for(auto itr = printers.begin(); itr != printers.end(); itr++){
            delete itr->second;
        }
    }
    
    // A copy constructor that copies the object.
    Printers(Printers &oldPrinters){
       for (auto it: oldPrinters.printers){
          printers[it.first] = it.second->Clone();
       }
    }
    
    // Copy assignment operator: copies the object given to self.
    Printers& operator=(Printers &oldPrinters){
        for (auto it: oldPrinters.printers){
          printers[it.first] = it.second->Clone();
       }
        return *this;
    } 
/*
 * Add: A function that adds a new StringPrinter object to the collection
 * and associates it with a name.
 * Takes two parameters:
 *  - a string that contains the name
 *  - the StringPrinter pointer to be added
 * Throws:
 *  - std::invalid_argument if an association for the name already exists ("Duplicate index").
 *  - std::invalid_argument if the pointer is null ("Invalid printer").
 * Note: The Printers object takes ownership of the pointer and is
 *  therefore responsible for eventually calling delete on the pointer.
*/
void Add(std::string name, StringPrinter* printer){
    if (printer == nullptr){
        throw std::invalid_argument("Invalid printer");
    } else if (printers.find(name) != printers.end()){
        throw std::invalid_argument("Duplicate index");
    } else {
        printers[name] = printer;
    }
}

/*
 * Indexing operator: The collection is indexed using the
 * name (string) and returns a reference to the associated StringPrinter.
 * Throws:
 *  - std::invalid_argument if an association does not exist ("Unknown index").
 * */
StringPrinter& operator[](std::string name){
    if (printers.find(name) == printers.end()){
        throw std::invalid_argument("Unknown index");
    } else return *(printers[name]);
}
    
    private:
      std::map<std::string, StringPrinter*> printers;
};